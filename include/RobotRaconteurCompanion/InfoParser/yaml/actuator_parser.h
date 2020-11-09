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
	struct convert<com::robotraconteur::actuator::ActuatorInfoPtr>{
		static Node encode(const com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::actuator::ActuatorInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["actuator_type"]){
				std::string enum_val_string= node["actuator_type"].as<std::string>();
				rhs->actuator_type = com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode(string_to_enum_ActuatorTypeCode(enum_val_string));
			}
			if(node["command_units"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::units::SIUnit> listy = AllocateEmptyRRList<com::robotraconteur::units::SIUnit>();
				for(int j=0; j< node["command_units"].size(); j++){
					com::robotraconteur::units::SIUnitPtr item= node["command_units"][j].as<com::robotraconteur::units::SIUnitPtr>();
					listy->push_back(item);
				}
				rhs->command_units = listy;
			}
			if(node["command_data_type"]){
				rhs->command_data_type = node["command_data_type"].as<com::robotraconteur::datatype::DataTypePtr>();
			}
			if(node["command_resolution"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["command_resolution"].size());
				for (int i = 0; i < node["command_resolution"].size(); i++) {
					my_array->at(i) = node["command_resolution"][i].as<double>();
				}
				rhs->command_resolution = my_array;
			}
			if(node["analog_output"]){
				rhs->analog_output = node["analog_output"].as<bool>();
			}
			if(node["parameter_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["parameter_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["parameter_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->parameter_info = listy;
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