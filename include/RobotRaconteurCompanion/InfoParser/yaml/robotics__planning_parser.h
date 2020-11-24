#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::planning::JointWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::JointWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::JointWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::JointWaypoint);
			rhs->joint_positions = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_positions",true,true,0);
			rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
			rhs->motion_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode>(node,"motion_type",true);
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			// TODO: parse field varvalue{string} constraints
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::CartesianWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::CartesianWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::CartesianWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::CartesianWaypoint);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"pose",true);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"velocity",true);
			rhs->motion_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode>(node,"motion_type",true);
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			// TODO: parse field varvalue{string} constraints
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::OtherWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::OtherWaypointPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::OtherWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::OtherWaypoint);
			rhs->waypoint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"waypoint_type",true);
			// TODO: parse field varvalue{string} waypoint_parameters
			rhs->motion_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::planning::PlannerMotionTypeCode::PlannerMotionTypeCode>(node,"motion_type",true);
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			// TODO: parse field varvalue{string} constraints
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlanningRequestPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningRequestPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningRequestPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningRequest);
			rhs->device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"device",true);
			rhs->planner_algorithm = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"planner_algorithm",true);
			rhs->filter_algorithm = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"filter_algorithm",true);
			rhs->workspace_bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Box>(node,"workspace_bounds",true);
			// TODO: parse field varvalue{list} waypoints
			rhs->tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"tcp",true);
			rhs->collision_check = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"collision_check",true);
			rhs->collision_safety_margin = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"collision_safety_margin",true);
			// TODO: parse field varvalue{string} planner_specific
			// TODO: parse field varvalue{string} filter_specific
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlanningResponsePtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningResponsePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningResponsePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningResponse);
			rhs->status_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::planning::PlannerStatusCode::PlannerStatusCode>(node,"status_code",true);
			rhs->joint_trajectory = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>(node,"joint_trajectory",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::ContactResultPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::ContactResultPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::ContactResultPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::ContactResult);
			rhs->distance = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"distance",true);
			rhs->link1_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"link1_name",true);
			rhs->link2_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"link2_name",true);
			rhs->link1_nearest_point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"link1_nearest_point",true);
			rhs->link2_nearest_point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"link2_nearest_point",true);
			rhs->link1_nearest_point_local = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"link1_nearest_point_local",true);
			rhs->link2_nearest_point_local = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"link2_nearest_point_local",true);
			rhs->link1_transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"link1_transform",true);
			rhs->link2_transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"link2_transform",true);
			rhs->normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"normal",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::InvKinResultPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::InvKinResultPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::InvKinResultPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::InvKinResult);
			rhs->joints = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joints",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerAlgorithmInfo);
			rhs->algorithm_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"algorithm_identifier",true);
			rhs->algorithm_classes = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceClassPtr>(node,"algorithm_classes",true);
			rhs->algorithm_capability_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_planner_algorithm_flags_override(node,"algorithm_capability_flags",true);
			rhs->algorithm_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceCapabilityPtr>(node,"algorithm_capabilities",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			rhs->waypoint_constraints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"waypoint_constraints",true);
			rhs->waypoint_extended = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"waypoint_extended",true);
			rhs->algorithm_specific = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"algorithm_specific",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlannerInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->planner_algorithms = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr>(node,"planner_algorithms",true);
			rhs->planner_filters = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::planning::PlannerAlgorithmInfoPtr>(node,"planner_filters",true);
			rhs->global_parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"global_parameter_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlanningSceneInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlanningSceneInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlanningSceneInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlanningSceneInfo);
			rhs->scene_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"scene_identifier",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			rhs->scene_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"scene_capabilities",true);
			rhs->scene_parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"scene_parameter_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerModelJointPositions);
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_map_string<double>(node,"joint_position",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::PlannerJointPositionsPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::PlannerJointPositionsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::PlannerJointPositionsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::PlannerJointPositions);
			rhs->model_joints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_string<com::robotraconteur::robotics::planning::PlannerModelJointPositionsPtr>(node,"model_joints",true);
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_map_string<double>(node,"joint_position",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::EnvStatePtr>{
		static Node encode(const com::robotraconteur::robotics::planning::EnvStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::EnvStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::EnvState);
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::planning::PlannerJointPositionsPtr>(node,"joint_position",true);
			rhs->link_transforms = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_string<com::robotraconteur::geometry::NamedTransformPtr>(node,"link_transforms",true);
			rhs->joint_transforms = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_string<com::robotraconteur::geometry::NamedTransformPtr>(node,"joint_transforms",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::AllowedCollisionEntry);
			rhs->model_identifier1 = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"model_identifier1",true);
			rhs->link_identifier1 = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"link_identifier1",true);
			rhs->model_identifier2 = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"model_identifier2",true);
			rhs->link_identifier2 = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"link_identifier2",true);
			rhs->reason = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"reason",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr>{
		static Node encode(const com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::planning::AllowedCollisionMatrixPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::planning::AllowedCollisionMatrix);
			rhs->entries = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::planning::AllowedCollisionEntryPtr>(node,"entries",true);
			return true;
		}
	};



}