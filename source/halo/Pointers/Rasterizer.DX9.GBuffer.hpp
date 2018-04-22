/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI
#include "Pointers/1.10/HaloCE_110_Runtime.Rasterizer.DX9.inl"
#include "Pointers/1.10/HaloCE_110_Runtime_Manual.Rasterizer.DX9.inl"
#endif

#include <Memory/MemoryInterface.hpp>
#include <Rasterizer/DX9/rasterizer_dx9_shaders_vshader9.hpp>
#include <yelo/memory/memory_interface_base.hpp>

namespace Yelo
{
	namespace DX9
	{
		ENGINE_PTR(DX9::s_vsf_entry*, VSF_TABLE_START_REFERENCE, K_VSF_TABLE_START_REFERENCE, PTR_NULL);

		FUNC_PTR(RENDER_OBJECT_LIST_HOOK, K_RENDER_OBJECT_LIST_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_OBJECT_LIST_HOOK_RETN, K_RENDER_OBJECT_LIST_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(RENDER_OBJECT_LIST_END_HOOK, K_RENDER_OBJECT_LIST_END_HOOK, FUNC_PTR_NULL);

		FUNC_PTR(RENDER_OBJECT_OBJECT_LOD_HOOK, K_RENDER_OBJECT_OBJECT_LOD_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_OBJECT_OBJECT_LOD_HOOK_RETN, K_RENDER_OBJECT_OBJECT_LOD_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(FIRST_PERSON_WEAPON_DRAW_HOOK, K_FIRST_PERSON_WEAPON_DRAW_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(FIRST_PERSON_WEAPON_DRAW_HOOK_RETN, K_FIRST_PERSON_WEAPON_DRAW_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(COMMAND_CAMERA_SET_HOOK, K_COMMAND_CAMERA_SET_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(COMMAND_CAMERA_SET_HOOK_RETN, K_COMMAND_CAMERA_SET_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(COMMAND_SWITCH_BSP_HOOK, K_COMMAND_SWITCH_BSP_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(COMMAND_SWITCH_BSP_HOOK_RETN, K_COMMAND_SWITCH_BSP_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(COMMAND_GAME_SAVE_HOOK, K_COMMAND_GAME_SAVE_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(COMMAND_GAME_SAVE_HOOK_RETN, K_COMMAND_GAME_SAVE_HOOK_RETN, FUNC_PTR_NULL);

		FUNC_PTR(RENDER_OBJECTS_TRANSPARENT, K_RENDER_OBJECTS_TRANSPARENT, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_HOOK, K_RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_RETN, K_RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_RETN, FUNC_PTR_NULL);

		FUNC_PTR(RASTERIZER_DRAW_STATIC_TRIANGLES_STATIC_VERTICES__DRAW_INDEXED_PRIMITIVE_HOOK, K_RASTERIZER_DRAW_STATIC_TRIANGLES_STATIC_VERTICES__DRAW_INDEXED_PRIMITIVE_HOOK, FUNC_PTR_NULL);
		FUNC_PTR(RASTERIZER_DRAW_DYNAMIC_TRIANGLES_STATIC_VERTICES2__DRAW_INDEXED_PRIMITIVE_HOOK, K_RASTERIZER_DRAW_DYNAMIC_TRIANGLES_STATIC_VERTICES2__DRAW_INDEXED_PRIMITIVE_HOOK, FUNC_PTR_NULL);
	}
}
