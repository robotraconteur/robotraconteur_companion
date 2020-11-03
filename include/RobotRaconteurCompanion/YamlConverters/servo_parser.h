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
	struct convert<com::robotraconteur::servo::ServoInfoPtr>{
		static Node encode(const com::robotraconteur::servo::ServoInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["servo_type"]){
				std::string enum_val_string= node["servo_type"].as<std::string>();
				rhs->servo_type = com::robotraconteur::servo::ServoTypeCode::ServoTypeCode(string_to_enum_ServoTypeCode(enum_val_string));
			}
			if(node["capabilities"]){
				rhs->capabilities = node["capabilities"].as<uint32_t>();
			}
			if(node["axis_count"]){
				rhs->axis_count = node["axis_count"].as<uint32_t>();
			}
			if(node["position_min"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position_min"].size());
				for (int i = 0; i < node["position_min"].size(); i++) {
					my_array->at(i) = node["position_min"][i].as<double>();
				}
				rhs->position_min = my_array;
			}
			if(node["position_max"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position_max"].size());
				for (int i = 0; i < node["position_max"].size(); i++) {
					my_array->at(i) = node["position_max"][i].as<double>();
				}
				rhs->position_max = my_array;
			}
			if(node["velocity_min"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity_min"].size());
				for (int i = 0; i < node["velocity_min"].size(); i++) {
					my_array->at(i) = node["velocity_min"][i].as<double>();
				}
				rhs->velocity_min = my_array;
			}
			if(node["velocity_max"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity_max"].size());
				for (int i = 0; i < node["velocity_max"].size(); i++) {
					my_array->at(i) = node["velocity_max"][i].as<double>();
				}
				rhs->velocity_max = my_array;
			}
			if(node["acceleration_min"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["acceleration_min"].size());
				for (int i = 0; i < node["acceleration_min"].size(); i++) {
					my_array->at(i) = node["acceleration_min"][i].as<double>();
				}
				rhs->acceleration_min = my_array;
			}
			if(node["acceleration_max"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["acceleration_max"].size());
				for (int i = 0; i < node["acceleration_max"].size(); i++) {
					my_array->at(i) = node["acceleration_max"][i].as<double>();
				}
				rhs->acceleration_max = my_array;
			}
			if(node["torque_min"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["torque_min"].size());
				for (int i = 0; i < node["torque_min"].size(); i++) {
					my_array->at(i) = node["torque_min"][i].as<double>();
				}
				rhs->torque_min = my_array;
			}
			if(node["torque_max"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["torque_max"].size());
				for (int i = 0; i < node["torque_max"].size(); i++) {
					my_array->at(i) = node["torque_max"][i].as<double>();
				}
				rhs->torque_max = my_array;
			}
			if(node["gear_ratio"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["gear_ratio"].size());
				for (int i = 0; i < node["gear_ratio"].size(); i++) {
					my_array->at(i) = node["gear_ratio"][i].as<double>();
				}
				rhs->gear_ratio = my_array;
			}
			if(node["sensor_resolution"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["sensor_resolution"].size());
				for (int i = 0; i < node["sensor_resolution"].size(); i++) {
					my_array->at(i) = node["sensor_resolution"][i].as<double>();
				}
				rhs->sensor_resolution = my_array;
			}
			if(node["effort_command_resolution"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["effort_command_resolution"].size());
				for (int i = 0; i < node["effort_command_resolution"].size(); i++) {
					my_array->at(i) = node["effort_command_resolution"][i].as<double>();
				}
				rhs->effort_command_resolution = my_array;
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
	struct convert<com::robotraconteur::servo::ServoStatePtr>{
		static Node encode(const com::robotraconteur::servo::ServoStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoState);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["mode"]){
				std::string enum_val_string= node["mode"].as<std::string>();
				rhs->mode = com::robotraconteur::servo::ServoMode::ServoMode(string_to_enum_ServoMode(enum_val_string));
			}
			if(node["position"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position"].size());
				for (int i = 0; i < node["position"].size(); i++) {
					my_array->at(i) = node["position"][i].as<double>();
				}
				rhs->position = my_array;
			}
			if(node["velocity"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity"].size());
				for (int i = 0; i < node["velocity"].size(); i++) {
					my_array->at(i) = node["velocity"][i].as<double>();
				}
				rhs->velocity = my_array;
			}
			if(node["acceleration"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["acceleration"].size());
				for (int i = 0; i < node["acceleration"].size(); i++) {
					my_array->at(i) = node["acceleration"][i].as<double>();
				}
				rhs->acceleration = my_array;
			}
			if(node["effort"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["effort"].size());
				for (int i = 0; i < node["effort"].size(); i++) {
					my_array->at(i) = node["effort"][i].as<double>();
				}
				rhs->effort = my_array;
			}
			if(node["position_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position_command"].size());
				for (int i = 0; i < node["position_command"].size(); i++) {
					my_array->at(i) = node["position_command"][i].as<double>();
				}
				rhs->position_command = my_array;
			}
			if(node["velocity_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity_command"].size());
				for (int i = 0; i < node["velocity_command"].size(); i++) {
					my_array->at(i) = node["velocity_command"][i].as<double>();
				}
				rhs->velocity_command = my_array;
			}
			if(node["effort_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["effort_command"].size());
				for (int i = 0; i < node["effort_command"].size(); i++) {
					my_array->at(i) = node["effort_command"][i].as<double>();
				}
				rhs->effort_command = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::servo::ServoStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoStateSensorData);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
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
	struct convert<com::robotraconteur::servo::ServoCommandPtr>{
		static Node encode(const com::robotraconteur::servo::ServoCommandPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoCommandPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoCommand);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["status_seqno"]){
				rhs->status_seqno = node["status_seqno"].as<uint64_t>();
			}
			if(node["command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["command"].size());
				for (int i = 0; i < node["command"].size(); i++) {
					my_array->at(i) = node["command"][i].as<double>();
				}
				rhs->command = my_array;
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::servo::ServoInfo 
// com::robotraconteur::servo::ServoStateSensorData 

}