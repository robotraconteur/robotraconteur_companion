#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::datetime::clock::ClockDeviceInfoPtr>{
		static Node encode(const com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datetime::clock::ClockDeviceInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->clock_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode>(node,"clock_type",true);
			rhs->timezone_utc_offset_seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"timezone_utc_offset_seconds",true);
			rhs->timezone_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"timezone_name",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}