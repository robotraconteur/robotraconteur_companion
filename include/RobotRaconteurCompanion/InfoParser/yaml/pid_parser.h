#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pid::PIDParamPtr>{
		static Node encode(const com::robotraconteur::pid::PIDParamPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::pid::PIDParamPtr& rhs);
	};


}