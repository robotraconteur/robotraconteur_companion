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
	struct convert<com::robotraconteur::eventlog::EventLogTypePtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogTypePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogTypePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogType);
			if(node["event_category"]){
				rhs->event_category = node["event_category"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["event_type"]){
				rhs->event_type = node["event_type"].as<std::string>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessageHeader);
			if(node["level"]){
				std::string enum_val_string= node["level"].as<std::string>();
				rhs->level = com::robotraconteur::eventlog::EventLogLevel::EventLogLevel(string_to_enum_EventLogLevel(enum_val_string));
			}
			if(node["source_device"]){
				rhs->source_device = node["source_device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["source_component"]){
				rhs->source_component = node["source_component"].as<std::string>();
			}
			if(node["source_object"]){
				rhs->source_object = node["source_object"].as<std::string>();
			}
			if(node["message_number"]){
				rhs->message_number = node["message_number"].as<uint64_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogMessagePtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessage);
			if(node["title"]){
				rhs->title = node["title"].as<std::string>();
			}
			if(node["message"]){
				rhs->message = node["message"].as<std::string>();
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



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogInfoPtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogInfo);
			if(node["logged_device"]){
				rhs->logged_device = node["logged_device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["min_message_number"]){
				rhs->min_message_number = node["min_message_number"].as<uint64_t>();
			}
			if(node["max_message_number"]){
				rhs->max_message_number = node["max_message_number"].as<uint64_t>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::eventlog::EventLogMessageHeader 
// com::robotraconteur::eventlog::EventLogMessage 

}