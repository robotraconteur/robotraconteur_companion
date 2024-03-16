#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
			rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorData); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudfPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudPartSensorData); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloudPartfPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2SensorData); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2fPtr>(node,"point_cloud",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorData); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensor::SensorDataPtr>(node,"sensor_data",true);
			rhs->point_cloud = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::pointcloud::PointCloud2PartfPtr>(node,"point_cloud",true);
			return true;
		}
	};



}