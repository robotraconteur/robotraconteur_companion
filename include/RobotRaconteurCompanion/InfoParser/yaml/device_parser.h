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
	struct convert<com::robotraconteur::device::DeviceOptionPtr>{
		static Node encode(const com::robotraconteur::device::DeviceOptionPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceOptionPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceOption);
			if(node["option_identifier"]){
				rhs->option_identifier = node["option_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceSubOptionPtr>{
		static Node encode(const com::robotraconteur::device::DeviceSubOptionPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceSubOptionPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubOption);
			if(node["suboption_name"]){
				rhs->suboption_name = node["suboption_name"].as<std::string>();
			}
			if(node["suboption_level"]){
				rhs->suboption_level = node["suboption_level"].as<double>();
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
	struct convert<com::robotraconteur::device::DeviceCapabilityPtr>{
		static Node encode(const com::robotraconteur::device::DeviceCapabilityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceCapabilityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceCapability);
			if(node["capability_identifier"]){
				rhs->capability_identifier = node["capability_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceSubCapabilityPtr>{
		static Node encode(const com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubCapability);
			if(node["subcapability_name"]){
				rhs->subcapability_name = node["subcapability_name"].as<std::string>();
			}
			if(node["subcapability_level"]){
				rhs->subcapability_level = node["subcapability_level"].as<double>();
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
	struct convert<com::robotraconteur::device::DeviceClassPtr>{
		static Node encode(const com::robotraconteur::device::DeviceClassPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceClassPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceClass);
			if(node["class_identifier"]){
				rhs->class_identifier = node["class_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["subclasses"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["subclasses"].size(); j++){
					std::string item= node["subclasses"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->subclasses = listy;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceInfoPtr>{
		static Node encode(const com::robotraconteur::device::DeviceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceInfo);
			if(node["device"]){
				rhs->device = node["device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["parent_device"]){
				rhs->parent_device = node["parent_device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["manufacturer"]){
				rhs->manufacturer = node["manufacturer"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["model"]){
				rhs->model = node["model"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["serial_number"]){
				rhs->serial_number = node["serial_number"].as<std::string>();
			}
			if(node["user_description"]){
				rhs->user_description = node["user_description"].as<std::string>();
			}
			if(node["description_resource"]){
				rhs->description_resource = node["description_resource"].as<com::robotraconteur::resource::ResourceIdentifierPtr>();
			}
			if(node["implemented_types"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["implemented_types"].size(); j++){
					std::string item= node["implemented_types"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->implemented_types = listy;
			}
			if(node["device_origin_pose"]){
				rhs->device_origin_pose = node["device_origin_pose"].as<com::robotraconteur::geometry::NamedPosePtr>();
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