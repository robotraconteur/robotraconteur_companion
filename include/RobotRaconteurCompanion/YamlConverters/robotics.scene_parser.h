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
	struct convert<com::robotraconteur::robotics::scene::JointPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::Joint);
			if(node["joint_info"]){
				rhs->joint_info = node["joint_info"].as<com::robotraconteur::robotics::joints::JointInfoPtr>();
			}
			if(node["axis"]){
				rhs->axis = node["axis"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["child_link_name"]){
				rhs->child_link_name = node["child_link_name"].as<std::string>();
			}
			if(node["parent_link_name"]){
				rhs->parent_link_name = node["parent_link_name"].as<std::string>();
			}
			if(node["parent_to_joint_origin_transform"]){
				rhs->parent_to_joint_origin_transform = node["parent_to_joint_origin_transform"].as<com::robotraconteur::geometry::Pose>();
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
	struct convert<com::robotraconteur::robotics::scene::JointDynamicsPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointDynamicsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointDynamicsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::JointDynamics);
			if(node["damping"]){
				rhs->damping = node["damping"].as<double>();
			}
			if(node["friction"]){
				rhs->friction = node["friction"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::scene::JointSafetyPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointSafetyPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointSafetyPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::JointSafety);
			if(node["soft_upper_limit"]){
				rhs->soft_upper_limit = node["soft_upper_limit"].as<double>();
			}
			if(node["soft_lower_limit"]){
				rhs->soft_lower_limit = node["soft_lower_limit"].as<double>();
			}
			if(node["k_position"]){
				rhs->k_position = node["k_position"].as<double>();
			}
			if(node["k_velocity"]){
				rhs->k_velocity = node["k_velocity"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::scene::JointCalibrationPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointCalibrationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointCalibrationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::JointCalibration);
			if(node["reference_position"]){
				rhs->reference_position = node["reference_position"].as<double>();
			}
			if(node["rising"]){
				rhs->rising = node["rising"].as<double>();
			}
			if(node["falling"]){
				rhs->falling = node["falling"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::scene::JointMimicPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointMimicPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointMimicPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::JointMimic);
			if(node["offset"]){
				rhs->offset = node["offset"].as<double>();
			}
			if(node["multiplier"]){
				rhs->multiplier = node["multiplier"].as<double>();
			}
			if(node["joint_name"]){
				rhs->joint_name = node["joint_name"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::scene::LinkPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::LinkPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::LinkPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::Link);
			if(node["link_identifier"]){
				rhs->link_identifier = node["link_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometry::SpatialInertia>();
			}
			if(node["visual"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::geometry::shapes::ShapeObject> listy = AllocateEmptyRRList<com::robotraconteur::geometry::shapes::ShapeObject>();
				for(int j=0; j< node["visual"].size(); j++){
					com::robotraconteur::geometry::shapes::ShapeObjectPtr item= node["visual"][j].as<com::robotraconteur::geometry::shapes::ShapeObjectPtr>();
					listy->push_back(item);
				}
				rhs->visual = listy;
			}
			if(node["collision"]){
				RobotRaconteur::RRListPtr<com::robotraconteur::geometry::shapes::ShapeObject> listy = AllocateEmptyRRList<com::robotraconteur::geometry::shapes::ShapeObject>();
				for(int j=0; j< node["collision"].size(); j++){
					com::robotraconteur::geometry::shapes::ShapeObjectPtr item= node["collision"][j].as<com::robotraconteur::geometry::shapes::ShapeObjectPtr>();
					listy->push_back(item);
				}
				rhs->collision = listy;
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
	struct convert<com::robotraconteur::robotics::scene::ModelPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::ModelPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::ModelPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::Model);
			if(node["model_identifier"]){
				rhs->model_identifier = node["model_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["parent_identifier"]){
				rhs->parent_identifier = node["parent_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
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
	struct convert<com::robotraconteur::robotics::scene::ScenePtr>{
		static Node encode(const com::robotraconteur::robotics::scene::ScenePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::ScenePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::Scene);
			if(node["scene_identifier"]){
				rhs->scene_identifier = node["scene_identifier"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["revision"]){
				rhs->revision = node["revision"].as<uint64_t>();
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