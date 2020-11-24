#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::gps::GpsStatePtr>{
		static Node encode(const com::robotraconteur::gps::GpsStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::gps::GpsStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsState);
			// TODO: parse field com.robotraconteur.datetime.DateTimeUTC time
			rhs->altitude = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"altitude",true);
			rhs->latitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"latitude_deg",true);
			rhs->longitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"longitude_deg",true);
			rhs->velocity_east = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"velocity_east",true);
			rhs->velocity_north = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"velocity_north",true);
			rhs->velocity_up = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"velocity_up",true);
			return true;
		}
	};



}