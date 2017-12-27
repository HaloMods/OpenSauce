/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
// NOTE: NON-STANDARD ENGINE SOURCE FILE
#include "Common/Precompile.hpp"
#include <blamlib/tag_files/tag_group_verification.hpp>

#if PLATFORM_IS_EDITOR
#include <blamlib/cseries/cseries_base.hpp>
#include <blamlib/cseries/enum_templates.h>
#include <blamlib/tag_files/tag_block_definition.h>
#include <blamlib/tag_files/tag_data_definition.h>
#include <blamlib/tag_files/tag_field.h>
#include <blamlib/tag_files/tag_group.h>
#include <blamlib/tag_files/tag_groups_base.hpp>
#include <blamlib/tag_files/tag_reference_definition.h>
#include <yelolib/cseries/cseries_yelo_base.hpp>
#include <yelolib/tag_files/string_id_yelo.hpp>

namespace Yelo
{
	namespace TagGroups
	{
		// called in the 'verify group fields' initialize step on tag_reference_definitions
		static void TagGroupMarkAsReferenced(tag group_tag)
		{
			blam::tag_group_get(group_tag)->flags.set(e_tag_group_flags::referenced_yelo_bit, true);
		}

		void CheckForUnreferencedGroups()
		{
#if FALSE
			struct mark_parent_group_children_as_referenced_action
			{ void operator()(tag_group* group) const
			{
				// also mark the parents as referenced
				if(group->child_count > 0)
					TagGroupMarkAsReferenced(group->group_tag);

				for(int x = 0; x < group->child_count; x++)
				{
					TagGroupMarkAsReferenced(group->child_group_tags[x]);
				}
			} };

			struct dump_non_referenced_tag_groups_action
			{ void operator()(tag_group* group) const
			{
				if( !TEST_FLAG(group->flags, Flags::_tag_group_referenced_yelo_bit) )
				{
					YELO_WARN("unreferenced tag group: %s", group->name);
				}
			} };

			// special cases
			TagGroupMarkAsReferenced('vcky'); // virtual_keyboard
			TagGroupMarkAsReferenced('Soul'); // ui_widget_collection
			TagGroupMarkAsReferenced('mode'); // non-pc 'model' tag
			TagGroupMarkAsReferenced('tagc'); // tag_collection
			TagGroupMarkAsReferenced('devc'); // input_device_defaults

			TagGroups::tag_groups_do_action<mark_parent_group_children_as_referenced_action>();
			TagGroups::tag_groups_do_action<dump_non_referenced_tag_groups_action>();
#endif
		}

		//////////////////////////////////////////////////////////////////////////
		// Everything below this comment is based on engine code
		// I've left it out of the 'blam' namespace due to the amount of structural changes made
		// and due to the fact that we call them from elsewhere besides the tag_groups_system code

		static void VerifyStringListDefinition(const string_list* definition,
			const tag_block_definition* block_definition, cstring field_type_name)
		{
			YELO_ASSERT_DISPLAY(definition, "no definition specified for %s field in block %s.",
				field_type_name, block_definition->name); // NOTE: added owner block name to info
			YELO_ASSERT( definition->count>=0 );

			for(int x = 0; x < definition->count; x++)
			{
				YELO_ASSERT_DISPLAY(definition->strings[x] != nullptr, "%s field in block %s doesn't have enough strings",
					field_type_name, block_definition->name);
			}
		}
		template<typename TEnum>
		static void VerifyEnumFieldDefinition(const tag_field& field,
			const tag_block_definition* block_definition)
		{
			auto* definition = field.get_definition<string_list>();
			VerifyStringListDefinition(definition, block_definition, "enum");
		}
		template<typename TFlags>
		static void VerifyFlagsFieldDefinition(const tag_field& field,
			const tag_block_definition* block_definition)
		{
			auto* definition = field.get_definition<string_list>();
			VerifyStringListDefinition(definition, block_definition, "flags");

			YELO_ASSERT_DISPLAY(definition->count<=BIT_COUNT(TFlags), "invalid string list specified for '%s' in block %s.",
				field.name, block_definition->name); // NOTE: added owner block name to info
		}

		static void VerifyTagReferenceFieldDefinition(const tag_field& field,
			const tag_block_definition* block_definition)
		{
			auto* definition = field.get_definition<tag_reference_definition>();
			YELO_ASSERT_DISPLAY(definition, "no definition specified for tag reference field in block %s.",
				block_definition->name); // NOTE: added owner block name to info
			YELO_ASSERT(definition->flags.is_valid());

			group_tag_to_string gt_string; gt_string.Terminate();

			if(definition->group_tag != NONE)
			{
				gt_string.group = definition->group_tag;
				YELO_ASSERT_DISPLAY( blam::tag_group_get(definition->group_tag), 
					"invalid group tag '%s' for tag reference field '%s' in block %s",
					gt_string.TagSwap().str, field.name, block_definition->name);
				YELO_ASSERT( definition->group_tags==nullptr );

				TagGroupMarkAsReferenced(definition->group_tag);
			}
			else if(definition->group_tags != nullptr)
			{
				for(auto group_tag : *definition)
				{
					gt_string.group = group_tag;
					YELO_ASSERT_DISPLAY( blam::tag_group_get(group_tag),
						"invalid group tag '%s' for variable tag reference field '%s' in block %s",
						gt_string.TagSwap().str, field.name, block_definition->name);

					TagGroupMarkAsReferenced(group_tag);
				}
			}
		}

		static void VerifyDataFieldDefinition(const tag_field& field,
			const tag_block_definition* block_definition)
		{
			auto* definition = field.get_definition<tag_data_definition>();
			YELO_ASSERT_DISPLAY(definition, "no definition specified for tag_data field in block %s.",
				block_definition->name); // NOTE: added owner block name to info
			YELO_ASSERT( definition->name );
			YELO_ASSERT( definition->flags.is_valid());
			YELO_ASSERT( definition->maximum_size>0 );
		}

		void VerifyTagField(const tag_block_definition* block_definition, const tag_field& field)
		{
			switch(field.type)
			{
			case e_field_type::string:
				{
					uintptr_t definition = CAST_PTR(uintptr_t, field.definition);

					YELO_ASSERT( definition==0 || definition <= Enums::k_long_string_length || 
						TagFieldIsOldStringId(&field) );
				}
				break;

			case e_field_type::word_enum:
				VerifyEnumFieldDefinition<int16>(field, block_definition);
				break;

			case e_field_type::long_flags:	VerifyFlagsFieldDefinition<long_flags>(field, block_definition); break;
			case e_field_type::word_flags:	VerifyFlagsFieldDefinition<word_flags>(field, block_definition); break;
			case e_field_type::byte_flags:	VerifyFlagsFieldDefinition<byte_flags>(field, block_definition); break;

			case e_field_type::tag_reference:
				VerifyTagReferenceFieldDefinition(field, block_definition);
				break;

			case e_field_type::block:
				{
					auto* definition = field.get_definition<tag_block_definition>();
					YELO_ASSERT_DISPLAY(definition, "no definition specified for block field in block %s.",
						block_definition->name); // NOTE: added owner block name to info

					VerifyBlockFieldDefinitions(definition);
				}
				break;

			case e_field_type::data:
				VerifyDataFieldDefinition(field, block_definition);
				break;

			case e_field_type::short_block_index:
			case e_field_type::long_block_index:
				{
					auto* definition = field.get_definition<tag_block_definition>();
					YELO_ASSERT_DISPLAY(definition, "no definition specified for block index field in block %s.",
						block_definition->name); // NOTE: added owner block name to info
				}
				break;

			case e_field_type::array_start:
			case e_field_type::pad:
			case e_field_type::skip:
				YELO_ASSERT( CAST_PTR(int32,field.definition)>0 );
				break;

			case e_field_type::explanation:
				{
					cstring definition = field.get_definition<const char>();
					YELO_ASSERT_DISPLAY(definition, "no definition specified for explanation field in block %s.",
						block_definition->name); // NOTE: added owner block name to info
				}
				break;
			}
		}

		void VerifyBlockFieldDefinitions(tag_block_definition* block)
		{
			YELO_ASSERT( block );
			YELO_ASSERT( block->name );
			YELO_ASSERT( block->flags.is_valid() );
			YELO_ASSERT( block->maximum_element_count>=0 );
			YELO_ASSERT( CAST(int,block->element_size)>=0 );
			YELO_ASSERT( block->fields );

			struct verify_tag_field_action
			{ void operator()(const tag_block_definition* block, const tag_field& field) const
			{
				VerifyTagField(block, field);
			} };

			block->fields_do_action<verify_tag_field_action, true>();
		}


		void VerifyTagGroupTags()
		{
			struct verify_no_duplicate_group_tags_action
			{
				group_tag_to_string m_group_string;

				verify_no_duplicate_group_tags_action()
				{
					m_group_string.Terminate();
				}

				void operator()(tag_group* group)
				{
					m_group_string.group = group->group_tag;
					m_group_string.TagSwap();
					YELO_ASSERT_DISPLAY(group==blam::tag_group_get(group->group_tag), "there are two groups using the tag '%s'.",
						m_group_string.str);
				}
			};

			TagGroups::tag_groups_do_action<verify_no_duplicate_group_tags_action>();
		}

		void VerifyGroupFieldDefinitions()
		{
			struct verify_group_field_definitions_action
			{
				bool m_found_group_missing_header_definition;

				verify_group_field_definitions_action() : m_found_group_missing_header_definition(false) { }

				void operator()(const tag_group* group)
				{
					if(group->header_block_definition != nullptr)
						VerifyBlockFieldDefinitions(group->header_block_definition);
					else
					{	// NOTE: added this warning
						YELO_WARN("tag group '%s' doesn't have a definition", group->name);
						m_found_group_missing_header_definition = true;
					}
				}
			};

			auto action = verify_group_field_definitions_action();
			TagGroups::tag_groups_do_action(action);

			if(action.m_found_group_missing_header_definition)
			{
				YELO_ASSERT( !"fix your goddamn tag groups" );
			}
		}

		void VerifyTagGroupsFinalChecks()
		{
		}
	};
};

#endif