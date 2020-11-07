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
	struct convert<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfo);
			if(node["k1"]){
				rhs->k1 = node["k1"].as<double>();
			}
			if(node["k2"]){
				rhs->k2 = node["k2"].as<double>();
			}
			if(node["p1"]){
				rhs->p1 = node["p1"].as<double>();
			}
			if(node["p2"]){
				rhs->p2 = node["p2"].as<double>();
			}
			if(node["k3"]){
				rhs->k3 = node["k3"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraCalibration);
			if(node["image_size"]){
				rhs->image_size = node["image_size"].as<com::robotraconteur::geometryi::Size2D>();
			}
			if(node["distortion_info"]){
				std::string type = node["distortion_info"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["distortion_info"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["distortion_info"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["distortion_info"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["distortion_info"]["value"].as<uint32_t>();
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
				rhs->distortion_info=varval;
			}
			if(node["K"]){
				std::vector<uint32_t> dims = {3,3};
				RRMultiDimArrayPtr<double> my_multidimarray = AllocateEmptyRRMultiDimArray<double>(dims);
				for(int i =0; i< 3; i++){
					for(int j=0; j< 3; j++){
						my_multidimarray->Array->at(i+(j * 3)) = node["K"][j+ (i * 3)].as<double>();
					}
				}
				rhs->K = my_multidimarray;
			}
			if(node["parent_device"]){
				rhs->parent_device = node["parent_device"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["camera_pose"]){
				rhs->camera_pose = node["camera_pose"].as<com::robotraconteur::geometry::NamedPosePtr>();
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
	struct convert<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
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
	struct convert<com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::MultiCameraInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
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
// com::robotraconteur::imaging::camerainfo::CameraInfo 

}