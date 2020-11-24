#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::scene::JointPtr>{
		static Node encode(const com::robotraconteur::robotics::scene::JointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::scene::JointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::scene::Joint);
			rhs->joint_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::joints::JointInfoPtr>(node,"joint_info",true);
			rhs->axis = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"axis",true);
			rhs->child_link_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"child_link_name",true);
			rhs->parent_link_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"parent_link_name",true);
			rhs->parent_to_joint_origin_transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"parent_to_joint_origin_transform",true);
			// TODO: parse field varvalue{string} extended
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
			rhs->damping = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"damping",true);
			rhs->friction = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"friction",true);
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
			rhs->soft_upper_limit = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"soft_upper_limit",true);
			rhs->soft_lower_limit = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"soft_lower_limit",true);
			rhs->k_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k_position",true);
			rhs->k_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k_velocity",true);
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
			rhs->reference_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reference_position",true);
			rhs->rising = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"rising",true);
			rhs->falling = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"falling",true);
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
			rhs->offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"offset",true);
			rhs->multiplier = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"multiplier",true);
			rhs->joint_name = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"joint_name",true);
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
			rhs->link_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"link_identifier",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
			rhs->visual = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::ShapeObjectPtr>(node,"visual",true);
			rhs->collision = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::ShapeObjectPtr>(node,"collision",true);
			// TODO: parse field varvalue{string} extended
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
			rhs->model_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"model_identifier",true);
			rhs->parent_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_identifier",true);
			rhs->joints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::scene::JointPtr>(node,"joints",true);
			rhs->links = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::scene::LinkPtr>(node,"links",true);
			// TODO: parse field varvalue{string} extended
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
			rhs->scene_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"scene_identifier",true);
			rhs->joints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::scene::JointPtr>(node,"joints",true);
			rhs->links = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::scene::LinkPtr>(node,"links",true);
			rhs->models = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::scene::ModelPtr>(node,"models",true);
			rhs->revision = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"revision",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}