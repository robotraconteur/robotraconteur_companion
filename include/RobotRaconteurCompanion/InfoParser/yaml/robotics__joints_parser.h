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
	struct convert<com::robotraconteur::robotics::joints::JointLimitsPtr>{
		static Node encode(const com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointLimits);
			if(node["lower"]){
				rhs->lower = node["lower"].as<double>();
			}
			if(node["upper"]){
				rhs->upper = node["upper"].as<double>();
			}
			if(node["home"]){
				rhs->home = node["home"].as<double>();
			}
			if(node["velocity"]){
				rhs->velocity = node["velocity"].as<double>();
			}
			if(node["acceleration"]){
				rhs->acceleration = node["acceleration"].as<double>();
			}
			if(node["jerk"]){
				rhs->jerk = node["jerk"].as<double>();
			}
			if(node["effort"]){
				rhs->effort = node["effort"].as<double>();
			}
			if(node["reduced_velocity"]){
				rhs->reduced_velocity = node["reduced_velocity"].as<double>();
			}
			if(node["reduced_acceleration"]){
				rhs->reduced_acceleration = node["reduced_acceleration"].as<double>();
			}
			if(node["reduced_jerk"]){
				rhs->reduced_jerk = node["reduced_jerk"].as<double>();
			}
			if(node["reduced_effort"]){
				rhs->reduced_effort = node["reduced_effort"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::joints::JointInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointInfo);
			if(node["joint_identifier"]){
				rhs->joint_identifier = node["joint_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["joint_type"]){
				std::string enum_val_string= node["joint_type"].as<std::string>();
				rhs->joint_type = com::robotraconteur::robotics::joints::JointType::JointType(string_to_enum_JointType(enum_val_string));
			}
			if(node["default_units"]){
				std::string enum_val_string= node["default_units"].as<std::string>();
				rhs->default_units = com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits(string_to_enum_JointPositionUnits(enum_val_string));
			}
			if(node["default_effort_units"]){
				std::string enum_val_string= node["default_effort_units"].as<std::string>();
				rhs->default_effort_units = com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits(string_to_enum_JointEffortUnits(enum_val_string));
			}
			if(node["passive"]){
				rhs->passive = node["passive"].as<bool>();
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


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::robotics::joints::JointInfo 

}