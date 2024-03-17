#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::datatype::DataTypePtr>{
		static Node encode(const com::robotraconteur::datatype::DataTypePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::datatype::DataTypePtr& rhs);
	};


}