/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

multiplayer_map_data_t* MultiplayerMaps()		PTR_IMP_GET2(multiplayer_maps);
cstring* MapListIgnoredMapNames()				PTR_IMP_GET2(map_list_ignored_map_names);

static void MapListInitialize()
{
	static const uintptr_t INITIALIZE = GET_FUNC_PTR(MULTIPLAYER_MAP_LIST_INITIALIZE);

	__asm	call	INITIALIZE
	MapListInitializeYelo();
}

API_FUNC_NAKED void MapListReIntialize()
{
	static const uintptr_t DISPOSE = GET_FUNC_PTR(MULTIPLAYER_MAP_LIST_DISPOSE);

	__asm {
		call	DISPOSE
		call	MapListInitialize
		retn
	}
}