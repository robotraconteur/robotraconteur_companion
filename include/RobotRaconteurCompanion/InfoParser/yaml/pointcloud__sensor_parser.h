#pragma once
#include <RobotRaconteur.h>
#include "yaml-cpp/yaml.h"
#include <boost/uuid/uuid_io.hpp>
#include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"
#include "yaml_loader_enums.h"

using namespace RobotRaconteur;
using namespace Companion;
using namespace boost;

#pragma once

namespace RR = RobotRaconteur;

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>{
		static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::sensor::PointCloudSensorInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["range_min"]){
				rhs->range_min = node["range_min"].as<com::robotraconteur::geometry::Point>();
			}
			if(node["range_max"]){
				rhs->range_max = node["range_max"].as<com::robotraconteur::geometry::Point>();
			}
			if(node["resolution"]){
				rhs->resolution = node["resolution"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["param_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["param_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["param_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->param_info = listy;
			}
			if(node["extended"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["extended"].begin(); it != node["extended"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["extended"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["extended"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["extended"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["extended"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["extended"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->extended = vars;
			}
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
			if(node["sensor_data"]){
				rhs->sensor_data = node["sensor_data"].as<com::robotraconteur::sensor::SensorDataPtr>();
			}
			if(node["point_cloud"]){
				rhs->point_cloud = node["point_cloud"].as<com::robotraconteur::pointcloud::PointCloudfPtr>();
			}
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
			if(node["sensor_data"]){
				rhs->sensor_data = node["sensor_data"].as<com::robotraconteur::sensor::SensorDataPtr>();
			}
			if(node["point_cloud"]){
				rhs->point_cloud = node["point_cloud"].as<com::robotraconteur::pointcloud::PointCloudPartfPtr>();
			}
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
			if(node["sensor_data"]){
				rhs->sensor_data = node["sensor_data"].as<com::robotraconteur::sensor::SensorDataPtr>();
			}
			if(node["point_cloud"]){
				rhs->point_cloud = node["point_cloud"].as<com::robotraconteur::pointcloud::PointCloud2fPtr>();
			}
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
			if(node["sensor_data"]){
				rhs->sensor_data = node["sensor_data"].as<com::robotraconteur::sensor::SensorDataPtr>();
			}
			if(node["point_cloud"]){
				rhs->point_cloud = node["point_cloud"].as<com::robotraconteur::pointcloud::PointCloud2PartfPtr>();
			}
			return true;
		}
	};



}