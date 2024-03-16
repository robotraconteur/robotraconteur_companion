#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::lighting::LightInfoPtr>{
		static Node encode(const com::robotraconteur::lighting::LightInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::lighting::LightInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::lighting::LightInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->max_lumens = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"max_lumens",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}