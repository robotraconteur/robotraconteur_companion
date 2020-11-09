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
	struct convert<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectoryWaypoint);
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
			if(node["position_tolerance"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position_tolerance"].size());
				for (int i = 0; i < node["position_tolerance"].size(); i++) {
					my_array->at(i) = node["position_tolerance"][i].as<double>();
				}
				rhs->position_tolerance = my_array;
			}
			if(node["velocity_tolerance"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity_tolerance"].size());
				for (int i = 0; i < node["velocity_tolerance"].size(); i++) {
					my_array->at(i) = node["velocity_tolerance"][i].as<double>();
				}
				rhs->velocity_tolerance = my_array;
			}
			if(node["interpolation_mode"]){
				std::string enum_val_string= node["interpolation_mode"].as<std::string>();
				rhs->interpolation_mode = com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode(string_to_enum_InterpolationMode(enum_val_string));
			}
			if(node["waypoint_type"]){
				std::string enum_val_string= node["waypoint_type"].as<std::string>();
				rhs->waypoint_type = com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType(string_to_enum_TrajectoryWaypointType(enum_val_string));
			}
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectory);
			if(node["joint_names"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["joint_names"].size(); j++){
					std::string item= node["joint_names"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->joint_names = listy;
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
	struct convert<com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::TrajectoryStatus);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["action_status"]){
				std::string enum_val_string= node["action_status"].as<std::string>();
				rhs->action_status = com::robotraconteur::action::ActionStatusCode::ActionStatusCode(string_to_enum_ActionStatusCode(enum_val_string));
			}
			if(node["current_waypoint"]){
				rhs->current_waypoint = node["current_waypoint"].as<uint32_t>();
			}
			if(node["trajectory_time"]){
				rhs->trajectory_time = node["trajectory_time"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypoint);
			if(node["joint_position"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joint_position"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_position"][i].size());
					for(int k =0; k<node["joint_position"][i].size(); k++) {
						my_array->at(k)=node["joint_position"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joint_position = listy;
			}
			if(node["joint_velocity"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joint_velocity"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity"][i].size());
					for(int k =0; k<node["joint_velocity"][i].size(); k++) {
						my_array->at(k)=node["joint_velocity"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joint_velocity = listy;
			}
			if(node["joint_acceleration"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joint_acceleration"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_acceleration"][i].size());
					for(int k =0; k<node["joint_acceleration"][i].size(); k++) {
						my_array->at(k)=node["joint_acceleration"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joint_acceleration = listy;
			}
			if(node["joint_jerk"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joint_jerk"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_jerk"][i].size());
					for(int k =0; k<node["joint_jerk"][i].size(); k++) {
						my_array->at(k)=node["joint_jerk"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joint_jerk = listy;
			}
			if(node["joint_effort"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joint_effort"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_effort"][i].size());
					for(int k =0; k<node["joint_effort"][i].size(); k++) {
						my_array->at(k)=node["joint_effort"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joint_effort = listy;
			}
			if(node["position_tolerance"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["position_tolerance"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["position_tolerance"][i].size());
					for(int k =0; k<node["position_tolerance"][i].size(); k++) {
						my_array->at(k)=node["position_tolerance"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->position_tolerance = listy;
			}
			if(node["velocity_tolerance"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["velocity_tolerance"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["velocity_tolerance"][i].size());
					for(int k =0; k<node["velocity_tolerance"][i].size(); k++) {
						my_array->at(k)=node["velocity_tolerance"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->velocity_tolerance = listy;
			}
			if(node["interpolation_mode"]){
				std::string enum_val_string= node["interpolation_mode"].as<std::string>();
				rhs->interpolation_mode = com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode(string_to_enum_InterpolationMode(enum_val_string));
			}
			if(node["waypoint_type"]){
				std::string enum_val_string= node["waypoint_type"].as<std::string>();
				rhs->waypoint_type = com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType(string_to_enum_TrajectoryWaypointType(enum_val_string));
			}
			if(node["signals"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["signals"].begin(); it != node["signals"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["signals"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["signals"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["signals"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["signals"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["signals"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->signals = vars;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypoint);
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevice);
			if(node["device"]){
				rhs->device = node["device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["joint_names"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["joint_names"].size(); j++){
					std::string item= node["joint_names"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->joint_names = listy;
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
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectory);
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
	struct convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypoint);
			if(node["interpolation_mode"]){
				rhs->interpolation_mode = node["interpolation_mode"].as<std::string>();
			}
			if(node["signals"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["signals"].begin(); it != node["signals"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["signals"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["signals"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["signals"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["signals"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["signals"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["signals"]["value"].size());
						for (int i = 0; i < node["signals"]["value"].size(); i++) {
							my_array->at(i) = node["signals"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->signals = vars;
			}
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
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
	struct convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectory);
			if(node["joint_names"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["joint_names"].size(); j++){
					std::string item= node["joint_names"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->joint_names = listy;
			}
			if(node["joint_units"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["joint_units"].size(); j++){
					std::string item= node["joint_units"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->joint_units = listy;
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



}