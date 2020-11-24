#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::units::SIUnitPtr>{
		static Node encode(const com::robotraconteur::units::SIUnitPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::units::SIUnitPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::units::SIUnit);
			rhs->display_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"display_units",true);
			rhs->encoded_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoded_units",true);
			return true;
		}
	};



}