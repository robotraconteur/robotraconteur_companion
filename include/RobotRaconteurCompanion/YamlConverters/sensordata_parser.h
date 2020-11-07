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
	struct convert<com::robotraconteur::sensordata::SensorDataHeaderPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataHeader);
			if(node["seqno"]){
				rhs->seqno = node["seqno"].as<uint64_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataSourceInfo);
			if(node["source"]){
				rhs->source = node["source"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["source_world_pose"]){
				rhs->source_world_pose = node["source_world_pose"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["source_config_nonce"]){
				rhs->source_config_nonce = node["source_config_nonce"].as<std::string>();
			}
			if(node["source_params"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["source_params"].begin(); it != node["source_params"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["source_params"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["source_params"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["source_params"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["source_params"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["source_params"]["value"].as<uint32_t>();
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
				rhs->source_params = vars;
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


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::sensordata::SensorDataHeader 

}