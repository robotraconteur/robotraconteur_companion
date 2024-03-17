#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::imaging::CameraStatePtr>{
		static Node encode(const com::robotraconteur::imaging::CameraStatePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::imaging::CameraStatePtr& rhs);
	};


}