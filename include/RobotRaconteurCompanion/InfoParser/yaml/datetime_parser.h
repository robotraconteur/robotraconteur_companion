#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::datetime::TimeSpec3>{
		static Node encode(const com::robotraconteur::datetime::TimeSpec3& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datetime::TimeSpec3& rhs){
			rhs.s.microseconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int64_t>(node,"microseconds",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::datetime::DateTimeLocalPtr>{
		static Node encode(const com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datetime::DateTimeLocal); // NOLINT(cppcoreguidelines-owning-memory)
			// TODO: parse field ClockInfo clock_info
			rhs->seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int64_t>(node,"seconds",true);
			rhs->nanoseconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"nanoseconds",true);
			rhs->utc_offset_seconds = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"utc_offset_seconds",true);
			rhs->timezone_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"timezone_name",true);
			return true;
		}
	};



}