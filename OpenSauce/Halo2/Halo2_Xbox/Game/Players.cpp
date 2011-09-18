/*
	Yelo: Open Sauce SDK
		Halo 2 (Xbox) Edition

	See license\OpenSauce\Halo2_Xbox for specific license information
*/
#include "Common/Precompile.hpp"
#include "Game/Players.hpp"

#include "Memory/Runtime.hpp"

#include "Game/EngineFunctions.hpp"
#include "Interface/Input.hpp"
#include "Objects/Objects.hpp"
#include "Cache/Cache.hpp"

static Yelo::Memory::Opcode::Call UNWIND_PLAYERS_BEFORE;
static Yelo::Memory::Opcode::Call UNWIND_PLAYERS_AFTER;

namespace Yelo
{
#define __EL_INCLUDE_ID			__EL_INCLUDE_GAME
#define __EL_INCLUDE_FILE_ID	__EL_GAME_PLAYERS
#include "Memory/_EngineLayout.inl"

	namespace Players
	{
		void Initialize()
		{
			YELO_MEM_WLIST_BEGIN();
			YELO_MEM_WLIST_ITEM(OverwriteJmp, &UNWIND_PLAYERS_BEFORE, GET_FUNC_VPTR(PLAYERS_UPDATE_BEFORE_GAME_HOOK), &Yelo::Players::UpdateBefore);
			//YELO_MEM_WLIST_ITEM(OverwriteJmp, &UNWIND_PLAYERS_AFTER, GET_FUNC_VPTR(PLAYERS_UPDATE_AFTER_GAME_HOOK), &Yelo::Players::UpdateAfter);
			YELO_MEM_WLIST_END();
		}

		void Dispose()
		{
			YELO_MEM_WLIST_BEGIN();
			YELO_MEM_WRITE(OverwriteJmp, &UNWIND_PLAYERS_BEFORE, GET_FUNC_VPTR(PLAYERS_UPDATE_BEFORE_GAME_HOOK), CAST_PTR(void*, UNWIND_PLAYERS_BEFORE.Address));
			//YELO_MEM_WRITE(OverwriteJmp, &UNWIND_PLAYERS_AFTER, GET_FUNC_VPTR(PLAYERS_UPDATE_AFTER_GAME_HOOK), CAST_PTR(void*, UNWIND_PLAYERS_AFTER.Address));
			YELO_MEM_WLIST_END();
		}

		void UpdateBefore(DWORD arg_0)
		{
			datum_index player = Engine::Players::LocalGetPlayerIndex();

			GameState::s_unit_datum* player_unit;

			if(!player.IsNull() &&
				( player = *(*GameState::_Players())[player]->GetSlaveUnitIndex() ).IsNull() &&
				GameState::ObjectTryAndGet<GameState::s_unit_datum>(player, &player_unit) != NULL
				)
			{
				// when i flipped these bit values (ie take damage = bit value of no die) the player died every time he spawned
				*player_unit->object.GetCollisionFlags() |= Flags::_object_datum_cannot_take_damage_flag;
				*player_unit->object.GetHealthFlags() |= Flags::_object_datum_cannot_die_flag;
				//*player_unit->object.GetJumpHeightScale() = 2.0f;
				byte* def = CAST_PTR(byte*, GameState::_TagInstances()[ player_unit->object.GetDefinition()->index ].Definition);
				*CAST_PTR(real*, &def[0x1F8]) = 6.16f;

				//real* input = CAST_PTR(real*, &Input::CurrentStates(0).LeftTrigger);
				//static wchar_t printbuff[0x200];
				//Std_snwprintf(printbuff, 0x200, L"%f %f %f %f %f %f", input[0], input[1], input[2], input[3], input[4], input[5]);
				//Engine::Interface::HudMessagePrint(printbuff);
			}


			#pragma region Goto the games function
			typedef void (PLATFORM_API* update_before)(DWORD arg_0);
			static update_before players_update_before_game = (update_before)GET_FUNC_PTR(PLAYERS_UPDATE_BEFORE_GAME);
			players_update_before_game(arg_0);
			#pragma endregion
		}

		void UpdateAfter()
		{
			#pragma region Goto the games function
			static proc_update players_update_after_game = (proc_update)GET_FUNC_PTR(PLAYERS_UPDATE_AFTER_GAME_HOOK);
			players_update_after_game();
			#pragma endregion
		}
	};

	namespace GameState
	{
		t_players_data* _Players()							DPTR_IMP_GET(_Players);
		s_player_globals* _PlayerGlobals()					DPTR_IMP_GET(_PlayerGlobals);
		s_player_control_globals* _PlayerControlGlobals()	DPTR_IMP_GET(_PlayerControlGlobals);
		s_player_training_globals* _PlayerTrainingGlobals()	DPTR_IMP_GET(_PlayerTrainingGlobals);
		s_player_effect_globals* _PlayerEffectGlobals()		DPTR_IMP_GET(_PlayerEffectGlobals);
	};
};

// _simulation_player_update_type_left_game = 0
// _simulation_player_update_type_swap = 1
// _simulation_player_update_type_remove = 2
// _simulation_player_update_type_added = 3
// _simulation_player_update_type_configuration = 5