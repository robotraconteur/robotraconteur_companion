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
	struct convert<com::robotraconteur::param::ParameterInfoPtr>{
		static Node encode(const com::robotraconteur::param::ParameterInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::param::ParameterInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::param::ParameterInfo);
			if(node["parameter_identifier"]){
				rhs->parameter_identifier = node["parameter_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["parameter_class"]){
				rhs->parameter_class = node["parameter_class"].as<com::robotraconteur::device::DeviceClassPtr>();
			}
			if(node["data_type"]){
				rhs->data_type = node["data_type"].as<com::robotraconteur::datatype::DataTypePtr>();
			}
			if(node["user_description"]){
				rhs->user_description = node["user_description"].as<std::string>();
			}
			if(node["default_value"]){
				std::string type = node["default_value"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["default_value"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["default_value"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["default_value"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["default_value"]["value"].as<uint32_t>();
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
				rhs->default_value=varval;
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
				rhs->max_value=varval;
			}
			if(node["enum_values"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["enum_values"].begin(); it != node["enum_values"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["enum_values"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["enum_values"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["enum_values"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["enum_values"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["enum_values"]["value"].as<uint32_t>();
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
				rhs->enum_values = vars;
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



}