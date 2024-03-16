#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanInfoPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_min",true);
			rhs->angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_max",true);
			rhs->angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"angle_increment",true);
			rhs->angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"angle_count",true);
			rhs->vertical_angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_min",true);
			rhs->vertical_angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_max",true);
			rhs->vertical_angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vertical_angle_increment",true);
			rhs->vertical_angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"vertical_angle_count",true);
			rhs->time_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_increment",true);
			rhs->scan_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"scan_time",true);
			rhs->range_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_min",true);
			rhs->range_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_max",true);
			rhs->range_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"range_resolution",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScan); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfoPtr>(node,"scan_info",true);
			rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"ranges",true,true,0);
			rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"intensities",true,true,0);
			rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
			rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanInfofPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfof); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_min",true);
			rhs->angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_max",true);
			rhs->angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"angle_increment",true);
			rhs->angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"angle_count",true);
			rhs->vertical_angle_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_min",true);
			rhs->vertical_angle_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_max",true);
			rhs->vertical_angle_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"vertical_angle_increment",true);
			rhs->vertical_angle_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"vertical_angle_count",true);
			rhs->time_increment = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"time_increment",true);
			rhs->scan_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"scan_time",true);
			rhs->range_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_min",true);
			rhs->range_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_max",true);
			rhs->range_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"range_resolution",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanfPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanfPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanf); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scan_info",true);
			rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"ranges",true,true,0);
			rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"intensities",true,true,0);
			rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
			rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanPartPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfoPtr>(node,"scan_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"ranges",true,true,0);
			rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"intensities",true,true,0);
			rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
			rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanPartfPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPartf); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->scan_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::laserscan::LaserScanInfofPtr>(node,"scan_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			rhs->ranges = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"ranges",true,true,0);
			rhs->intensities = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<float>(node,"intensities",true,true,0);
			rhs->color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::image::PixelRGB>(node,"color",true,true,0);
			rhs->fiducial = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"fiducial",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}