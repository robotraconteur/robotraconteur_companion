#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::laserscanner::LaserScannerInfoPtr>{
		static Node encode(const com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscanner::LaserScannerInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->scanner_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scanner_info",true);
			rhs->scan_rate = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"scan_rate",true);
			rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}