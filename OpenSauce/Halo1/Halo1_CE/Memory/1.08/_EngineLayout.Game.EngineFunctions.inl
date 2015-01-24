/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

ENGINE_PTR(const void*, gather_exception_data,	0x6BDDC4, 0x62648C);
FUNC_PTR(GATHER_EXCEPTION,					0x582750, 0x52AE70);

FUNC_PTR(RASTERIZER_SET_TEXTURE_BITMAP_DATA,	0x51C340, FUNC_PTR_NULL);
FUNC_PTR(RESOLUTION_LIST_ADD_RESOLUTION,		0x4BE320, FUNC_PTR_NULL);

FUNC_PTR(ANIMATION_CHOOSE_RANDOM_PERMUTATION_INTERNAL,	0x4D9790, 0x4C1CC0);

FUNC_PTR(GSMD5DIGEST,						0x5BFA30, 0x52F730);

FUNC_PTR(SHELL_GET_COMMAND_LINE_ARGUMENT,		0x5460B0, 0x4FF8D0);

//////////////////////////////////////////////////////////////////////////
// AI
FUNC_PTR(ACTOR_DELETE,						0x427E60, 0x427E70);
FUNC_PTR(ACTOR_UPDATE,						0x429160, 0x429170);
FUNC_PTR(ACTOR_CUSTOMIZE_UNIT,				0x426CF0, 0x426D00);
FUNC_PTR(ACTOR_SET_ACTIVE,					0x4277C0, 0x4277D0);
FUNC_PTR(ACTOR_SET_DORMANT,					0x427860, 0x427870);
FUNC_PTR(ACTOR_DELETE_PROPS,				0x427E00, 0x427E10);
FUNC_PTR(ACTOR_FREEZE,						0x429000, 0x429010);
FUNC_PTR(ACTOR_CREATE_FOR_UNIT,				0x426AC0, 0x426AD0);
FUNC_PTR(AI_SCRIPTING_ATTACH_FREE,			0x435420, 0x435430);

//////////////////////////////////////////////////////////////////////////
// Cache
FUNC_PTR(CACHE_FILE_READ_REQUEST,					0x443580, 0x4440A0);
FUNC_PTR(SOUND_CACHE_SOUND_REQUEST,					0x444930, FUNC_PTR_NULL);
FUNC_PTR(TEXTURE_CACHE_BITMAP_GET_HARDWARE_FORMAT,	0x445070, FUNC_PTR_NULL);
FUNC_PTR(PHYSICAL_MEMORY_MAP_PREDICT_RESOURCES,		0x445510, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Console
FUNC_PTR(CONSOLE_PROCESS_COMMAND,	0x4C9F10, 0x4B3960);
FUNC_PTR(CONSOLE_PRINTF,			0x4C9D10, 0x48ED40);
FUNC_PTR(CONSOLE_RESPONSE_PRINTF,	0x4C9DB0, 0x4B3760);
FUNC_PTR(CONSOLE_WARNING,			0x4C9E70, 0x4B38C0);

//////////////////////////////////////////////////////////////////////////
// Cheats
FUNC_PTR(CHEAT_ALL_WEAPONS,						0x45B0A0, 0x457B00);
FUNC_PTR(CHEAT_SPAWN_WARTHOG,					0x45B130, 0x457B90);
FUNC_PTR(CHEAT_TELEPORT_TO_CAMERA,				0x45B1A0, 0x457C00);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE,				0x45B230, 0x457C90);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE_LOCAL_PLAYER,	0x45B290, 0x457CF0);
FUNC_PTR(CHEAT_PLAYER_INDEX,					0x45B310, 0x457D70);
FUNC_PTR(DIRECTOR_SAVE_CAMERA,					0x4463A0, FUNC_PTR_NULL);
FUNC_PTR(DIRECTOR_LOAD_CAMERA,					0x446460, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Effects
FUNC_PTR(EFFECT_NEW_ON_OBJECT_MARKER,		0x48B630, 0x482F10);

//////////////////////////////////////////////////////////////////////////
// Game
FUNC_PTR(SCENARIO_SWITCH_STRUCTURE_BSP,		0x5425E0, 0x4FD2F0);
FUNC_PTR(BINK_PLAYBACK_START,				0x43ED20, FUNC_PTR_NULL);
FUNC_PTR(GAME_ENGINE_RASTERIZE_MESSAGE,		0x462C80, FUNC_PTR_NULL);
FUNC_PTR(GAME_TEAM_IS_ENEMY,				0x45C8C0, 0x459270);
FUNC_PTR(GAME_ENGINE_PLAY_MULTIPLAYER_SOUND,0x46EC60, 0x4665C0);

//////////////////////////////////////////////////////////////////////////
// HS
FUNC_PTR(OBJECT_LIST_ADD,					0x48DFF0, 0x4858D0);

//////////////////////////////////////////////////////////////////////////
// Input
FUNC_PTR(INPUT_KEY_IS_DOWN, 0x493AC0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Interface
FUNC_PTR(KEYSTONE_CHAT_LOG_ADD_STRING,	0x4AEAA0, FUNC_PTR_NULL); // I forget if the dedicated has a chat log equivalent...
FUNC_PTR(HUD_PRINT_MESSAGE,				0x4B1760, 0x4A0210);
FUNC_PTR(HUD_GET_ITEM_MESSAGE,			0x4AD600, 0x49F310);
FUNC_PTR(HUD_DRAW_METER,				0x4AF1B0, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_NUMBERS,				0x4AF6A0, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_STATIC_ELEMENT,		0x4AFCE0, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_BITMAP,				0x4B00C0, FUNC_PTR_NULL);
FUNC_PTR(MAINMENU_LOAD,					0x4CBED0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Items
FUNC_PTR(WEAPON_PREVENTS_MELEE_ATTACK,				0x4C6430, 0x4AFF10);
FUNC_PTR(WEAPON_PREVENTS_GRENADE_THROWING,			0x4C6480, 0x4AFF60);
FUNC_PTR(WEAPON_STOP_RELOAD,						0x4C80A0, 0x4B1B80);
FUNC_PTR(FIRST_PERSON_WEAPON_MESSAGE_FROM_UNIT,		0x4956B0, 0x48C320);
FUNC_PTR(WEAPON_GET_FIRST_PERSON_ANIMATION_TIME,	0x4C64D0, 0x4AFFB0);

//////////////////////////////////////////////////////////////////////////
// Math
FUNC_PTR(PERIODIC_FUNCTION_EVALUATE,	0x4CFEC0, 0x4B8F30);
FUNC_PTR(TRANSITION_FUNCTION_EVALUATE,	0x4CFFD0, 0x4B9040);

//////////////////////////////////////////////////////////////////////////
// Memory
FUNC_PTR(DATA_NEW,			0x4D3880, 0x4BC7F0);
FUNC_PTR(DATUM_NEW_AT_INDEX,0x4D38E0, 0x4BC850);
FUNC_PTR(DATUM_NEW,			0x4D3990, 0x4BC900);
FUNC_PTR(DATUM_DELETE,		0x4D3A20, 0x4BC990);
FUNC_PTR(DATA_DELETE_ALL,	0x4D3A90, 0x4BCA00);
FUNC_PTR(DATA_ITERATOR_NEXT,0x4D3AE0, 0x4BCA50);
FUNC_PTR(DATA_NEXT_INDEX,	0x4D3B40, 0x4BCAB0);
FUNC_PTR(DATUM_TRY_AND_GET,	0x4D3B90, 0x4BCB00);
FUNC_PTR(DATUM_INITIALIZE,	0x4D3BD0, 0x4BCB40);

//////////////////////////////////////////////////////////////////////////
// Models
FUNC_PTR(MODEL_FIND_MARKER,	0x4DACD0, 0x4C2920);

//////////////////////////////////////////////////////////////////////////
// Networking
FUNC_PTR(HUD_CHAT_TO_NETWORK,							0x4ADF40, 0x49F710);
FUNC_PTR(INDEX_RESOLUTION_TABLE_TRANSLATE,				0x4F4240, 0x4DD4A0);
FUNC_PTR(MAIN_CONNECT,									0x4CB950, 0x4B4D50);

//////////////////////////////////////////////////////////////////////////
// Objects
FUNC_PTR(HS_OBJECT_ORIENT,				0x48AC90, 0x482570);

FUNC_PTR(OBJECT_HEADER_BLOCK_ALLOCATE,	0x4FBAB0, 0x4E2A00);
FUNC_PTR(OBJECT_ITERATOR_NEXT,			0x4FAB80, 0x4E1AD0);

FUNC_PTR(OBJECT_PLACEMENT_DATA_NEW,		0x4F9000, 0x4DFFF0);
FUNC_PTR(OBJECT_NEW,					0x4F90C0, 0x4E00B0);
FUNC_PTR(OBJECT_NEW_WITH_ROLE,			0x4F9110, 0x4E0100);
FUNC_PTR(OBJECT_DELETE_TO_NETWORK,		0x4F9700, 0x4E06F0);
FUNC_PTR(OBJECT_DELETE,					0x4F9830, 0x4E0820);
FUNC_PTR(OBJECT_ATTACH_TO_MARKER,		0x4F9DE0, 0x4E0D30);
FUNC_PTR(OBJECT_DETACH,					0x4FA270, 0x4E11C0);
FUNC_PTR(OBJECTS_FIND_IN_SPHERE,		0x4FAC40, 0x4E1B90);
FUNC_PTR(OBJECT_START_INTERPOLATION,	0x4FA7D0, 0x4E1720);
FUNC_PTR(OBJECT_RESET,					0x4F8DC0, 0x4DFDB0);
FUNC_PTR(OBJECT_RECONNECT_TO_MAP,		0x4F9890, 0x4E0880);
FUNC_PTR(OBJECT_DISCONNECT_FROM_MAP,	0x4F9A40, 0x4E0A30);
FUNC_PTR(OBJECT_GET_ORIGIN,				0x4FA560, 0x4E14B0);
FUNC_PTR(OBJECT_GET_ORIENTATION,		0x4FA5D0, 0x4E1520);
FUNC_PTR(OBJECT_GET_LOCATION,			0x4FA770, 0x4E16C0);
FUNC_PTR(OBJECT_SET_POSITION,			0x4F8E20, 0x4DFE10);
FUNC_PTR(OBJECT_SET_POSITION_NETWORK,	0x4F8F20, 0x4DFF10);
FUNC_PTR(OBJECT_RESTORE_BODY,			0x4F1630, 0x4DA890);
FUNC_PTR(OBJECT_DEPLETE_BODY,			0x4F1680, 0x4DA8E0);
FUNC_PTR(OBJECT_DEPLETE_SHIELD,			0x4F1770, 0x4DA9D0);
FUNC_PTR(OBJECT_DOUBLE_CHARGE_SHIELD,	0x4F1800, 0x4DA960);
FUNC_PTR(OBJECT_CAUSE_DAMAGE,			0x4F2240, 0x4DB4A0);
FUNC_PTR(OBJECT_DEFINITION_PREDICT,		0x4FB730, 0x4E2680);
FUNC_PTR(OBJECT_SET_SCALE,				0x4FD300, 0x4E4250);
FUNC_PTR(OBJECT_GET_LEVEL_OF_DETAIL_PIXELS,	0x5133B0, FUNC_PTR_NULL);
FUNC_PTR(OBJECT_RENDER_STATE_REFRESH,	0x512EE0, FUNC_PTR_NULL);
FUNC_PTR(OBJECTS_UPDATE,				0x4F8AF0, 0x4DFAE0);
FUNC_PTR(OBJECT_UPDATE,					0x4FBB50, 0x4FBB50);

//////////////////////////////////////////////////////////////////////////
// Units
FUNC_PTR(UNIT_UPDATE,							0x566080, 0x514A10);
FUNC_PTR(UNIT_GET_CAMERA_POSITION,				0x56CA50, FUNC_PTR_NULL);
FUNC_PTR(UNIT_SET_ANIMATION,					0x5728E0, 0x520FE0);
FUNC_PTR(UNIT_ANIMATION_START_ACTION,			0x5698D0, 0x518260);
FUNC_PTR(UNIT_GET_CUSTOM_ANIMATION_TIME,		0x573EC0, 0x5225D0);
FUNC_PTR(UNIT_CAN_ENTER_SEAT,					0x56A310, 0x518CA0);
FUNC_PTR(UNIT_ENTER_SEAT,						0x56A440, 0x518DD0);
FUNC_PTR(UNIT_EXIT_VEHICLE,						0x56F300, 0x51DA50);
FUNC_PTR(UNIT_OPEN,								0x56E820, 0x51CF70);
FUNC_PTR(UNIT_CLOSE,							0x56E840, 0x51CF90);
FUNC_PTR(UNIT_FIND_NEARBY_SEAT,					0x56A030, 0x5189C0);
FUNC_PTR(UNIT_EXIT_SEAT_END,					0x570350, 0x51EAA0);
FUNC_PTR(UNIT_CAN_SEE_POINT,					0x56FE10, 0x51E560);
FUNC_PTR(UNIT_TRY_AND_EXIT_SEAT,				0x433EA0, 0x433EB0);
FUNC_PTR(UNIT_DETACH_FROM_PARENT,				0x570750, 0x51EEA0);
FUNC_PTR(UNIT_START_USER_ANIMATION,				0x573FB0, 0x5226C0);
FUNC_PTR(UNIT_DROP_CURRENT_WEAPON,				0x571BD0, 0x520320);
FUNC_PTR(UNIT_DAMAGE_AFTERMATH,					0x56AF70, 0x519900);
FUNC_PTR(UNIT_SCRIPTING_SET_CURRENT_VITALITY,	0x565650, 0x513FE0);
FUNC_PTR(UNIT_ANIMATION_SET_STATE,				0x569A60, 0x5183F0);
FUNC_PTR(UNIT_INVENTORY_GET_WEAPON,				0x56D680, 0x51BDD0);
FUNC_PTR(UNIT_THROW_GRENADE_RELEASE,			0x572150, 0x520850);
FUNC_PTR(UNIT_CAUSE_PLAYER_MELEE_DAMAGE,		0x573260, 0x521960);

//////////////////////////////////////////////////////////////////////////
// Physics
FUNC_PTR(COLLISION_TEST_VECTOR,			0x5094F0, 0x4EF5D0);

//////////////////////////////////////////////////////////////////////////
// Players
FUNC_PTR(PLAYER_INDEX_FROM_UNIT_INDEX,			0x477BE0, 0x46F660);
FUNC_PTR(PLAYER_TELEPORT,						0x478A80, 0x470500);
FUNC_PTR(PLAYER_OVER_SHIELD_SCREEN_EFFECT,		0x47C4A0, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_CAMO_SCREEN_EFFECT,				0x47C560, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_HEALTH_PACK_SCREEN_EFFECT,		0x47C620, FUNC_PTR_NULL);
FUNC_PTR(FIND_CLOSEST_PLAYER_INDEX,				0x45EED0, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_EXAMINE_NEARBY_VEHICLE,			0x47B390, 0x472E10);
FUNC_PTR(PLAYER_SET_ACTION_RESULT,				0x47BB90, 0x473610);
FUNC_PTR(PLAYER_SET_ACTION_RESULT_TO_NETWORK,	0x47BD80, 0x473800);

//////////////////////////////////////////////////////////////////////////
// Render
FUNC_PTR(RENDER_FRAME,							0x50FB10, FUNC_PTR_NULL);
FUNC_PTR(RENDER_WINDOW,							0x50FC20, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Scenario
FUNC_PTR(SCENARIO_TRIGGER_VOLUME_TEST_POINT,0x542750, 0x4FD460);

//////////////////////////////////////////////////////////////////////////
// TagGroups
FUNC_PTR(TAG_LOADED,							0x442990, 0x443520);
FUNC_PTR(TAG_ITERATOR_NEXT,						0x442A10, 0x4435A0);
FUNC_PTR(UNICODE_STRING_LIST_GET_STRING,		0x55B360, 0x509DB0);