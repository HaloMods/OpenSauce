/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blam/objects/object_structures.hpp>
#include <blam/items/item_structures.hpp>

#include <blam/items/equipment_definitions.hpp>

#include <yelo/items/equipment_structures_yelo.hpp>

namespace Yelo
{
	namespace Objects
	{
		struct s_equipment_datum_network_data
		{
			real_point3d position;
			real_vector3d transitional_velocity;
			real_vector3d angular_velocity;
		}; ASSERT_SIZE(s_equipment_datum_network_data, 0x24);

		struct s_equipment_data
		{
			union {												// 0x22C, unknown (and unused?) bytes
				struct s_unknown { PAD128; PAD64; }unknown;

				s_equipment_data_yelo yelo;
			};
			bool baseline_valid;								// 0x244
			sbyte baseline_index;
			sbyte message_index;
			PAD8;
			s_equipment_datum_network_data update_baseline;		// 0x248
			UNKNOWN_TYPE(bool);									// 0x26C probably delta_valid
			PAD24;
			s_equipment_datum_network_data update_delta;		// 0x270
		}; ASSERT_SIZE(s_equipment_data, Enums::k_object_size_equipment - Enums::k_object_size_item);


		struct s_equipment_datum : s_item_datum
		{
			enum { k_object_types_mask = FLAG(Enums::_object_type_equipment) };

			s_equipment_data equipment;
		}; ASSERT_SIZE(s_equipment_datum, Enums::k_object_size_equipment);
	};
};