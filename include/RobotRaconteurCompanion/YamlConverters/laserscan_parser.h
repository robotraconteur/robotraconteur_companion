#pragma once
#include <RobotRaconteur.h>
#include "yaml-cpp/yaml.h"
#include <boost/uuid/uuid_io.hpp>
#include "robotraconteur_generated.h"
#include "yaml_loader_enums.h"

using namespace RobotRaconteur;
using namespace Companion;
using namespace boost;

namespace RR = RobotRaconteur;

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanInfoPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfo);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			if(node["angle_min"]){
				rhs->angle_min = node["angle_min"].as<double>();
			}
			if(node["angle_max"]){
				rhs->angle_max = node["angle_max"].as<double>();
			}
			if(node["angle_increment"]){
				rhs->angle_increment = node["angle_increment"].as<double>();
			}
			if(node["angle_count"]){
				rhs->angle_count = node["angle_count"].as<uint32_t>();
			}
			if(node["vertical_angle_min"]){
				rhs->vertical_angle_min = node["vertical_angle_min"].as<double>();
			}
			if(node["vertical_angle_max"]){
				rhs->vertical_angle_max = node["vertical_angle_max"].as<double>();
			}
			if(node["vertical_angle_increment"]){
				rhs->vertical_angle_increment = node["vertical_angle_increment"].as<double>();
			}
			if(node["vertical_angle_count"]){
				rhs->vertical_angle_count = node["vertical_angle_count"].as<uint32_t>();
			}
			if(node["time_increment"]){
				rhs->time_increment = node["time_increment"].as<double>();
			}
			if(node["scan_time"]){
				rhs->scan_time = node["scan_time"].as<double>();
			}
			if(node["range_min"]){
				rhs->range_min = node["range_min"].as<double>();
			}
			if(node["range_max"]){
				rhs->range_max = node["range_max"].as<double>();
			}
			if(node["range_resolution"]){
				rhs->range_resolution = node["range_resolution"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScan);
			if(node["ranges"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["ranges"].size());
				for (int i = 0; i < node["ranges"].size(); i++) {
					my_array->at(i) = node["ranges"][i].as<double>();
				}
				rhs->ranges = my_array;
			}
			if(node["intensities"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["intensities"].size());
				for (int i = 0; i < node["intensities"].size(); i++) {
					my_array->at(i) = node["intensities"][i].as<double>();
				}
				rhs->intensities = my_array;
			}
			if(node["fiducial"]){
				RRArrayPtr<int32_t> my_array = AllocateEmptyRRArray<int32_t>(node["fiducial"].size());
				for (int i = 0; i < node["fiducial"].size(); i++) {
					my_array->at(i) = node["fiducial"][i].as<int32_t>();
				}
				rhs->fiducial = my_array;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
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
	struct convert<com::robotraconteur::laserscan::LaserScanInfofPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfofPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanInfof);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			if(node["angle_min"]){
				rhs->angle_min = node["angle_min"].as<float>();
			}
			if(node["angle_max"]){
				rhs->angle_max = node["angle_max"].as<float>();
			}
			if(node["angle_increment"]){
				rhs->angle_increment = node["angle_increment"].as<float>();
			}
			if(node["angle_count"]){
				rhs->angle_count = node["angle_count"].as<uint32_t>();
			}
			if(node["vertical_angle_min"]){
				rhs->vertical_angle_min = node["vertical_angle_min"].as<float>();
			}
			if(node["vertical_angle_max"]){
				rhs->vertical_angle_max = node["vertical_angle_max"].as<float>();
			}
			if(node["vertical_angle_increment"]){
				rhs->vertical_angle_increment = node["vertical_angle_increment"].as<float>();
			}
			if(node["vertical_angle_count"]){
				rhs->vertical_angle_count = node["vertical_angle_count"].as<uint32_t>();
			}
			if(node["time_increment"]){
				rhs->time_increment = node["time_increment"].as<float>();
			}
			if(node["scan_time"]){
				rhs->scan_time = node["scan_time"].as<float>();
			}
			if(node["range_min"]){
				rhs->range_min = node["range_min"].as<float>();
			}
			if(node["range_max"]){
				rhs->range_max = node["range_max"].as<float>();
			}
			if(node["range_resolution"]){
				rhs->range_resolution = node["range_resolution"].as<float>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::laserscan::LaserScanfPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanfPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanf);
			if(node["ranges"]){
				RRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node["ranges"].size());
				for (int i = 0; i < node["ranges"].size(); i++) {
					my_array->at(i) = node["ranges"][i].as<float>();
				}
				rhs->ranges = my_array;
			}
			if(node["intensities"]){
				RRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node["intensities"].size());
				for (int i = 0; i < node["intensities"].size(); i++) {
					my_array->at(i) = node["intensities"][i].as<float>();
				}
				rhs->intensities = my_array;
			}
			if(node["fiducial"]){
				RRArrayPtr<int32_t> my_array = AllocateEmptyRRArray<int32_t>(node["fiducial"].size());
				for (int i = 0; i < node["fiducial"].size(); i++) {
					my_array->at(i) = node["fiducial"][i].as<int32_t>();
				}
				rhs->fiducial = my_array;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
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
	struct convert<com::robotraconteur::laserscan::LaserScanPartPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
			if(node["ranges"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["ranges"].size());
				for (int i = 0; i < node["ranges"].size(); i++) {
					my_array->at(i) = node["ranges"][i].as<double>();
				}
				rhs->ranges = my_array;
			}
			if(node["intensities"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["intensities"].size());
				for (int i = 0; i < node["intensities"].size(); i++) {
					my_array->at(i) = node["intensities"][i].as<double>();
				}
				rhs->intensities = my_array;
			}
			if(node["fiducial"]){
				RRArrayPtr<int32_t> my_array = AllocateEmptyRRArray<int32_t>(node["fiducial"].size());
				for (int i = 0; i < node["fiducial"].size(); i++) {
					my_array->at(i) = node["fiducial"][i].as<int32_t>();
				}
				rhs->fiducial = my_array;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
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
	struct convert<com::robotraconteur::laserscan::LaserScanPartfPtr>{
		static Node encode(const com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::laserscan::LaserScanPartf);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
			if(node["ranges"]){
				RRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node["ranges"].size());
				for (int i = 0; i < node["ranges"].size(); i++) {
					my_array->at(i) = node["ranges"][i].as<float>();
				}
				rhs->ranges = my_array;
			}
			if(node["intensities"]){
				RRArrayPtr<float> my_array = AllocateEmptyRRArray<float>(node["intensities"].size());
				for (int i = 0; i < node["intensities"].size(); i++) {
					my_array->at(i) = node["intensities"][i].as<float>();
				}
				rhs->intensities = my_array;
			}
			if(node["fiducial"]){
				RRArrayPtr<int32_t> my_array = AllocateEmptyRRArray<int32_t>(node["fiducial"].size());
				for (int i = 0; i < node["fiducial"].size(); i++) {
					my_array->at(i) = node["fiducial"][i].as<int32_t>();
				}
				rhs->fiducial = my_array;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
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


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::laserscan::LaserScan 
// com::robotraconteur::laserscan::LaserScanf 
// com::robotraconteur::laserscan::LaserScanPart 
// com::robotraconteur::laserscan::LaserScanPartf 

}