#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotKinChainInfo);
			rhs->kin_chain_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"kin_chain_identifier",true);
			rhs->H = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"H",true,true,0);
			rhs->P = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"P",true,true,0);
			rhs->link_inertias = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialInertia>(node,"link_inertias",true,true,0);
			rhs->link_identifiers = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::identifier::IdentifierPtr>(node,"link_identifiers",true);
			rhs->link_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"link_fiducials",true);
			rhs->joint_numbers = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"joint_numbers",true,true,0);
			rhs->flange_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"flange_pose",true);
			rhs->flange_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"flange_identifier",true);
			rhs->current_tool = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::tool::ToolInfoPtr>(node,"current_tool",true);
			rhs->current_payload = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::payload::PayloadInfoPtr>(node,"current_payload",true);
			rhs->tcp_max_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"tcp_max_velocity",true);
			rhs->tcp_max_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"tcp_max_acceleration",true);
			rhs->tcp_reduced_max_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"tcp_reduced_max_velocity",true);
			rhs->tcp_reduced_max_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"tcp_reduced_max_acceleration",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->robot_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode>(node,"robot_type",true);
			rhs->joint_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::joints::JointInfoPtr>(node,"joint_info",true);
			rhs->chains = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>(node,"chains",true);
			rhs->robot_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities>(node,"robot_capabilities",true);
			rhs->signal_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::signal::SignalInfoPtr>(node,"signal_info",true);
			rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
			rhs->config_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"config_seqno",true);
			rhs->trajectory_interpolation_modes = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"trajectory_interpolation_modes",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotStatePtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotState);
			rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->command_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode>(node,"command_mode",true);
			rhs->operational_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode>(node,"operational_mode",true);
			rhs->controller_state = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState>(node,"controller_state",true);
			rhs->robot_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"robot_state_flags",true);
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
			rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
			rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_effort",true,true,0);
			rhs->joint_position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position_command",true,true,0);
			rhs->joint_velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity_command",true,true,0);
			rhs->kin_chain_tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Pose>(node,"kin_chain_tcp",true,true,0);
			rhs->kin_chain_tcp_vel = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialVelocity>(node,"kin_chain_tcp_vel",true,true,0);
			rhs->trajectory_running = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"trajectory_running",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>{
		static Node encode(const com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::AdvancedRobotState);
			rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->command_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode>(node,"command_mode",true);
			rhs->operational_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode>(node,"operational_mode",true);
			rhs->controller_state = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState>(node,"controller_state",true);
			rhs->robot_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"robot_state_flags",true);
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
			rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
			rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_effort",true,true,0);
			rhs->joint_position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position_command",true,true,0);
			rhs->joint_velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity_command",true,true,0);
			rhs->joint_position_units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"joint_position_units",true,true,0);
			rhs->joint_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"joint_effort_units",true,true,0);
			rhs->kin_chain_tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Pose>(node,"kin_chain_tcp",true,true,0);
			rhs->kin_chain_tcp_vel = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::SpatialVelocity>(node,"kin_chain_tcp_vel",true,true,0);
			rhs->trajectory_running = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"trajectory_running",true);
			rhs->trajectory_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_time",true);
			rhs->trajectory_max_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_max_time",true);
			rhs->trajectory_current_waypoint = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"trajectory_current_waypoint",true);
			rhs->config_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"config_seqno",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotStateSensorData);
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->robot_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>(node,"robot_state",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::robot::RobotJointCommandPtr>{
		static Node encode(const com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::robot::RobotJointCommand);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->state_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"state_seqno",true);
			rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command",true,true,0);
			rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"units",true,true,0);
			return true;
		}
	};



}