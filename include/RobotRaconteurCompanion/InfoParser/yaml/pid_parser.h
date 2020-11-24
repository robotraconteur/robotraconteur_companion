#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::pid::PIDParamPtr>{
		static Node encode(const com::robotraconteur::pid::PIDParamPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pid::PIDParamPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pid::PIDParam);
			rhs->p = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p",true);
			rhs->i = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"i",true);
			rhs->d = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"d",true);
			rhs->imax = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"imax",true);
			rhs->imin = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"imin",true);
			rhs->cmd_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"cmd_max",true);
			rhs->cmd_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"cmd_min",true);
			return true;
		}
	};



}