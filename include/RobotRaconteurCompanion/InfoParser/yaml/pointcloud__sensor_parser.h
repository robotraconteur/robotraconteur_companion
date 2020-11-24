#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->range_min = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"range_min",true);
			rhs->range_max = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"range_max",true);
			rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
			rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudfPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudPartSensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudPartfPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2SensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2fPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2PartfPtr>(node,"point_cloud",true);
			return true;
		}
	};



}