#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::payload::PayloadInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::payload::PayloadInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::payload::PayloadInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
			rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}