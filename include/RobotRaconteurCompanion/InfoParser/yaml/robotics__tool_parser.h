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
	struct convert<com::robotraconteur::robotics::tool::ToolInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["tool_type"]){
				std::string enum_val_string= node["tool_type"].as<std::string>();
				rhs->tool_type = com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_ToolTypeCode(enum_val_string));
			}
			if(node["tool_capabilities"]){
				rhs->tool_capabilities = node["tool_capabilities"].as<uint32_t>();
			}
			if(node["tcp"]){
				rhs->tcp = node["tcp"].as<com::robotraconteur::geometry::Transform>();
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometry::SpatialInertia>();
			}
			if(node["actuation_time"]){
				rhs->actuation_time = node["actuation_time"].as<double>();
			}
			if(node["close_position"]){
				rhs->close_position = node["close_position"].as<double>();
			}
			if(node["open_position"]){
				rhs->open_position = node["open_position"].as<double>();
			}
			if(node["command_min"]){
				rhs->command_min = node["command_min"].as<double>();
			}
			if(node["command_max"]){
				rhs->command_max = node["command_max"].as<double>();
			}
			if(node["command_close"]){
				rhs->command_close = node["command_close"].as<double>();
			}
			if(node["command_open"]){
				rhs->command_open = node["command_open"].as<double>();
			}
			if(node["sensor_min"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["sensor_min"].size());
				for (int i = 0; i < node["sensor_min"].size(); i++) {
					my_array->at(i) = node["sensor_min"][i].as<double>();
				}
				rhs->sensor_min = my_array;
			}
			if(node["sensor_max"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["sensor_max"].size());
				for (int i = 0; i < node["sensor_max"].size(); i++) {
					my_array->at(i) = node["sensor_max"][i].as<double>();
				}
				rhs->sensor_max = my_array;
			}
			if(node["sensor_units"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::units::SIUnit> listy = AllocateEmptyRRList<com::robotraconteur::units::SIUnit>();
				for(int j=0; j< node["sensor_units"].size(); j++){
					com::robotraconteur::units::SIUnitPtr item= node["sensor_units"][j].as<com::robotraconteur::units::SIUnitPtr>();
					listy->push_back(item);
				}
				rhs->sensor_units = listy;
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
	struct convert<com::robotraconteur::robotics::tool::ToolStatePtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolState);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			if(node["tool_state_flags"]){
				rhs->tool_state_flags = node["tool_state_flags"].as<uint32_t>();
			}
			if(node["position"]){
				rhs->position = node["position"].as<double>();
			}
			if(node["command"]){
				rhs->command = node["command"].as<double>();
			}
			if(node["sensor"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["sensor"].size());
				for (int i = 0; i < node["sensor"].size(); i++) {
					my_array->at(i) = node["sensor"][i].as<double>();
				}
				rhs->sensor = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::tool::ToolStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolStateSensorData);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::robotics::tool::ToolStateSensorData 

}