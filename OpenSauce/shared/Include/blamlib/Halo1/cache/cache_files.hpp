/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blamlib/Halo1/scenario/scenario.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum cache_file_request_source : byte_enum {
			_cache_file_request_source_open_map,
			_cache_file_request_source_bitmaps,
			_cache_file_request_source_sounds,
			_cache_file_request_source_loc,
		};

		enum cache_file_type : _enum {
			_cache_file_type_campaign		= _scenario_type_campaign,
			_cache_file_type_multiplayer	= _scenario_type_multiplayer,
			_cache_file_type_main_menu		= _scenario_type_main_menu,
		};
	};

	namespace Cache
	{
		struct s_cache_file_globals;
		struct s_cache_header;
		struct s_cache_tag_header;
		struct s_cache_tag_instance;

		struct s_cache_file_request_params
		{
			typedef void (PLATFORM_API* proc_finished)(void* params);

			bool* finished_flag;// NOT optional
			void* finished_proc_params;	// optional
			proc_finished finished_proc;// optional
		}; BOOST_STATIC_ASSERT( sizeof(s_cache_file_request_params) == 0xC );

		extern cstring K_MAP_FILE_EXTENSION; /// ".maps"
		extern cstring K_MAP_FILES_DIRECTORY;/// "maps\"


		s_cache_file_globals* CacheFileGlobals();
		
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Directory to the maps\ folder for the defined PLATFORM_TYPE. </summary>
		///
		/// <remarks>For editors, this is the maps path as defined by the editor profile settings. For the runtime, this is
		/// 	just "maps\".
		/// </remarks>
		///
		/// <returns>	. </returns>
		cstring MapsDirectory();
	};

	namespace blam
	{
		bool PLATFORM_API cache_file_read_request(/*datum_index tag_index,*/ // unused, and optimized out, at runtime
			uint32 offset, uint32 size, void* buffer, const Cache::s_cache_file_request_params& params, 
			bool block = true, Enums::cache_file_request_source source = Enums::_cache_file_request_source_open_map);
	};
};