/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/
#include "Common/Precompile.hpp"
#include "Engine/AnimationUpgrade.hpp"

#include "TagGroups/TagGroups.hpp"

#include <blamlib/Halo1/models/model_animations.hpp>
#include <blamlib/Halo1/models/model_animation_definitions.hpp>

namespace Yelo
{
	namespace Animations
	{
		ENGINE_PTR(tag_block_definition, animation_graph_sound_reference_block,		0x9D6BB0, 0x6BA898, 0xA4E388);
		ENGINE_PTR(tag_block_definition, animation_block,							0x9D6DD8, 0x6BAAC0, 0xA4E5B0);
		ENGINE_PTR(tag_block_definition, animation_graph_unit_seat_block,			0x9D7138, 0x6BAE20, 0xA4E910);

		ENGINE_PTR(s_animation_list, weapon_class_animation_list,					0x9D7998, 0x6BB680, 0xA4F170);
		ENGINE_PTR(s_animation_list, unit_seat_animation_list,						0x9D7AE0, 0x6BB7C8, 0xA4F2B8);

		static s_animation_list_entry g_unit_seat_animation_list_yelo_entries[Enums::k_number_of_unit_seat_animations_yelo];

		void AnimationUpgradesInitialize()
		{
			// Set the animation graph's sound references block's max elements to yelo's
			{
				tag_block_definition* animation_graph_sound_reference_block = GET_PTR2(animation_graph_sound_reference_block);
				assert( animation_graph_sound_reference_block->maximum_element_count==Enums::k_max_sound_references_per_graph );
				animation_graph_sound_reference_block->maximum_element_count = Enums::k_max_sound_references_per_graph_upgrade;
			}

			// Set the animation graph's animations block's max elements to yelo's
			{
				tag_block_definition* animation_block = GET_PTR2(animation_block);
				assert( animation_block->maximum_element_count==Enums::k_max_animations_per_graph );
				animation_block->maximum_element_count = Enums::k_max_animations_per_graph_upgrade;
			}

			// set the unit seat block's max elements to yelo's
			{
				tag_block_definition* animation_graph_unit_seat_block = GET_PTR2(animation_graph_unit_seat_block);
				assert( animation_graph_unit_seat_block->maximum_element_count==Enums::k_max_unit_seat_modes_per_graph );
				animation_graph_unit_seat_block->maximum_element_count = Enums::k_max_unit_seat_modes_per_graph_upgrade;
			}

			//////////////////////////////////////////////////////////////////////////
			// Setup the engine's unit seat s_animation_list with yelo's changes
			s_animation_list* unit_seat_animation_list = GET_PTR2(unit_seat_animation_list);
			assert( unit_seat_animation_list->count==Enums::k_number_of_unit_seat_animations );

			// copy the existing animation entries
			memcpy_s(g_unit_seat_animation_list_yelo_entries, 
				sizeof(s_animation_list_entry) * NUMBEROF(g_unit_seat_animation_list_yelo_entries), 
				unit_seat_animation_list->entries, 
				sizeof(s_animation_list_entry) * unit_seat_animation_list->count
			);
			// set the seat animation list count to yelo's
			unit_seat_animation_list->count = Enums::k_number_of_unit_seat_animations_yelo;
			// set the seat animation list entries to yelo's
			unit_seat_animation_list->entries = g_unit_seat_animation_list_yelo_entries;

			//////////////////////////////////////////////////////////////////////////
			// populate yelo's new unit seat animation definitions
			g_unit_seat_animation_list_yelo_entries[Enums::_unit_seat_animation_yelo_board].name = "board";
			g_unit_seat_animation_list_yelo_entries[Enums::_unit_seat_animation_yelo_board].type = Enums::_model_animation_type_base;
			g_unit_seat_animation_list_yelo_entries[Enums::_unit_seat_animation_yelo_ejection].name = "ejection";
			g_unit_seat_animation_list_yelo_entries[Enums::_unit_seat_animation_yelo_ejection].type = Enums::_model_animation_type_base;


			//////////////////////////////////////////////////////////////////////////
			// Setup the engine's weapon class s_animation_list with yelo's changes
			s_animation_list* weapon_class_animation_list = GET_PTR2(weapon_class_animation_list);
			assert( weapon_class_animation_list->count == Enums::k_number_of_weapon_class_animations );

			//////////////////////////////////////////////////////////////////////////
			// populate yelo's new weapon class animation definitions
			s_animation_list_entry* weapon_class_animation_list_entries = weapon_class_animation_list->entries;
			weapon_class_animation_list_entries[Enums::_weapon_class_animation_yelo_infect].name = "infect";
			weapon_class_animation_list_entries[Enums::_weapon_class_animation_yelo_infect].type = Enums::_model_animation_type_base;
		}
		
		void AnimationUpgradesDispose()
		{
		}
	};
};