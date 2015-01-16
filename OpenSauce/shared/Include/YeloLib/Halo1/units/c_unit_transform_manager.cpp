/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#include "Common/Precompile.hpp"
#include <YeloLib/Halo1/units/c_unit_transform_manager.hpp>

#include <blamlib/Halo1/tag_files/tag_groups.hpp>
#include <blamlib/Halo1/objects/objects.hpp>
#include <blamlib/Halo1/objects/damage.hpp>
#include <blamlib/Halo1/units/unit_structures.hpp>
#include <blamlib/Halo1/units/units.hpp>
#include <blamlib/Halo1/ai/ai_script.hpp>
#include <blamlib/Halo1/ai/actors.hpp>
#include <blamlib/Halo1/effects/damage_effect_definitions.hpp>
#include <blamlib/Halo1/hs/hs_library_external.hpp>
#include <blamlib/Halo1/models/model_animation_definitions.hpp>
#include <blamlib/Halo1/ai/actor_structures.hpp>
#include <blamlib/Halo1/ai/actor_definitions.hpp>

#include <YeloLib/Halo1/units/unit_transform_definition.hpp>
#include <YeloLib/Halo1/objects/objects_yelo.hpp>

namespace Yelo
{
	namespace Objects { namespace Units { namespace Transform
	{
		c_unit_transform_manager::c_unit_transform_manager()
			: m_transforms_allowed(true)
			, m_unit_transform_map()
			, m_transforms_in_progress()
		{ }

		const TagGroups::s_unit_transform_definition* c_unit_transform_manager::FindUnitTransform(const datum_index unit_tag_index
			, const datum_index instigator_tag_index
			, const bool damage_is_melee)
		{
			// Search for a matching unit tag index
			auto transform_set_iter = m_unit_transform_map.find(unit_tag_index.index);
			if(transform_set_iter == m_unit_transform_map.end())
			{
				return nullptr;
			}

			auto& transform_set = transform_set_iter->second;
			auto& transform_list = transform_set.m_transforms;

			auto found_transform = std::find_if(transform_list.begin(), transform_list.end(),
				[&](const TagGroups::s_unit_transform_definition* entry)
				{
					for(auto& instigator : entry->instigators)
					{
						// Skip if the damage type does not match
						if(((instigator.damage_type == Enums::_unit_transform_damage_type_weapon_only) && damage_is_melee)
							|| ((instigator.damage_type == Enums::_unit_transform_damage_type_melee_only) && !damage_is_melee))
						{
							return false;
						}

						if(instigator.unit.tag_index == instigator_tag_index)
						{
							return true;
						}
					}

					return false;
				}
			);

			// If a matching transform was found, return it, otherwise return the default transform
			if(found_transform != transform_list.end())
			{
				return *found_transform;
			}
			else
			{
				return transform_set.m_default_transform;
			}
		}

		const TagGroups::s_unit_transform_target& c_unit_transform_manager::GetTransformTarget(const TagGroups::s_unit_transform_definition& transform_definition)
		{
			// Choose a random transform target
			int target_index = rand() % transform_definition.targets.Count;

			return transform_definition.targets[target_index];
		}

#pragma region Attachments
		void c_unit_transform_manager::TransformAttachObject(const datum_index unit_index
			, const s_unit_datum* unit_datum
			, const datum_index object_type
			, const tag_string& object_marker_name
			, const tag_string& destination_marker_name
			, const int32 destination_marker_index)
		{
			// Set up the placement data to match the target object's
			s_object_placement_data attachment_placement_data;
			blam::object_placement_data_new(attachment_placement_data, object_type);

			attachment_placement_data.position = unit_datum->object.position;

			// Create the object
			datum_index attachment_object;
			attachment_object = blam::object_new(attachment_placement_data);

			// If there is only 1 marker do not append a marker index to the name
			cstring destination_marker = destination_marker_name;
			if(destination_marker_index != NONE)
			{
				tag_string destination_marker_buffer;
				sprintf_s(destination_marker_buffer, "%s%d", destination_marker_name, destination_marker_index);

				destination_marker = destination_marker_buffer;
			}

			// Attach the object
			blam::object_attach_to_marker(unit_index, destination_marker_name, attachment_object, object_marker_name);
		}

		void c_unit_transform_manager::TransformAttachObjects(const datum_index unit_index
			, const s_unit_datum* unit_datum
			, const TagGroups::s_unit_transform_definition& transform_definition)
		{
			for(auto& attachment : transform_definition.attachments)
			{
				if(attachment.destination_marker_count == 1)
				{
					TransformAttachObject(unit_index
						, unit_datum
						, attachment.object_type.tag_index
						, attachment.object_marker
						, attachment.destination_marker
						, NONE);
				}
				else
				{
					for(int32 marker_index = 0; marker_index < attachment.destination_marker_count; marker_index++)
					{
						TransformAttachObject(unit_index
							, unit_datum
							, attachment.object_type.tag_index
							, attachment.object_marker
							, attachment.destination_marker
							, marker_index);
					}
				}
			}
		}
#pragma endregion

#pragma region Transform Sequence
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Sets up the unit's actor. </summary>
		///
		/// <param name="actor_variant_tag_index">	Datum index of the actor variant tag. </param>
		/// <param name="unit_index">			  	Datum index of the unit. </param>
		/// <param name="source_actor_index">	  	Datum index of the source actor. </param>
		/// <param name="inherit_encounter_squad">
		/// 	Flag for whether to inherit the source actor's encounter and squad.
		/// </param>
		static void SetupUnitActor(const datum_index unit_index
			, const datum_index actor_variant_tag_index
			, const Enums::actor_default_state default_state
			, const datum_index source_actor_index
			, const bool inherit_encounter_squad)
		{
			// Set up the unit's inventory
			blam::actor_customize_unit(actor_variant_tag_index, unit_index);

			// Inherit the encounter and squad if desired
			datum_index encounter_index = datum_index::null;
			int32 squad_index = NONE;

			if(inherit_encounter_squad)
			{
				const auto actor_data = AI::Actors()[source_actor_index];

				encounter_index = actor_data->meta.encounter_index;
				squad_index = actor_data->meta.squad_index;
			}

			blam::actor_create_for_unit(false
				, unit_index
				, actor_variant_tag_index
				, encounter_index
				, squad_index
				, 0
				, NONE
				, false
				, default_state
				, default_state
				, NONE
				, 0);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Creates a new unit reusing the old unit. </summary>
		///
		/// <param name="unit_index">	  	Datum index of the old unit. </param>
		/// <param name="unit_datum">	  	[in] If non-null, the old unit's datum. </param>
		/// <param name="resulting_team"> 	The resulting team. </param>
		/// <param name="instigator_team">	The instigator team. </param>
		///
		/// <returns>	The new unit index. </returns>
		static datum_index CreateUnitReuse(const datum_index unit_index
			, s_unit_datum* unit_datum
			, const Enums::unit_transform_resulting_team resulting_team
			, const Enums::game_team instigator_team)
		{
			SET_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit, false);

			switch(resulting_team)
			{
			case Enums::_unit_transform_resulting_team_inherit_from_attacked:
				break;
			case Enums::_unit_transform_resulting_team_inherit_from_attacker:
				unit_datum->object.owner_team = instigator_team;
				break;
			default:
				unit_datum->object.owner_team = (Enums::game_team)resulting_team;
			}

			DeleteChildrenByType(unit_index, Enums::_object_type_mask_unit);

			return unit_index;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Creates a new unit. </summary>
		///
		/// <param name="unit_index">	  	Datum index of the old unit. </param>
		/// <param name="unit_datum">	  	[in] If non-null, the old unit's datum. </param>
		/// <param name="new_unit_type">  	Type of the new unit. </param>
		/// <param name="resulting_team"> 	The resulting team. </param>
		/// <param name="instigator_team">	The instigator team. </param>
		///
		/// <returns>	The new unit index. </returns>
		static datum_index CreateUnitNew(const datum_index unit_index
			, s_unit_datum* unit_datum
			, const datum_index new_unit_type
			, const Enums::unit_transform_resulting_team resulting_team
			, const Enums::game_team instigator_team)
		{
			// Create the new unit based on the target_unit's data
			s_object_placement_data unit_placement_data;
			PlacementDataNewAndCopy(unit_placement_data, unit_index, new_unit_type);

			// Set the to-be-created unit's team
			switch(resulting_team)
			{
			case Enums::_unit_transform_resulting_team_inherit_from_attacked:
				unit_placement_data.owner_team = unit_datum->object.owner_team;
				break;
			case Enums::_unit_transform_resulting_team_inherit_from_attacker:
				unit_placement_data.owner_team = instigator_team;
				break;
			default:
				unit_placement_data.owner_team = (Enums::game_team)resulting_team;
			}

			return blam::object_new(unit_placement_data);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Overrides a units health and shield values. </summary>
		///
		/// <param name="option">	 	The override operation. </param>
		/// <param name="unit_datum">	[in] If non-null, the old unit's datum. </param>
		/// <param name="health">	 	The health value. </param>
		/// <param name="shield">	 	The shield value. </param>
		static void OverrideDamage(const Enums::unit_transform_vitality_handling operation
			, s_unit_datum* unit_datum
			, const real health
			, const real shield)
		{
			switch(operation)
			{
			case Enums::_unit_transform_vitality_handling_both:
				unit_datum->object.damage.health = health;
				unit_datum->object.damage.shield = shield;
				break;
			case Enums::_unit_transform_vitality_handling_shield_only:
				unit_datum->object.damage.shield = shield;
				break;
			case Enums::_unit_transform_vitality_handling_health_only:
				unit_datum->object.damage.health = health;
				break;
			}
		}

		void c_unit_transform_manager::TransformOut(const datum_index unit_index
			, s_unit_datum* unit_datum
			, const TagGroups::s_unit_transform_definition& transform_definition)
		{
			// Freeze the actor
			blam::actor_braindead(unit_datum->unit.actor_index, true);

			// Play the transform-out animation
			blam::unit_start_user_animation(unit_index
				, unit_datum->object.animation.definition_index
				, transform_definition.transform_out_anim
				, false);

			// Attach the transform objects
			TransformAttachObjects(unit_index, unit_datum, transform_definition);

			if(TEST_FLAG(transform_definition.flags, Flags::_unit_transform_flags_invicible_during_transform_out_bit))
			{
				SET_FLAG(unit_datum->object.damage.flags, Flags::_object_cannot_take_damage_bit, true);
			}

			SET_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit, true);
		}

		void c_unit_transform_manager::TransformIn(const datum_index unit_index
			, s_unit_datum* unit_datum
			, const s_unit_transform_state& transform_state)
		{
			auto& transform_target = GetTransformTarget(*transform_state.m_unit_transform);
			auto* actor_variant_definition = blam::tag_get<TagGroups::s_actor_variant_definition>(transform_target.actor_variant.tag_index);

			// Spawn the transition effect
			blam::hs_effect_new_from_object_marker(transform_target.transform_effect.tag_index, unit_index);
			
			// Drop weapon if needed
			if(TEST_FLAG(transform_target.flags, Flags::_unit_transform_target_flags_drop_weapon))
			{
				blam::unit_drop_current_weapon(unit_index, true);
			}

			// Create the new unit
			bool delete_unit = false;
			auto new_unit_index = datum_index::null;
			if(TEST_FLAG(transform_target.flags, Flags::_unit_transform_target_flags_try_to_use_existing_unit)
				&& (unit_datum->object.definition_index == actor_variant_definition->unit.tag_index))
			{
				new_unit_index = CreateUnitReuse(unit_index
					, unit_datum
					, transform_target.resulting_team
					, transform_state.m_instigator_team);
			}
			else
			{
				new_unit_index = CreateUnitNew(unit_index
					, unit_datum
					, actor_variant_definition->unit.tag_index
					, transform_target.resulting_team
					, transform_state.m_instigator_team);

				delete_unit = true;
			}
			auto* new_unit_datum = blam::object_get_and_verify_type<s_unit_datum>(new_unit_index);

			// Handle seated units
			// TODO: Add ejection and inheritance
			for(datum_index current_child = unit_datum->object.first_object_index;
				!current_child.IsNull();
				current_child = blam::object_get(current_child)->next_object_index)
			{
				auto child_object = blam::object_try_and_get_and_verify_type<s_unit_datum>(current_child);
				if(!child_object || (child_object->unit.vehicle_seat_index == NONE))
				{
					continue;
				}

				blam::unit_kill(current_child);
			}

			real old_unit_health = unit_datum->object.damage.health;
			real old_unit_shield = unit_datum->object.damage.shield;

			// Set up the unit's actor
			SetupUnitActor(new_unit_index
				, transform_target.actor_variant.tag_index
				, transform_target.actor_state
				, unit_datum->unit.actor_index
				, TEST_FLAG(transform_target.flags, Flags::_unit_transform_target_flags_inherit_encounter_squad));

			blam::actor_braindead(new_unit_datum->unit.actor_index, true);

			// Inherit unit vitality
			OverrideDamage(transform_target.vitality_inheritance
				, new_unit_datum
				, old_unit_health
				, old_unit_shield);

			// Override unit vitality
			OverrideDamage(transform_target.vitality_override
				, new_unit_datum
				, transform_target.health_override
				, transform_target.shield_override);

			SET_FLAG(new_unit_datum->object.damage.flags, Flags::_object_shield_depleted_bit, new_unit_datum->object.damage.shield <= 0.0f);

			// Delete the existing unit if necessary
			if(delete_unit)
			{
				Objects::DetachChildActors(unit_index);

				blam::actor_delete(unit_datum->unit.actor_index);
				blam::object_delete(unit_index);
			}

			// Play the transform-in animation
			blam::unit_start_user_animation(new_unit_index
				, new_unit_datum->object.animation.definition_index
				, transform_target.transform_in_anim
				, false);

			SET_FLAG(new_unit_datum->object.damage.flags, Flags::_object_cannot_take_damage_bit, true);
			SET_FLAG(new_unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit, true);
		}

		void c_unit_transform_manager::TransformEnd(s_unit_datum* unit_datum)
		{
			blam::actor_braindead(unit_datum->unit.actor_index, false);

			SET_FLAG(unit_datum->object.damage.flags, Flags::_object_cannot_take_damage_bit, false);
			SET_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit, false);
		}
#pragma endregion

		bool c_unit_transform_manager::GetTransformsAllowed()
		{
			return m_transforms_allowed;
		}

		void c_unit_transform_manager::SetTransformsAllowed(const bool value)
		{
			m_transforms_allowed = value;
		}

		void c_unit_transform_manager::LoadTransformDefinitions()
		{
			// Look for all unit transform tags in the cache
			TagGroups::s_tag_iterator iter;
			blam::tag_iterator_new(iter, TagGroups::s_unit_transform_definition::k_group_tag);

			datum_index tag_index = datum_index::null;
			while(!(tag_index = blam::tag_iterator_next(iter)).IsNull())
			{
				// Add the unit transform definition
				auto* unit_transform = blam::tag_get<TagGroups::s_unit_transform_definition>(tag_index);

				for(auto& variant : unit_transform->actor_variants)
				{
					auto actv_tag_index = variant.tag_index;

					// Add a new transform set entry if one does not exist
					auto transform_list_iter = m_unit_transform_map.find(actv_tag_index.index);
					if(transform_list_iter == m_unit_transform_map.end())
					{
						m_unit_transform_map[actv_tag_index.index] = s_unit_transform_set();
					}

					auto& transform_set = m_unit_transform_map[actv_tag_index.index];

					// If the transform is the default, add it as the default, otherwise add it as a normal option
					if(TEST_FLAG(unit_transform->flags, Flags::_unit_transform_flags_default_transform_bit))
					{
						transform_set.m_default_transform = unit_transform;
					}
					else
					{
						transform_set.m_transforms.push_back(unit_transform);
					}
				}
			}
		}

		void c_unit_transform_manager::UnloadTransformDefinitions()
		{
			m_unit_transform_map.clear();
			m_transforms_in_progress.clear();
		}

		void c_unit_transform_manager::UnitDamaged(const datum_index unit_index, const Objects::s_damage_data* damage_data)
		{
			if(!m_transforms_allowed || damage_data->responsible_unit_index.IsNull())
			{
				return;
			}

			// Get the unit datums and definitions
			auto* unit_datum = blam::object_try_and_get_and_verify_type<s_unit_datum>(unit_index);
			if(!unit_datum)
			{
				return;
			}

			// Transforms only apply to actors
			if(unit_datum->unit.actor_index.IsNull())
			{
				return;
			}

			// If the unit is dead or already transforming, return
			if(TEST_FLAG(unit_datum->object.damage.flags, Flags::_object_killed_bit)
				|| TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit)
				|| TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit))
			{
				return;
			}

			auto* responsible_unit_datum = blam::object_try_and_get_and_verify_type<s_unit_datum>(damage_data->responsible_unit_index);
			if(!responsible_unit_datum)
			{
				return;
			}

			auto* actor_datum = AI::Actors()[unit_datum->unit.actor_index];
			if(!actor_datum)
			{
				return;
			}

			// If no matching transform is found, return
			bool is_melee = (unit_datum->unit.damage_result.category == Enums::_damage_category_melee);

			auto* unit_transform = FindUnitTransform(actor_datum->meta.actor_variant_definition_index
				, responsible_unit_datum->object.definition_index
				, is_melee);
			if(!unit_transform)
			{
				return;
			}

			// If we should ignore friendly fire, do so
			if(TEST_FLAG(unit_transform->flags, Flags::_unit_transform_flags_ignore_friendly_fire_bit)
				&& !blam::game_team_is_enemy(unit_datum->object.owner_team, responsible_unit_datum->object.owner_team))
			{
				return;
			}

			// Test whether the unit should transform based on it's damage
			bool health_below_threshold = unit_datum->object.damage.health <= unit_transform->health_threshold;
			bool shield_below_threshold = unit_datum->object.damage.shield <= unit_transform->shield_threshold;

			bool transform = false;
			switch(unit_transform->threshold_type)
			{
			case Enums::_unit_transform_threshold_type_both:
				transform = health_below_threshold && shield_below_threshold;
				break;
			case Enums::_unit_transform_threshold_type_shield_amount_only:
				transform = shield_below_threshold;
				break;
			case Enums::_unit_transform_threshold_type_health_amount_only:
				transform = health_below_threshold;
				break;
			};

			// If the unit should transform, start the transform out stage
			if(transform)
			{
				TransformOut(unit_index, unit_datum, *unit_transform);

				m_transforms_in_progress[unit_index.index] = s_unit_transform_state
				{
					unit_transform,
					responsible_unit_datum->object.owner_team
				};
			}
		}

		void c_unit_transform_manager::UnitUpdate(const datum_index unit_index)
		{
			auto* unit_datum = blam::object_try_and_get_and_verify_type<s_unit_datum>(unit_index);
			if(!unit_datum)
			{
				return;
			}

			// If the unit was transforming but is now dead or had it's actor removed, stop the transform
			if(TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit)
				|| TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit))
			{
				if(TEST_FLAG(unit_datum->object.damage.flags, Flags::_object_killed_bit) || unit_datum->unit.actor_index.IsNull())
				{
					SET_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit, false);
					SET_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit, false);

					m_transforms_in_progress.erase(unit_index.index);
					return;
				}
			}

			// If the unit has started a transformation, wait until the animation is done playing
			if(TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_out_bit))
			{
				// If the transform out animation has finished playing start the transform in stage
				auto frames_left = blam::unit_get_custom_animation_time(unit_index);
				if(frames_left == 0 || (unit_datum->unit.animation.state != Enums::_unit_animation_state_custom_animation))
				{
					TransformIn(unit_index, unit_datum, m_transforms_in_progress[unit_index.index]);
					m_transforms_in_progress.erase(unit_index.index);
				}
			}
			else if(TEST_FLAG(unit_datum->object.flags, Flags::_object_yelo_is_transforming_in_bit))
			{
				// If the transform in animation has finished playing end the transformation
				auto frames_left = blam::unit_get_custom_animation_time(unit_index);
				if(frames_left == 0 || (unit_datum->unit.animation.state != Enums::_unit_animation_state_custom_animation))
				{
					TransformEnd(unit_datum);
				}
			}
		}
	};};}
};