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
	struct convert<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotKinChainInfo);
			if(node["kin_chain_identifier"]){
				rhs->kin_chain_identifier = node["kin_chain_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["link_identifiers"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::identifier::Identifier> listy = AllocateEmptyRRList<com::robotraconteur::identifier::Identifier>();
				for(int j=0; j< node["link_identifiers"].size(); j++){
					com::robotraconteur::identifier::IdentifierPtr item= node["link_identifiers"][j].as<com::robotraconteur::identifier::IdentifierPtr>();
					listy->push_back(item);
				}
				rhs->link_identifiers = listy;
			}
			if(node["joint_numbers"]){
				RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["joint_numbers"].size());
				for (int i = 0; i < node["joint_numbers"].size(); i++) {
					my_array->at(i) = node["joint_numbers"][i].as<uint32_t>();
				}
				rhs->joint_numbers = my_array;
			}
			if(node["flange_pose"]){
				rhs->flange_pose = node["flange_pose"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["flange_identifier"]){
				rhs->flange_identifier = node["flange_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["current_tool"]){
				rhs->current_tool = node["current_tool"].as<com::robotraconteur::robotics::tool::ToolInfoPtr>();
			}
			if(node["current_payload"]){
				rhs->current_payload = node["current_payload"].as<com::robotraconteur::robotics::payload::PayloadInfoPtr>();
			}
			if(node["tcp_max_velocity"]){
				rhs->tcp_max_velocity = node["tcp_max_velocity"].as<com::robotraconteur::geometry::SpatialVelocity>();
			}
			if(node["tcp_max_acceleration"]){
				rhs->tcp_max_acceleration = node["tcp_max_acceleration"].as<com::robotraconteur::geometry::SpatialAcceleration>();
			}
			if(node["tcp_reduced_max_velocity"]){
				rhs->tcp_reduced_max_velocity = node["tcp_reduced_max_velocity"].as<com::robotraconteur::geometry::SpatialVelocity>();
			}
			if(node["tcp_reduced_max_acceleration"]){
				rhs->tcp_reduced_max_acceleration = node["tcp_reduced_max_acceleration"].as<com::robotraconteur::geometry::SpatialAcceleration>();
			}
			if(node["description"]){
				rhs->description = node["description"].as<std::string>();
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
	struct convert<com::robotraconteur::robotics::robot::RobotInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["robot_type"]){
				std::string enum_val_string= node["robot_type"].as<std::string>();
				rhs->robot_type = com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotTypeCode(enum_val_string));
			}
			if(node["joint_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::robotics::joints::JointInfo> listy = AllocateEmptyRRList<com::robotraconteur::robotics::joints::JointInfo>();
				for(int j=0; j< node["joint_info"].size(); j++){
					com::robotraconteur::robotics::joints::JointInfoPtr item= node["joint_info"][j].as<com::robotraconteur::robotics::joints::JointInfoPtr>();
					listy->push_back(item);
				}
				rhs->joint_info = listy;
			}
			if(node["robot_capabilities"]){
				rhs->robot_capabilities = node["robot_capabilities"].as<uint32_t>();
			}
			if(node["signal_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::signal::SignalInfo> listy = AllocateEmptyRRList<com::robotraconteur::signal::SignalInfo>();
				for(int j=0; j< node["signal_info"].size(); j++){
					com::robotraconteur::signal::SignalInfoPtr item= node["signal_info"][j].as<com::robotraconteur::signal::SignalInfoPtr>();
					listy->push_back(item);
				}
				rhs->signal_info = listy;
			}
			if(node["parameter_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["parameter_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["parameter_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->parameter_info = listy;
			}
			if(node["config_seqno"]){
				rhs->config_seqno = node["config_seqno"].as<uint16_t>();
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
	struct convert<com::robotraconteur::robotics::robot::RobotStatePtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotState);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["command_mode"]){
				std::string enum_val_string= node["command_mode"].as<std::string>();
				rhs->command_mode = com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotCommandMode(enum_val_string));
			}
			if(node["operational_mode"]){
				std::string enum_val_string= node["operational_mode"].as<std::string>();
				rhs->operational_mode = com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotOperationalMode(enum_val_string));
			}
			if(node["controller_state"]){
				std::string enum_val_string= node["controller_state"].as<std::string>();
				rhs->controller_state = com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotControllerState(enum_val_string));
			}
			if(node["robot_state_flags"]){
				rhs->robot_state_flags = node["robot_state_flags"].as<uint64_t>();
			}
			if(node["joint_position"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_position"].size());
				for (int i = 0; i < node["joint_position"].size(); i++) {
					my_array->at(i) = node["joint_position"][i].as<double>();
				}
				rhs->joint_position = my_array;
			}
			if(node["joint_velocity"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity"].size());
				for (int i = 0; i < node["joint_velocity"].size(); i++) {
					my_array->at(i) = node["joint_velocity"][i].as<double>();
				}
				rhs->joint_velocity = my_array;
			}
			if(node["joint_effort"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_effort"].size());
				for (int i = 0; i < node["joint_effort"].size(); i++) {
					my_array->at(i) = node["joint_effort"][i].as<double>();
				}
				rhs->joint_effort = my_array;
			}
			if(node["joint_position_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_position_command"].size());
				for (int i = 0; i < node["joint_position_command"].size(); i++) {
					my_array->at(i) = node["joint_position_command"][i].as<double>();
				}
				rhs->joint_position_command = my_array;
			}
			if(node["joint_velocity_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity_command"].size());
				for (int i = 0; i < node["joint_velocity_command"].size(); i++) {
					my_array->at(i) = node["joint_velocity_command"][i].as<double>();
				}
				rhs->joint_velocity_command = my_array;
			}
			if(node["trajectory_running"]){
				rhs->trajectory_running = node["trajectory_running"].as<bool>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>{
		static Node encode(const com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::AdvancedRobotState);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["command_mode"]){
				std::string enum_val_string= node["command_mode"].as<std::string>();
				rhs->command_mode = com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotCommandMode(enum_val_string));
			}
			if(node["operational_mode"]){
				std::string enum_val_string= node["operational_mode"].as<std::string>();
				rhs->operational_mode = com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotOperationalMode(enum_val_string));
			}
			if(node["controller_state"]){
				std::string enum_val_string= node["controller_state"].as<std::string>();
				rhs->controller_state = com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_RobotControllerState(enum_val_string));
			}
			if(node["robot_state_flags"]){
				rhs->robot_state_flags = node["robot_state_flags"].as<uint64_t>();
			}
			if(node["joint_position"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_position"].size());
				for (int i = 0; i < node["joint_position"].size(); i++) {
					my_array->at(i) = node["joint_position"][i].as<double>();
				}
				rhs->joint_position = my_array;
			}
			if(node["joint_velocity"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity"].size());
				for (int i = 0; i < node["joint_velocity"].size(); i++) {
					my_array->at(i) = node["joint_velocity"][i].as<double>();
				}
				rhs->joint_velocity = my_array;
			}
			if(node["joint_effort"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_effort"].size());
				for (int i = 0; i < node["joint_effort"].size(); i++) {
					my_array->at(i) = node["joint_effort"][i].as<double>();
				}
				rhs->joint_effort = my_array;
			}
			if(node["joint_position_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_position_command"].size());
				for (int i = 0; i < node["joint_position_command"].size(); i++) {
					my_array->at(i) = node["joint_position_command"][i].as<double>();
				}
				rhs->joint_position_command = my_array;
			}
			if(node["joint_velocity_command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity_command"].size());
				for (int i = 0; i < node["joint_velocity_command"].size(); i++) {
					my_array->at(i) = node["joint_velocity_command"][i].as<double>();
				}
				rhs->joint_velocity_command = my_array;
			}
			if(node["joint_position_units"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["joint_position_units"].size());
				for (int i = 0; i < node["joint_position_units"].size(); i++) {
					my_array->at(i) = node["joint_position_units"][i].as<uint8_t>();
				}
				rhs->joint_position_units = my_array;
			}
			if(node["joint_effort_units"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["joint_effort_units"].size());
				for (int i = 0; i < node["joint_effort_units"].size(); i++) {
					my_array->at(i) = node["joint_effort_units"][i].as<uint8_t>();
				}
				rhs->joint_effort_units = my_array;
			}
			if(node["trajectory_running"]){
				rhs->trajectory_running = node["trajectory_running"].as<bool>();
			}
			if(node["trajectory_time"]){
				rhs->trajectory_time = node["trajectory_time"].as<double>();
			}
			if(node["trajectory_max_time"]){
				rhs->trajectory_max_time = node["trajectory_max_time"].as<double>();
			}
			if(node["trajectory_current_waypoint"]){
				rhs->trajectory_current_waypoint = node["trajectory_current_waypoint"].as<uint32_t>();
			}
			if(node["config_seqno"]){
				rhs->config_seqno = node["config_seqno"].as<uint16_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotStateSensorData);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotJointCommandPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotJointCommand);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["state_seqno"]){
				rhs->state_seqno = node["state_seqno"].as<uint64_t>();
			}
			if(node["command"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["command"].size());
				for (int i = 0; i < node["command"].size(); i++) {
					my_array->at(i) = node["command"][i].as<double>();
				}
				rhs->command = my_array;
			}
			if(node["units"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["units"].size());
				for (int i = 0; i < node["units"].size(); i++) {
					my_array->at(i) = node["units"][i].as<uint8_t>();
				}
				rhs->units = my_array;
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::robotics::robot::RobotStateSensorData 

}