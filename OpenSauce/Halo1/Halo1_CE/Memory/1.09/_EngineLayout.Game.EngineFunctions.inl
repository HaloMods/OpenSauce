/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

ENGINE_PTR(const void*, gather_exception_data,	0x6BDEAC, 0x626524);
FUNC_PTR(GATHER_EXCEPTION,					0x582780, 0x52AEB0);

FUNC_PTR(RASTERIZER_SET_TEXTURE_BITMAP_DATA,	0x51C370, FUNC_PTR_NULL);
FUNC_PTR(RESOLUTION_LIST_ADD_RESOLUTION,		0x4BE350, FUNC_PTR_NULL);

FUNC_PTR(ANIMATION_CHOOSE_RANDOM_PERMUTATION_INTERNAL,	0x4D97C0, 0x4C1CF0);

FUNC_PTR(GSMD5DIGEST,						0x5BFB70, 0x52F7E0);

FUNC_PTR(SHELL_GET_COMMAND_LINE_ARGUMENT,		0x5460E0, 0x4FF900);

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
FUNC_PTR(ACTOR_ACTION_CHANGE,				0x40D8D0, 0x40D8E0);
FUNC_PTR(AI_SCRIPTING_ATTACH_FREE,			0x435420, 0x435430);

//////////////////////////////////////////////////////////////////////////
// Cache
FUNC_PTR(CACHE_FILE_READ_REQUEST,					0x443580+0x10, 0x4440A0+0x10);
FUNC_PTR(SOUND_CACHE_SOUND_REQUEST,					0x444940, FUNC_PTR_NULL);
FUNC_PTR(TEXTURE_CACHE_BITMAP_GET_HARDWARE_FORMAT,	0x445080, FUNC_PTR_NULL);
FUNC_PTR(PHYSICAL_MEMORY_MAP_PREDICT_RESOURCES,		0x445520, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Camera
FUNC_PTR(DIRECTOR_DESIRED_PERSPECTIVE,			0x446650, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Console
FUNC_PTR(CONSOLE_PROCESS_COMMAND,	0x4C9F40, 0x4B3990);
FUNC_PTR(CONSOLE_PRINTF,			0x4C9D40, 0x48ED70);
FUNC_PTR(CONSOLE_RESPONSE_PRINTF,	0x4C9DE0, 0x4B3790);
FUNC_PTR(CONSOLE_WARNING,			0x4C9EA0, 0x4B38F0);

//////////////////////////////////////////////////////////////////////////
// Cheats
FUNC_PTR(CHEAT_ALL_WEAPONS,						0x45B0B0, 0x457B10);
FUNC_PTR(CHEAT_SPAWN_WARTHOG,					0x45B140, 0x457BA0);
FUNC_PTR(CHEAT_TELEPORT_TO_CAMERA,				0x45B1B0, 0x457C10);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE,				0x45B240, 0x457CA0);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE_LOCAL_PLAYER,	0x45B2A0, 0x457D00);
FUNC_PTR(CHEAT_PLAYER_INDEX,					0x45B320, 0x457D80);
FUNC_PTR(DIRECTOR_SAVE_CAMERA,					0x4463B0, FUNC_PTR_NULL);
FUNC_PTR(DIRECTOR_LOAD_CAMERA,					0x446470, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Effects
FUNC_PTR(EFFECT_NEW_ON_OBJECT_MARKER,		0x48B640, 0x482F20);

//////////////////////////////////////////////////////////////////////////
// Game
FUNC_PTR(SCENARIO_SWITCH_STRUCTURE_BSP,		0x542610, 0x4FD320);
FUNC_PTR(BINK_PLAYBACK_START,				0x43ED20, FUNC_PTR_NULL);
FUNC_PTR(GAME_ENGINE_RASTERIZE_MESSAGE,		0x462C90, FUNC_PTR_NULL);
FUNC_PTR(GAME_TEAM_IS_ENEMY,				0x45C8D0, 0x459280);
FUNC_PTR(GAME_ENGINE_PLAY_MULTIPLAYER_SOUND,0x46EC70, 0x4665D0);

//////////////////////////////////////////////////////////////////////////
// HS
FUNC_PTR(OBJECT_LIST_ADD,					0x48E000, 0x4858E0);

//////////////////////////////////////////////////////////////////////////
// Input
FUNC_PTR(INPUT_KEY_IS_DOWN, 0x493AD0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Interface
FUNC_PTR(KEYSTONE_CHAT_LOG_ADD_STRING,	0x4AEAD0, FUNC_PTR_NULL); // I forget if the dedicated has a chat log equivalent...
FUNC_PTR(HUD_PRINT_MESSAGE,				0x4B1790, 0x4A0240);
FUNC_PTR(HUD_GET_ITEM_MESSAGE,			0x4AD630, 0x49F340);
FUNC_PTR(HUD_DRAW_METER,				0x4AF1B0+0x30, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_NUMBERS,				0x4AF6A0+0x30, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_STATIC_ELEMENT,		0x4AFCE0+0x30, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_BITMAP,				0x4B00C0+0x30, FUNC_PTR_NULL);
FUNC_PTR(MAINMENU_LOAD,					0x4CBF00, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Items
FUNC_PTR(WEAPON_PREVENTS_MELEE_ATTACK,				0x4C6460, 0x4AFF40);
FUNC_PTR(WEAPON_PREVENTS_GRENADE_THROWING,			0x4C64B0, 0x4AFF90);
FUNC_PTR(WEAPON_STOP_RELOAD,						0x4C80D0, 0x4B1BB0);
FUNC_PTR(FIRST_PERSON_WEAPON_MESSAGE_FROM_UNIT,		0x4956C0, 0x48C330);
FUNC_PTR(WEAPON_GET_FIRST_PERSON_ANIMATION_TIME,	0x4C6500, 0x4AFFE0);

//////////////////////////////////////////////////////////////////////////
// Math
FUNC_PTR(PERIODIC_FUNCTION_EVALUATE,	0x4CFEF0, 0x4B8F60);
FUNC_PTR(TRANSITION_FUNCTION_EVALUATE,	0x4D0000, 0x4B9070);

//////////////////////////////////////////////////////////////////////////
// Memory
FUNC_PTR(DATA_NEW,			0x4D3880+0x30, 0x4BC7F0+0x30);
FUNC_PTR(DATUM_NEW_AT_INDEX,0x4D3910, 0x4BC880);
FUNC_PTR(DATUM_NEW,			0x4D39C0, 0x4BC930);
FUNC_PTR(DATUM_DELETE,		0x4D3A50, 0x4BC9C0);
FUNC_PTR(DATA_DELETE_ALL,	0x4D3A90+0x30, 0x4BCA00+0x30);
FUNC_PTR(DATA_ITERATOR_NEXT,0x4D3B10, 0x4BCA80);
FUNC_PTR(DATA_NEXT_INDEX,	0x4D3B70, 0x4BCAE0);
FUNC_PTR(DATUM_TRY_AND_GET,	0x4D3BC0, 0x4BCB30);
FUNC_PTR(DATUM_INITIALIZE,	0x4D3C00, 0x4BCB70);

//////////////////////////////////////////////////////////////////////////
// Models
FUNC_PTR(MODEL_FIND_MARKER,	0x4DAD00, 0x4C2950);

//////////////////////////////////////////////////////////////////////////
// Networking
FUNC_PTR(HUD_CHAT_TO_NETWORK,							0x4ADF70, 0x49F740);
FUNC_PTR(INDEX_RESOLUTION_TABLE_TRANSLATE,				0x4F4270, 0x4DD4D0);
FUNC_PTR(MAIN_CONNECT,									0x4CB950+0x30, 0x4B4D50+0x30);

//////////////////////////////////////////////////////////////////////////
// Objects
FUNC_PTR(HS_OBJECT_ORIENT,				0x48ACA0, 0x482580);

FUNC_PTR(OBJECT_HEADER_BLOCK_ALLOCATE,	0x4FBAE0, 0x4E2A30);
FUNC_PTR(OBJECT_ITERATOR_NEXT,			0x4FAB80+0x30, 0x4E1AD0+0x30);

FUNC_PTR(OBJECT_PLACEMENT_DATA_NEW,			0x4F9030, 0x4E0020);
FUNC_PTR(OBJECT_NEW,						0x4F90F0, 0x4E00E0);
FUNC_PTR(OBJECT_NEW_WITH_ROLE,				0x4F9140, 0x4E0130);
FUNC_PTR(OBJECT_DELETE_TO_NETWORK,			0x4F9730, 0x4E0720);
FUNC_PTR(OBJECT_DELETE,						0x4F9860, 0x4E0850);
FUNC_PTR(OBJECT_ATTACH_TO_MARKER,			0x4F9E10, 0x4E0D60);
FUNC_PTR(OBJECT_DETACH,						0x4FA2A0, 0x4E11F0);
FUNC_PTR(OBJECTS_FIND_IN_SPHERE,			0x4FAC70, 0x4E1BC0);
FUNC_PTR(OBJECT_START_INTERPOLATION,		0x4FA800, 0x4E1750);
FUNC_PTR(OBJECT_RESET,						0x4F8DF0, 0x4DFDE0);
FUNC_PTR(OBJECT_RECONNECT_TO_MAP,			0x4F98C0, 0x4E08B0);
FUNC_PTR(OBJECT_DISCONNECT_FROM_MAP,		0x4F9A70, 0x4E0A60);
FUNC_PTR(OBJECT_GET_ORIGIN,					0x4FA590, 0x4E14E0);
FUNC_PTR(OBJECT_GET_ORIENTATION,			0x4FA600, 0x4E1550);
FUNC_PTR(OBJECT_GET_LOCATION,				0x4FA7A0, 0x4E16F0);
FUNC_PTR(OBJECT_SET_POSITION,				0x4F8E50, 0x4DFE40);
FUNC_PTR(OBJECT_SET_POSITION_NETWORK,		0x4F8F50, 0x4DFF40);
FUNC_PTR(OBJECT_RESTORE_BODY,				0x4F1660, 0x4DA8C0);
FUNC_PTR(OBJECT_DEPLETE_BODY,				0x4F16B0, 0x4DA910);
FUNC_PTR(OBJECT_DEPLETE_SHIELD,				0x4F17A0, 0x4DAA00);
FUNC_PTR(OBJECT_DOUBLE_CHARGE_SHIELD,		0x4F1830, 0x4DAA90);
FUNC_PTR(OBJECT_CAUSE_DAMAGE,				0x4F2270, 0x4DB4D0);
FUNC_PTR(OBJECT_DEFINITION_PREDICT,			0x4FB760, 0x4E26B0);
FUNC_PTR(OBJECT_SET_SCALE,					0x4FD330, 0x4E4280);
FUNC_PTR(OBJECT_GET_LEVEL_OF_DETAIL_PIXELS,	0x5133E0, FUNC_PTR_NULL);
FUNC_PTR(OBJECT_RENDER_STATE_REFRESH,		0x512F10, FUNC_PTR_NULL);
FUNC_PTR(OBJECTS_UPDATE,					0x4F8B20, 0x4DFB10);
FUNC_PTR(OBJECT_UPDATE,						0x4FBB80, 0x4FBB80);
FUNC_PTR(OBJECT_GET_MARKER_BY_NAME,			0x4F9D10, 0x4E0C60);
FUNC_PTR(OBJECT_DESTROY,					0x4F1910, 0x4DAB70);

//////////////////////////////////////////////////////////////////////////
// Units
FUNC_PTR(UNIT_UPDATE,							0x5660B0, 0x514A40);
FUNC_PTR(UNIT_GET_CAMERA_POSITION,				0x56CA80, FUNC_PTR_NULL);
FUNC_PTR(UNIT_SET_ANIMATION,					0x572910, 0x521010);
FUNC_PTR(UNIT_ANIMATION_START_ACTION,			0x569900, 0x518290);
FUNC_PTR(UNIT_GET_CUSTOM_ANIMATION_TIME,		0x573EF0, 0x522600);
FUNC_PTR(UNIT_CAN_ENTER_SEAT,					0x56A340, 0x518CD0);
FUNC_PTR(UNIT_ENTER_SEAT,						0x56A470, 0x518E00);
FUNC_PTR(UNIT_EXIT_VEHICLE,						0x56F330, 0x51DA80);
FUNC_PTR(UNIT_OPEN,								0x56E850, 0x51CFA0);
FUNC_PTR(UNIT_CLOSE,							0x56E870, 0x51CFC0);
FUNC_PTR(UNIT_FIND_NEARBY_SEAT,					0x56A060, 0x5189F0);
FUNC_PTR(UNIT_EXIT_SEAT_END,					0x570380, 0x51EAD0);
FUNC_PTR(UNIT_CAN_SEE_POINT,					0x56FE40, 0x51E590);
FUNC_PTR(UNIT_TRY_AND_EXIT_SEAT,				0x433EA0, 0x433EB0);
FUNC_PTR(UNIT_DETACH_FROM_PARENT,				0x570780, 0x51EED0);
FUNC_PTR(UNIT_START_USER_ANIMATION,				0x573FE0, 0x5226F0);
FUNC_PTR(UNIT_DROP_CURRENT_WEAPON,				0x571C00, 0x520350);
FUNC_PTR(UNIT_DAMAGE_AFTERMATH,					0x56AFA0, 0x519930);
FUNC_PTR(UNIT_SCRIPTING_SET_CURRENT_VITALITY,	0x565680, 0x514010);
FUNC_PTR(UNIT_ANIMATION_SET_STATE,				0x569A90, 0x518420);
FUNC_PTR(UNIT_INVENTORY_GET_WEAPON,				0x56D6B0, 0x51BE00);
FUNC_PTR(UNIT_THROW_GRENADE_RELEASE,			0x572180, 0x520880);
FUNC_PTR(UNIT_CAUSE_PLAYER_MELEE_DAMAGE,		0x573290, 0x521990);
FUNC_PTR(UNIT_SET_ACTIVELY_CONTROLLED,			0x56D930, 0x51C080);
FUNC_PTR(UNIT_READY_DESIRED_WEAPON,				0x571420, 0x51FB70);

//////////////////////////////////////////////////////////////////////////
// Physics
FUNC_PTR(COLLISION_TEST_VECTOR,			0x5094F0+0x30, 0x4EF5D0+0x30);

//////////////////////////////////////////////////////////////////////////
// Players
FUNC_PTR(PLAYER_INDEX_FROM_UNIT_INDEX,			0x477BF0, 0x46F670);
FUNC_PTR(PLAYER_TELEPORT,						0x478A90, 0x470510);
FUNC_PTR(PLAYER_OVER_SHIELD_SCREEN_EFFECT,		0x47C4B0, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_CAMO_SCREEN_EFFECT,				0x47C570, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_HEALTH_PACK_SCREEN_EFFECT,		0x47C630, FUNC_PTR_NULL);
FUNC_PTR(FIND_CLOSEST_PLAYER_INDEX,				0x45EEE0, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_EXAMINE_NEARBY_VEHICLE,			0x47B3A0, 0x472E20);
FUNC_PTR(PLAYER_SET_ACTION_RESULT,				0x47BBA0, 0x473620);
FUNC_PTR(PLAYER_SET_ACTION_RESULT_TO_NETWORK,	0x47BD90, 0x473810);
FUNC_PTR(PLAYER_CONTROL_GET_UNIT_CAMERA_INFO,	0x474EC0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Render
FUNC_PTR(RENDER_FRAME,							0x50FB40, FUNC_PTR_NULL);
FUNC_PTR(RENDER_WINDOW_FUNC,					0x50FC50, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Scenario
FUNC_PTR(SCENARIO_TRIGGER_VOLUME_TEST_POINT,0x542780, 0x4FD490);

//////////////////////////////////////////////////////////////////////////
// TagGroups
FUNC_PTR(TAG_LOADED,							0x4429A0, 0x443530);
FUNC_PTR(TAG_ITERATOR_NEXT,						0x442A20, 0x4435B0);
FUNC_PTR(UNICODE_STRING_LIST_GET_STRING,		0x55B390, 0x509DE0);