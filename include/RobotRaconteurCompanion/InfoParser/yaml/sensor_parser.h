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
	struct convert<com::robotraconteur::sensor::SensorInfoPtr>{
		static Node encode(const com::robotraconteur::sensor::SensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensor::SensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["sensor_type"]){
				std::string enum_val_string= node["sensor_type"].as<std::string>();
				rhs->sensor_type = com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_SensorTypeCode(enum_val_string));
			}
			if(node["units"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::units::SIUnit> listy = AllocateEmptyRRList<com::robotraconteur::units::SIUnit>();
				for(int j=0; j< node["units"].size(); j++){
					com::robotraconteur::units::SIUnitPtr item= node["units"][j].as<com::robotraconteur::units::SIUnitPtr>();
					listy->push_back(item);
				}
				rhs->units = listy;
			}
			if(node["data_type"]){
				rhs->data_type = node["data_type"].as<com::robotraconteur::datatype::DataTypePtr>();
			}
			if(node["sensor_resolution"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["sensor_resolution"].size());
				for (int i = 0; i < node["sensor_resolution"].size(); i++) {
					my_array->at(i) = node["sensor_resolution"][i].as<double>();
				}
				rhs->sensor_resolution = my_array;
			}
			if(node["analog_sensor"]){
				rhs->analog_sensor = node["analog_sensor"].as<bool>();
			}
			if(node["update_frequency"]){
				rhs->update_frequency = node["update_frequency"].as<double>();
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



	template<> 
	struct convert<com::robotraconteur::sensor::SensorDataPtr>{
		static Node encode(const com::robotraconteur::sensor::SensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensor::SensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorData);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			if(node["data"]){
				RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["data"].size());
				for (int i = 0; i < node["data"].size(); i++) {
					my_array->at(i) = node["data"][i].as<double>();
				}
				rhs->data = my_array;
			}
			if(node["data_type"]){
				rhs->data_type = node["data_type"].as<com::robotraconteur::datatype::DataTypePtr>();
			}
			if(node["data_units"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::units::SIUnit> listy = AllocateEmptyRRList<com::robotraconteur::units::SIUnit>();
				for(int j=0; j< node["data_units"].size(); j++){
					com::robotraconteur::units::SIUnitPtr item= node["data_units"][j].as<com::robotraconteur::units::SIUnitPtr>();
					listy->push_back(item);
				}
				rhs->data_units = listy;
			}
			if(node["parameters"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["parameters"].begin(); it != node["parameters"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["parameters"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["parameters"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["parameters"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["parameters"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["parameters"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["parameters"]["value"].size());
						for (int i = 0; i < node["parameters"]["value"].size(); i++) {
							my_array->at(i) = node["parameters"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["parameters"]["value"].size());
						for (int i = 0; i < node["parameters"]["value"].size(); i++) {
							my_array->at(i) = node["parameters"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["parameters"]["value"].size());
						for (int i = 0; i < node["parameters"]["value"].size(); i++) {
							my_array->at(i) = node["parameters"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->parameters = vars;
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