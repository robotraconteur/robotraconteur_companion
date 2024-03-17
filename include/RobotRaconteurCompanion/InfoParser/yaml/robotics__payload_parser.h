#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::payload::PayloadInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs);
	};


}