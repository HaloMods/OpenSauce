/*
    Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition
    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Tool/BuildCacheFile/DataFiles.inl"
#include "Tool/BuildCacheFile/BuildGlobals.inl"
#include "Tool/BuildCacheFile/CullTags.inl"
#include "Tool/BuildCacheFile/PredictedResources.inl"

/*!
 * \brief
 * Code to execute before we commit the yelo header and the tool's code finishes building the cache.
 * 
 * \param header
 * Description of parameter header.
 * 
 * \param ych
 * Description of parameter ych.
 * 
 * This function is called before we commit the yelo header to the resulting cache file's header. The implementing code which 
 * calls this (MemoryUpgrades.inl, InterceptorEnd) calls the tool's build_cache_file_end function after this function completes.
 * 
 */
static void build_cache_file_end_preprocess(s_cache_header* header, s_cache_header_yelo& ych)
{
	s_build_cache_file_for_scenario& bcffs = build_cache_file_for_scenario_internals;

	void* buffer;
	bool result = CheApe::GetCacheFileResourceBuffer(buffer, 
		ych.cheape_definitions.decompressed_size, ych.cheape_definitions.size);

	if(result)
	{
		bcffs.build_cache_file_add_resource(buffer, ych.cheape_definitions.size, 
			&ych.cheape_definitions.offset, false);

		delete buffer;
	}
}

/*!
 * \brief
 * Code to execute before the tool's code for building the cache begins.
 * 
 * \param scenario_name
 * Tag name of the scenario which is being built into a cache.
 * 
 * Since this code is executed before any real cache building code begins, we can do things like create stub tags, in the event the user 
 * doesn't define them. Or anything else we need to do/change in tags (e.g., rename) before they're committed to cache memory.
 *
 */
static void build_cache_file_begin_preprocess(cstring scenario_name)
{
	datum_index scenario_index = tag_load<TagGroups::scenario>(build_cache_file_for_scenario_internals.scenario_path, 0);
	if(!scenario_index.IsNull())
	{
		TagGroups::scenario* scenario = tag_get<TagGroups::scenario>(scenario_index);
		const tag_reference& yelo_reference = scenario->GetYeloReferenceHack();

		if(!yelo_reference.tag_index.IsNull())
		{
			TagGroups::project_yellow* yelo = tag_get<TagGroups::project_yellow>(yelo_reference.tag_index);

			// if there is a globals tag override, rename it to "globals/globals" so 
			// we avoid further hacks in the runtime engine code as it also explicitly 
			// looks for "globals/globals"
			if(yelo->game_globals.name_length > 0)
			{
				yelo->game_globals.tag_index = 
					tag_load(yelo->game_globals.group_tag, yelo->game_globals.name, 0);

				if(!yelo->game_globals.tag_index.IsNull())
					tag_rename(yelo->game_globals.tag_index, "globals\\globals");

				// re-set the reference just for good measure
				tag_reference_set(&yelo->game_globals, 
					yelo->game_globals.group_tag, "globals\\globals");
			}
		}
	}
}

#include "Tool/BuildCacheFile/MemoryUpgrades.inl"

namespace BuildCacheFileEx
{
	void Initialize(bool only_using_data_file_hacks)
	{
		BuildCacheFileEx::CullTags::Initialize();
		BuildCacheFileEx::PredictedResources::Initialize();
		BuildCacheFileEx::MemoryUpgrades::Initialize(only_using_data_file_hacks);
	}

	void Dispose(bool only_using_data_file_hacks)
	{
		BuildCacheFileEx::MemoryUpgrades::Dispose(only_using_data_file_hacks);
		BuildCacheFileEx::PredictedResources::Dispose();
		BuildCacheFileEx::CullTags::Dispose();
	}
};

static void PLATFORM_API build_cache_file_for_scenario_extended(void** arguments)
{
	//////////////////////////////////////////////////////////////////////////
	// Initialize arguments
	struct s_arguments {
		char* mod_name;
		cstring copy_data_files_first_str;
		cstring store_resources_str;
		cstring use_memory_upgrades_str;
		char* scenario_name;
	}* args = CAST_PTR(s_arguments*, arguments);

	bool copy_data_files_first, store_resources, use_memory_upgrades;
	copy_data_files_first = Settings::ParseBoolean(args->copy_data_files_first_str);
	store_resources = Settings::ParseBoolean(args->store_resources_str);
	use_memory_upgrades = Settings::ParseBoolean(args->use_memory_upgrades_str);
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// Initialize locals and globals
	build_cache_file_for_scenario_internals.build_failed = false;
	build_cache_file_for_scenario_internals.scenario_path = args->scenario_name;

	BuildCacheFileEx::MemoryUpgrades::yelo_cache_header_globals.InitializeForNewMap();
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// validate and fix the mod name if it is too long for a tag_string
	const size_t k_max_mod_set_name_length = Enums::k_tag_string_length - sizeof("-bitmaps");

	size_t mod_set_name_length = strlen(args->mod_name);

	if(mod_set_name_length > k_max_mod_set_name_length)
		args->mod_name[k_max_mod_set_name_length+1] = '\0';
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// setup the data files
	bool using_mod_sets = use_memory_upgrades && (mod_set_name_length > 0);

	c_data_files data_files;

	s_build_cache_file_for_scenario::InitializeFileSystem(data_files, args->mod_name, using_mod_sets);

	if(using_mod_sets)
	{
		// check if the user wants to copy the base data files
		if(copy_data_files_first)
			data_files.CopyStock();
	}
	//////////////////////////////////////////////////////////////////////////


	BuildCacheFileEx::MemoryUpgrades::InitializeHeaderGlobals(using_mod_sets, args->mod_name, use_memory_upgrades);

	// open the data files for referencing and write
	s_build_cache_file_for_scenario& bcffs = build_cache_file_for_scenario_internals;
	bcffs.DataFilesOpen(data_files, store_resources);

	// If we're using OS's memory upgrades, force tool to use our file naming convention
	if(use_memory_upgrades) bcffs.InitializeBuildCacheFileEndSprintfOverride();

	BuildCacheFileEx::Initialize(use_memory_upgrades == false);

	// build cache file
		bcffs._build_cache_file_for_scenario(args->scenario_name);

	BuildCacheFileEx::Dispose(use_memory_upgrades == false);

	bcffs.BuildPostprocess(args->mod_name, using_mod_sets);

	bcffs.DataFilesClose(store_resources);
}