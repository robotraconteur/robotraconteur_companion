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
	struct convert<com::robotraconteur::signal::SignalInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::signal::SignalInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalInfo);
			if(node["signal_identifier"]){
				rhs->signal_identifier = node["signal_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["signal_class"]){
				rhs->signal_class = node["signal_class"].as<com::robotraconteur::device::DeviceClassPtr>();
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
			if(node["signal_type"]){
				std::string enum_val_string= node["signal_type"].as<std::string>();
				rhs->signal_type = com::robotraconteur::signal::SignalType::SignalType(string_to_enum_SignalType(enum_val_string));
			}
			if(node["access_level"]){
				std::string enum_val_string= node["access_level"].as<std::string>();
				rhs->access_level = com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel(string_to_enum_SignalAccessLevel(enum_val_string));
			}
			if(node["address"]){
				RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["address"].size());
				for (int i = 0; i < node["address"].size(); i++) {
					my_array->at(i) = node["address"][i].as<uint32_t>();
				}
				rhs->address = my_array;
			}
			if(node["user_description"]){
				rhs->user_description = node["user_description"].as<std::string>();
			}
			if(node["min_value"]){
				std::string type = node["min_value"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["min_value"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["min_value"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["min_value"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["min_value"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["min_value"]["value"].size());
					for (int i = 0; i < node["min_value"]["value"].size(); i++) {
						my_array->at(i) = node["min_value"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["min_value"]["value"].size());
					for (int i = 0; i < node["min_value"]["value"].size(); i++) {
						my_array->at(i) = node["min_value"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["min_value"]["value"].size());
					for (int i = 0; i < node["min_value"]["value"].size(); i++) {
						my_array->at(i) = node["min_value"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->min_value=varval;
			}
			if(node["max_value"]){
				std::string type = node["max_value"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["max_value"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["max_value"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["max_value"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["max_value"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["max_value"]["value"].size());
					for (int i = 0; i < node["max_value"]["value"].size(); i++) {
						my_array->at(i) = node["max_value"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["max_value"]["value"].size());
					for (int i = 0; i < node["max_value"]["value"].size(); i++) {
						my_array->at(i) = node["max_value"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["max_value"]["value"].size());
					for (int i = 0; i < node["max_value"]["value"].size(); i++) {
						my_array->at(i) = node["max_value"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->max_value=varval;
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
	struct convert<com::robotraconteur::signal::SignalGroupInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::signal::SignalGroupInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::signal::SignalGroupInfo);
			if(node["signal_group_identifier"]){
				rhs->signal_group_identifier = node["signal_group_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["description"]){
				rhs->description = node["description"].as<std::string>();
			}
			return true;
		}
	};



}