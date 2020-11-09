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
	struct convert<com::robotraconteur::resource::ResourceIdentifierPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceIdentifier);
			if(node["bucket"]){
				rhs->bucket = node["bucket"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["key"]){
				rhs->key = node["key"].as<std::string>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::BucketInfoPtr>{
		static Node encode(const com::robotraconteur::resource::BucketInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::BucketInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::BucketInfo);
			if(node["identifier"]){
				rhs->identifier = node["identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["keys"]){
				RobotRaconteur::RRListPtr<RRArray<char>> listy = AllocateEmptyRRList<RRArray<char>>();
				for(int j=0; j< node["keys"].size(); j++){
					std::string item= node["keys"][j].as<std::string>();
					RRArrayPtr<char> itemRR= RR::stringToRRArray(item);
					listy->push_back(itemRR);
				}
				rhs->keys = listy;
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
	struct convert<com::robotraconteur::resource::ResourceInfoPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceInfo);
			if(node["key"]){
				rhs->key = node["key"].as<std::string>();
			}
			if(node["total_size"]){
				rhs->total_size = node["total_size"].as<uint64_t>();
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
	struct convert<com::robotraconteur::resource::ResourcePtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::Resource);
			if(node["data"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data"].size());
				for (int i = 0; i < node["data"].size(); i++) {
					my_array->at(i) = node["data"][i].as<uint8_t>();
				}
				rhs->data = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::ResourcePartPtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourcePart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint64_t>();
			}
			if(node["data"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data"].size());
				for (int i = 0; i < node["data"].size(); i++) {
					my_array->at(i) = node["data"][i].as<uint8_t>();
				}
				rhs->data = my_array;
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::resource::ResourceInfo 
// com::robotraconteur::resource::Resource 
// com::robotraconteur::resource::ResourcePart 

}