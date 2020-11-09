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
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionTemplate);
			if(node["object_identifier"]){
				rhs->object_identifier = node["object_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["object_class"]){
				rhs->object_class = node["object_class"].as<com::robotraconteur::device::DeviceClassPtr>();
			}
			if(node["object_shape"]){
				rhs->object_shape = node["object_shape"].as<com::robotraconteur::geometry::shapes::ShapeObjectPtr>();
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
	struct convert<com::robotraconteur::objectrecognition::RecognizedObjectPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObject);
			if(node["recognized_object"]){
				rhs->recognized_object = node["recognized_object"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["recognized_object_class"]){
				rhs->recognized_object_class = node["recognized_object_class"].as<com::robotraconteur::device::DeviceClassPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>();
			}
			if(node["confidence"]){
				rhs->confidence = node["confidence"].as<double>();
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
	struct convert<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObjects);
			if(node["source_data"]){
				std::string type = node["source_data"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["source_data"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["source_data"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["source_data"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["source_data"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["source_data"]["value"].size());
					for (int i = 0; i < node["source_data"]["value"].size(); i++) {
						my_array->at(i) = node["source_data"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["source_data"]["value"].size());
					for (int i = 0; i < node["source_data"]["value"].size(); i++) {
						my_array->at(i) = node["source_data"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["source_data"]["value"].size());
					for (int i = 0; i < node["source_data"]["value"].size(); i++) {
						my_array->at(i) = node["source_data"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->source_data=varval;
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
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["range_min"]){
				rhs->range_min = node["range_min"].as<com::robotraconteur::geometry::Point>();
			}
			if(node["range_max"]){
				rhs->range_max = node["range_max"].as<com::robotraconteur::geometry::Point>();
			}
			if(node["resolution"]){
				rhs->resolution = node["resolution"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["param_info"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::param::ParameterInfo> listy = AllocateEmptyRRList<com::robotraconteur::param::ParameterInfo>();
				for(int j=0; j< node["param_info"].size(); j++){
					com::robotraconteur::param::ParameterInfoPtr item= node["param_info"][j].as<com::robotraconteur::param::ParameterInfoPtr>();
					listy->push_back(item);
				}
				rhs->param_info = listy;
			}
			if(node["object_template_identifiers"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::identifier::Identifier> listy = AllocateEmptyRRList<com::robotraconteur::identifier::Identifier>();
				for(int j=0; j< node["object_template_identifiers"].size(); j++){
					com::robotraconteur::identifier::IdentifierPtr item= node["object_template_identifiers"][j].as<com::robotraconteur::identifier::IdentifierPtr>();
					listy->push_back(item);
				}
				rhs->object_template_identifiers = listy;
			}
			if(node["object_template_classes"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::device::DeviceClass> listy = AllocateEmptyRRList<com::robotraconteur::device::DeviceClass>();
				for(int j=0; j< node["object_template_classes"].size(); j++){
					com::robotraconteur::device::DeviceClassPtr item= node["object_template_classes"][j].as<com::robotraconteur::device::DeviceClassPtr>();
					listy->push_back(item);
				}
				rhs->object_template_classes = listy;
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
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorData);
			if(node["sensor_data"]){
				rhs->sensor_data = node["sensor_data"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::objectrecognition::ObjectRecognitionSensorData 

}