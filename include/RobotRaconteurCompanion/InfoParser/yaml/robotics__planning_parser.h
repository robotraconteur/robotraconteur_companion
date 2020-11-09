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
	struct convert<com::robotraconteur::robotics::planning::JointWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::JointWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::JointWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::JointWaypoint);
			if(node["joint_positions"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_positions"].size());
				for (int i = 0; i < node["joint_positions"].size(); i++) {
					my_array->at(i) = node["joint_positions"][i].as<double>();
				}
				rhs->joint_positions = my_array;
			}
			if(node["joint_velocity"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joint_velocity"].size());
				for (int i = 0; i < node["joint_velocity"].size(); i++) {
					my_array->at(i) = node["joint_velocity"][i].as<double>();
				}
				rhs->joint_velocity = my_array;
			}
			if(node["motion_type"]){
				std::string enum_val_string= node["motion_type"].as<std::string>();
				rhs->motion_type = com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_PlannerMotionTypeCode(enum_val_string));
			}
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
			}
			if(node["constraints"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["constraints"].begin(); it != node["constraints"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["constraints"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["constraints"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["constraints"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["constraints"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["constraints"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->constraints = vars;
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
	struct convert<com::robotraconteur::robotics::planning::CartesianWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::CartesianWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::CartesianWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::CartesianWaypoint);
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometry::NamedPosePtr>();
			}
			if(node["velocity"]){
				rhs->velocity = node["velocity"].as<com::robotraconteur::geometry::SpatialVelocity>();
			}
			if(node["motion_type"]){
				std::string enum_val_string= node["motion_type"].as<std::string>();
				rhs->motion_type = com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_PlannerMotionTypeCode(enum_val_string));
			}
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
			}
			if(node["constraints"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["constraints"].begin(); it != node["constraints"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["constraints"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["constraints"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["constraints"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["constraints"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["constraints"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->constraints = vars;
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
	struct convert<com::robotraconteur::robotics::planning::OtherWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::OtherWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::OtherWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::OtherWaypoint);
			if(node["waypoint_type"]){
				rhs->waypoint_type = node["waypoint_type"].as<std::string>();
			}
			if(node["waypoint_parameters"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["waypoint_parameters"].begin(); it != node["waypoint_parameters"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["waypoint_parameters"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["waypoint_parameters"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["waypoint_parameters"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["waypoint_parameters"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["waypoint_parameters"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["waypoint_parameters"]["value"].size());
						for (int i = 0; i < node["waypoint_parameters"]["value"].size(); i++) {
							my_array->at(i) = node["waypoint_parameters"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["waypoint_parameters"]["value"].size());
						for (int i = 0; i < node["waypoint_parameters"]["value"].size(); i++) {
							my_array->at(i) = node["waypoint_parameters"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["waypoint_parameters"]["value"].size());
						for (int i = 0; i < node["waypoint_parameters"]["value"].size(); i++) {
							my_array->at(i) = node["waypoint_parameters"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->waypoint_parameters = vars;
			}
			if(node["motion_type"]){
				std::string enum_val_string= node["motion_type"].as<std::string>();
				rhs->motion_type = com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_PlannerMotionTypeCode(enum_val_string));
			}
			if(node["time_from_start"]){
				rhs->time_from_start = node["time_from_start"].as<double>();
			}
			if(node["constraints"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["constraints"].begin(); it != node["constraints"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["constraints"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["constraints"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["constraints"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["constraints"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["constraints"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["constraints"]["value"].size());
						for (int i = 0; i < node["constraints"]["value"].size(); i++) {
							my_array->at(i) = node["constraints"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->constraints = vars;
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
	struct convert<com::robotraconteur::robotics::planning::PlanningRequestPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningRequestPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningRequestPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningRequest);
			if(node["device"]){
				rhs->device = node["device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["planner_algorithm"]){
				rhs->planner_algorithm = node["planner_algorithm"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["filter_algorithm"]){
				rhs->filter_algorithm = node["filter_algorithm"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["workspace_bounds"]){
				rhs->workspace_bounds = node["workspace_bounds"].as<com::robotraconteur::geometry::Box>();
			}
			if(node["tcp"]){
				rhs->tcp = node["tcp"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["collision_check"]){
				rhs->collision_check = node["collision_check"].as<bool>();
			}
			if(node["collision_safety_margin"]){
				rhs->collision_safety_margin = node["collision_safety_margin"].as<double>();
			}
			if(node["planner_specific"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["planner_specific"].begin(); it != node["planner_specific"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["planner_specific"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["planner_specific"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["planner_specific"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["planner_specific"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["planner_specific"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["planner_specific"]["value"].size());
						for (int i = 0; i < node["planner_specific"]["value"].size(); i++) {
							my_array->at(i) = node["planner_specific"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["planner_specific"]["value"].size());
						for (int i = 0; i < node["planner_specific"]["value"].size(); i++) {
							my_array->at(i) = node["planner_specific"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["planner_specific"]["value"].size());
						for (int i = 0; i < node["planner_specific"]["value"].size(); i++) {
							my_array->at(i) = node["planner_specific"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->planner_specific = vars;
			}
			if(node["filter_specific"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["filter_specific"].begin(); it != node["filter_specific"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["filter_specific"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["filter_specific"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["filter_specific"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["filter_specific"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["filter_specific"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["filter_specific"]["value"].size());
						for (int i = 0; i < node["filter_specific"]["value"].size(); i++) {
							my_array->at(i) = node["filter_specific"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["filter_specific"]["value"].size());
						for (int i = 0; i < node["filter_specific"]["value"].size(); i++) {
							my_array->at(i) = node["filter_specific"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["filter_specific"]["value"].size());
						for (int i = 0; i < node["filter_specific"]["value"].size(); i++) {
							my_array->at(i) = node["filter_specific"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->filter_specific = vars;
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
	struct convert<com::robotraconteur::robotics::planning::PlanningResponsePtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningResponsePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningResponsePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningResponse);
			if(node["status_code"]){
				std::string enum_val_string= node["status_code"].as<std::string>();
				rhs->status_code = com::robotraconteur::robotics::planning::PlannerStatusCode::PlannerStatusCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_PlannerStatusCode(enum_val_string));
			}
			if(node["joint_trajectory"]){
				rhs->joint_trajectory = node["joint_trajectory"].as<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>();
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
	struct convert<com::robotraconteur::robotics::planning::ContactResultPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::ContactResultPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::ContactResultPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::ContactResult);
			if(node["distance"]){
				rhs->distance = node["distance"].as<double>();
			}
			if(node["link1_name"]){
				rhs->link1_name = node["link1_name"].as<std::string>();
			}
			if(node["link2_name"]){
				rhs->link2_name = node["link2_name"].as<std::string>();
			}
			if(node["link1_nearest_point"]){
				rhs->link1_nearest_point = node["link1_nearest_point"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["link2_nearest_point"]){
				rhs->link2_nearest_point = node["link2_nearest_point"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["link1_nearest_point_local"]){
				rhs->link1_nearest_point_local = node["link1_nearest_point_local"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["link2_nearest_point_local"]){
				rhs->link2_nearest_point_local = node["link2_nearest_point_local"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["link1_transform"]){
				rhs->link1_transform = node["link1_transform"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["link2_transform"]){
				rhs->link2_transform = node["link2_transform"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["normal"]){
				rhs->normal = node["normal"].as<com::robotraconteur::geometry::Vector3>();
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
	struct convert<com::robotraconteur::robotics::planning::InvKinResultPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::InvKinResultPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::InvKinResultPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::InvKinResult);
			if(node["joints"]){
				RobotRaconteur::RRListPtr<RRArray<double>> listy = AllocateEmptyRRList<RRArray<double>>();
				for(int i =0; i<node["joints"].size(); i++) {
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["joints"][i].size());
					for(int k =0; k<node["joints"][i].size(); k++) {
						my_array->at(k)=node["joints"][i][k].as<double>();
					}
					listy->push_back(my_array);
				}
				rhs->joints = listy;
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
	struct convert<com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerAlgorithmInfo);
			if(node["algorithm_identifier"]){
				rhs->algorithm_identifier = node["algorithm_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["algorithm_classes"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::device::DeviceClass> listy = AllocateEmptyRRList<com::robotraconteur::device::DeviceClass>();
				for(int j=0; j< node["algorithm_classes"].size(); j++){
					com::robotraconteur::device::DeviceClassPtr item= node["algorithm_classes"][j].as<com::robotraconteur::device::DeviceClassPtr>();
					listy->push_back(item);
				}
				rhs->algorithm_classes = listy;
			}
			if(node["algorithm_capability_flags"]){
				rhs->algorithm_capability_flags = node["algorithm_capability_flags"].as<uint64_t>();
			}
			if(node["algorithm_capabilities"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::device::DeviceCapability> listy = AllocateEmptyRRList<com::robotraconteur::device::DeviceCapability>();
				for(int j=0; j< node["algorithm_capabilities"].size(); j++){
					com::robotraconteur::device::DeviceCapabilityPtr item= node["algorithm_capabilities"][j].as<com::robotraconteur::device::DeviceCapabilityPtr>();
					listy->push_back(item);
				}
				rhs->algorithm_capabilities = listy;
			}
			if(node["description"]){
				rhs->description = node["description"].as<std::string>();
			}
			if(node["waypoint_constraints"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["waypoint_constraints"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["waypoint_constraints"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->waypoint_constraints = listy;
			}
			if(node["waypoint_extended"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["waypoint_extended"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["waypoint_extended"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->waypoint_extended = listy;
			}
			if(node["algorithm_specific"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["algorithm_specific"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["algorithm_specific"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->algorithm_specific = listy;
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
	struct convert<com::robotraconteur::robotics::planning::PlannerInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["global_parameter_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["global_parameter_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["global_parameter_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->global_parameter_info = listy;
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
	struct convert<com::robotraconteur::robotics::planning::PlanningSceneInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningSceneInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningSceneInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningSceneInfo);
			if(node["scene_identifier"]){
				rhs->scene_identifier = node["scene_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["description"]){
				rhs->description = node["description"].as<std::string>();
			}
			if(node["scene_capabilities"]){
				rhs->scene_capabilities = node["scene_capabilities"].as<uint64_t>();
			}
			if(node["scene_parameter_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["scene_parameter_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["scene_parameter_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->scene_parameter_info = listy;
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
	struct convert<com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerModelJointPositions);
			if(node["joint_position"]){
				RR::RRMapPtr<std::string, RR::RRArray<double>> joints;
				for (YAML::const_iterator it = node["joint_position"].begin(); it != node["joint_position"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[name].size());
					for (int i = 0; i < node[name].size(); i++) {
						my_array->at(i) = node[name][i].as<double>();
					}
					joints->insert(std::make_pair(name,my_array));
				}
				rhs->joint_position = joints;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlannerJointPositionsPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerJointPositionsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerJointPositionsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerJointPositions);
			if(node["joint_position"]){
				RR::RRMapPtr<std::string, RR::RRArray<double>> joints;
				for (YAML::const_iterator it = node["joint_position"].begin(); it != node["joint_position"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node[name].size());
					for (int i = 0; i < node[name].size(); i++) {
						my_array->at(i) = node[name][i].as<double>();
					}
					joints->insert(std::make_pair(name,my_array));
				}
				rhs->joint_position = joints;
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
	struct convert<com::robotraconteur::robotics::planning::EnvStatePtr>{
		static Node encode(const com::robotraconteur::robotics::planning::EnvStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::EnvStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::EnvState);
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
	struct convert<com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::AllowedCollisionEntry);
			if(node["model_identifier1"]){
				rhs->model_identifier1 = node["model_identifier1"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["link_identifier1"]){
				rhs->link_identifier1 = node["link_identifier1"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["model_identifier2"]){
				rhs->model_identifier2 = node["model_identifier2"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["link_identifier2"]){
				rhs->link_identifier2 = node["link_identifier2"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["reason"]){
				rhs->reason = node["reason"].as<std::string>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::AllowedCollisionMatrix);
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::robotics::planning::PlannerJointPositions 
// com::robotraconteur::robotics::planning::EnvState 

}