/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

namespace Yelo
{
	namespace Enums
	{
		enum game_connection : _enum
		{
			_game_connection_local,
			_game_connection_network_client,
			_game_connection_network_server,
			_game_connection_film_playback,
		};
	};

	namespace GameState
	{
		struct s_main_globals;

		s_main_globals* MainGlobals();

		// Is the game *only* running the simulation locally? (ie, campaign or splitscreen)
		bool IsLocal();
		// Is this machine a server?
		bool IsServer();
		// Is this machine a client?
		bool IsClient();
	};

	namespace blam
	{
		// Gets the current connection type
		Enums::game_connection game_connection();

		// Connect to a multiplayer server using it's ip:port and password
		bool PLATFORM_API main_connect(cstring address, cstring password);

		void PLATFORM_API main_menu_load();
	};	
};