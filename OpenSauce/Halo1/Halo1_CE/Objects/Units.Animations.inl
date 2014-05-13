/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

#include <blamlib/Halo1/units/unit_structures.hpp>

#include "Memory/MemoryInterface.hpp"

namespace Yelo { namespace Objects { namespace Units {

namespace Animations
{
	namespace
	{
		// An enumeration for each jmp_table we're replacing
		// Shows each jmp_entry and which animation states use it

		enum {
			unit_update_animation_primary_keyframe_jmp_0,		// 30, 31, 41
			unit_update_animation_primary_keyframe_jmp_1,		// 33
			unit_update_animation_primary_keyframe_jmp_default
		};
		
		enum {
			unit_update_animation_final_keyframe_jmp_0,			// 25
			unit_update_animation_final_keyframe_jmp_1,			// 26
			unit_update_animation_final_keyframe_jmp_2,			// 27
			unit_update_animation_final_keyframe_jmp_3,			// 37, 38
			unit_update_animation_final_keyframe_jmp_4,			// 39
			unit_update_animation_final_keyframe_jmp_default
		};
	};

	static void* unit_update_animation_primary_keyframe_jmp_table_yelo[Enums::_unit_animation_state_yelo];
	static void* unit_update_animation_final_keyframe_jmp_table_yelo[Enums::_unit_animation_state_yelo];

	static void unit_update_animation_primary_keyframe_jmp_table_yelo_remapping(_enum state, _enum to)
	{
		unit_update_animation_primary_keyframe_jmp_table_yelo[state] = 
			CAST_PTR(void*, UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_JMP_TABLE[to]);
	}
	// Replaces the UnitUpdateAnimation function's primary keyframe switch tables with our own
	// Called when an animation reaches the primary keyframe index value in the model_animations tag
	static void InitializeUnitUpdateAnimationPrimaryKeyframeJmpTable()
	{
		static const byte opcode_null[] = { 
			Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, 
			Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, 
			Enums::_x86_opcode_nop 
		};
		// TODO: was there a point to this?
//		static const byte jmp_eax[] = { 0xFF, 0x24, 0x85 };

		int32 jmp_default = unit_update_animation_primary_keyframe_jmp_default;
		
		// write the game's default jump case into our jump table
		for(auto& ptr : unit_update_animation_primary_keyframe_jmp_table_yelo)
			ptr = CAST_PTR(void*, UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_JMP_TABLE[jmp_default]);
		
		// remap the existing jump entries into our jump table at the correct indices
		unit_update_animation_primary_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_melee,			unit_update_animation_primary_keyframe_jmp_0);
		unit_update_animation_primary_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_melee_airborne,	unit_update_animation_primary_keyframe_jmp_0);
		unit_update_animation_primary_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_leap_melee,		unit_update_animation_primary_keyframe_jmp_0);
		unit_update_animation_primary_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_throw_grenade,	unit_update_animation_primary_keyframe_jmp_1);

		// set the game's jump table count to ours
		GET_PTR(unit_update_animation_primary_keyframe_jmp_tbl_count) = Enums::_unit_animation_state_yelo - 1;
		// set the game's jump table address to ours
		GET_PTR(unit_update_animation_primary_keyframe_jmp_ptr) = unit_update_animation_primary_keyframe_jmp_table_yelo;		
		// nullify jmp table size adjustment
		Memory::WriteMemory(GET_FUNC_VPTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_JMP_TABLE_ADJUST_SIZE), opcode_null, 3);
		// nullify indirect table references
		Memory::WriteMemory(GET_FUNC_VPTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_INDIRECT_TABLE_PTR), opcode_null);
	}

	static void unit_update_animation_final_keyframe_jmp_table_yelo_remapping(_enum state, _enum to)
	{
		unit_update_animation_final_keyframe_jmp_table_yelo[state] = 
			CAST_PTR(void*, UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE[to]);
	}
	// Replaces the UnitUpdateAnimation function's final keyframe switch tables with our own
	// Called when an animation reaches it's final keyframe
	static void InitializeUnitUpdateAnimationFinalKeyframeJmpTable()
	{
		static const byte opcode_null[] = { 
			Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, 
			Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, Enums::_x86_opcode_nop, 
			Enums::_x86_opcode_nop 
		};
		static const byte jmp_eax[] = { 0xFF, 0x24, 0x85 };

		int32 jmp_default = unit_update_animation_final_keyframe_jmp_default;

		// write the game's default jump case into our jump table
		for(auto& ptr : unit_update_animation_final_keyframe_jmp_table_yelo)
			ptr = CAST_PTR(void*, UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE[jmp_default]);
		
		// remap the existing jump entries into our jump table at the correct indices
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_landing_dead,		unit_update_animation_final_keyframe_jmp_0);
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_seat_enter,		unit_update_animation_final_keyframe_jmp_1);
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_seat_exit,			unit_update_animation_final_keyframe_jmp_2);
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_surprise_front,	unit_update_animation_final_keyframe_jmp_3);
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_surprise_back,		unit_update_animation_final_keyframe_jmp_3);
		unit_update_animation_final_keyframe_jmp_table_yelo_remapping(
			Enums::_unit_animation_state_leap_start,		unit_update_animation_final_keyframe_jmp_4);

		// set the game's jump table count to ours
		GET_PTR(unit_update_animation_final_keyframe_jmp_tbl_count) = Enums::_unit_animation_state_yelo - 1;
		// set the game's jump table address to ours
		GET_PTR(unit_update_animation_final_keyframe_jmp_ptr) = unit_update_animation_final_keyframe_jmp_table_yelo;		
		// nullify jmp table size adjustment
		Memory::WriteMemory(GET_FUNC_VPTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE_ADJUST_SIZE), opcode_null, 3);
		// nullify indirect table references
		Memory::WriteMemory(GET_FUNC_VPTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_INDIRECT_TABLE_PTR), opcode_null);
		// fix jmp table index value
		Memory::WriteMemory(GET_FUNC_VPTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_INDIRECT_TABLE_PTR + sizeof(opcode_null)), jmp_eax, sizeof(jmp_eax));
	}

	static bool UnitAnimationStateInterruptableHook()
	{
		const s_unit_animation_data* unit_animation;
		_enum next_animation_state;

		_asm mov	next_animation_state, dx;
		_asm mov	unit_animation, ecx;

		return blam::unit_animation_state_interruptable(*unit_animation, next_animation_state);
	}
	static bool UnitAnimationBusyHook()
	{
		const s_unit_animation_data* unit_animation;

		_asm mov	unit_animation, ecx;

		return blam::unit_animation_busy(*unit_animation);
	}
	static bool UnitAnimationStateLoopsHook()
	{
		const s_unit_animation_data* unit_animation;

		_asm mov	unit_animation, ecx;

		return blam::unit_animation_state_loops(*unit_animation);
	}
	static bool UnitAnimationWeaponIKHook()
	{
		const s_unit_animation_data* unit_animation;

		_asm mov	unit_animation, ecx;

		return blam::unit_animation_weapon_ik(*unit_animation);
	}
	static bool UnitAnimationVehicleIKHook()
	{
		const s_unit_animation_data* unit_animation;

		_asm mov	unit_animation, ecx;

		return blam::unit_animation_vehicle_ik(*unit_animation);
	}

	// Called on the primary_keyframe_index of the yelo_seat_board animation
	API_FUNC_NAKED static void PLATFORM_API UnitUpdateAnimationPrimaryKeyframeSeatBoardJMP()
	{
		static const uintptr_t RETN_ADDRESS = GET_FUNC_PTR(UNIT_UPDATE_ANIMATION_PRIMARY_KEYFRAME_SWITCH_RETN);
		
		__asm {
			push	eax
			push	ecx
			push	edx

			push	ebx		// datum_index boarding_unit_index
			call	Units::Boarding::SeatBoardPrimaryKeyframe

			pop		edx
			pop		ecx
			pop		eax

			jmp		RETN_ADDRESS
		}
	}

	// Called on the final keyframe of the yelo_seat_board animation
	API_FUNC_NAKED static void PLATFORM_API UnitUpdateAnimationFinalKeyframeSeatBoardJMP()
	{
		static const uintptr_t RETN_ADDRESS = GET_FUNC_PTR(UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_SWITCH_RETN);

		__asm {
			push	eax
			push	ecx
			push	edx

			push	ebx		// datum_index unit_index
			call	Units::Boarding::SeatBoardFinalKeyframe

			push	edx
			push	ecx
			push	eax

			jmp		RETN_ADDRESS
		}
	}

	// Called on the final keyframe of the seat enter animation
	API_FUNC_NAKED static void PLATFORM_API UnitUpdateAnimationFinalKeyframeSeatEnterJMP()
	{
		// use the seat_enter animation's final keyframe jmp entry as the return address
		static const uintptr_t RETN_ADDRESS = (uint32)UNIT_UPDATE_ANIMATION_FINAL_KEYFRAME_JMP_TABLE
			[unit_update_animation_final_keyframe_jmp_1];

		__asm {
			push	eax
			push	ecx
			push	edx

			mov		eax, ebp
			sub		eax, 16	// address of the next_animation_state variable

			push	eax		// int32* next_animation_state
			push	ebx		// datum_index unit_index
			call	Units::Boarding::SeatEnterFinalKeyframe

			pop		edx
			pop		ecx
			pop		eax

			jmp		RETN_ADDRESS
		}
	}

	// Initializes custom yelo animation states
	// This is where we replace each switch table entry with our new animation states, 
	// which allows us to change the behavior of each animation state (keyframe events, ending behavior, etc.)
	static void InitializeYeloAnimationStates()
	{
		//////////////////////////////////////////////////////////////////////////
		// UnitUpdateAnimationPrimaryKeyframe
		// Called when an animation reaches the primary keyframe index value in the model_animations tag
		unit_update_animation_primary_keyframe_jmp_table_yelo[Enums::_unit_animation_state_seat_exit] = 
			&UnitUpdateAnimationPrimaryKeyframeSeatBoardJMP;
		unit_update_animation_primary_keyframe_jmp_table_yelo[Enums::_unit_animation_state_yelo_seat_board] = 
			&UnitUpdateAnimationPrimaryKeyframeSeatBoardJMP;

		//////////////////////////////////////////////////////////////////////////
		// UnitUpdateAnimationFinalKeyframe
		// Called on the final keyframe of our animation
		unit_update_animation_final_keyframe_jmp_table_yelo[Enums::_unit_animation_state_yelo_seat_board] = 
			&UnitUpdateAnimationFinalKeyframeSeatBoardJMP;
		unit_update_animation_final_keyframe_jmp_table_yelo[Enums::_unit_animation_state_seat_enter] = 
			&UnitUpdateAnimationFinalKeyframeSeatEnterJMP;
	}

	void Initialize()
	{
		Animations::InitializeUnitUpdateAnimationPrimaryKeyframeJmpTable();
		Animations::InitializeUnitUpdateAnimationFinalKeyframeJmpTable();
		Animations::InitializeYeloAnimationStates();
		
		for(auto ptr : K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALLS)
			Memory::WriteRelativeCall(&UnitAnimationStateInterruptableHook, ptr, true);
		for(auto ptr : K_UNIT_ANIMATION_BUSY_CALLS)
			Memory::WriteRelativeCall(&UnitAnimationBusyHook, ptr, true);
		Memory::WriteRelativeCall(&UnitAnimationStateLoopsHook, GET_FUNC_VPTR(K_UNIT_ANIMATION_STATE_LOOPS_CALL), true);
		Memory::WriteRelativeCall(&UnitAnimationWeaponIKHook, GET_FUNC_VPTR(K_UNIT_ANIMATION_WEAPON_IK_CALL), true);
		Memory::WriteRelativeCall(&UnitAnimationVehicleIKHook, GET_FUNC_VPTR(K_UNIT_ANIMATION_VEHICLE_IK_CALL), true);
	}

	void Dispose()
	{
	}
};

}; }; };