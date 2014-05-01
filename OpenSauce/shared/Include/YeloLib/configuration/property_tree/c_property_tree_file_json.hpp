/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <YeloLib/configuration/property_tree/c_property_tree_file.hpp>

namespace Yelo
{
	namespace Configuration { namespace PropertyTree
	{
		class c_property_tree_file_json
			: public c_property_tree_file
		{
		public:
			c_property_tree_file_json(const std::string file_path);

		protected:
			void ReadPropertyTree(const std::string file_path, boost::property_tree::ptree& property_tree);
			void WritePropertyTree(const std::string file_path, boost::property_tree::ptree& property_tree);
		};
	}}
}