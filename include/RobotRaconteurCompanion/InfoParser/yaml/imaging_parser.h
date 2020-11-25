#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::imaging::CameraStatePtr>{
		static Node encode(const com::robotraconteur::imaging::CameraStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::CameraStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::CameraState);
			rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"state_flags",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}