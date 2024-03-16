#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::device::isoch::IsochInfoPtr>{
		static Node encode(const com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::isoch::IsochInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->update_rate = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"update_rate",true);
			// TODO: parse field com.robotraconteur.datetime.TimeSpec2 isoch_epoch
			rhs->max_downsample = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"max_downsample",true);
			return true;
		}
	};



}