#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_position",true,true,0);
			rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"joint_velocity",true,true,0);
			rhs->position_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_tolerance",true,true,0);
			rhs->velocity_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_tolerance",true,true,0);
			rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"interpolation_mode",true);
			rhs->waypoint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType>(node,"waypoint_type",true);
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::JointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
			rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"joint_units",true);
			rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>(node,"waypoints",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::TrajectoryStatus); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->action_status = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::action::ActionStatusCode::ActionStatusCode>(node,"action_status",true);
			rhs->current_waypoint = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"current_waypoint",true);
			rhs->trajectory_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"trajectory_time",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->joint_position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_position",true,true,0);
			rhs->joint_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_velocity",true,true,0);
			rhs->joint_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_acceleration",true,true,0);
			rhs->joint_jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_jerk",true,true,0);
			rhs->joint_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"joint_effort",true,true,0);
			rhs->position_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"position_tolerance",true,true,0);
			rhs->velocity_tolerance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_list<double>(node,"velocity_tolerance",true,true,0);
			rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>(node,"interpolation_mode",true);
			rhs->waypoint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType>(node,"waypoint_type",true);
			// TODO: parse field varvalue{string} signals
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->joints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>(node,"joints",true);
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevice); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"device",true);
			rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
			rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"joint_units",true);
			rhs->joint_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"joint_effort_units",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::AdvancedJointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->devices = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>(node,"devices",true);
			rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>(node,"waypoints",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypoint); // NOLINT(cppcoreguidelines-owning-memory)
			// TODO: parse field varvalue{list} joint_position
			// TODO: parse field varvalue{list} joint_velocity
			// TODO: parse field varvalue{list} position_tolerance
			// TODO: parse field varvalue{list} velocity_tolerance
			rhs->interpolation_mode = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"interpolation_mode",true);
			// TODO: parse field varvalue{string} signals
			rhs->time_from_start = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"time_from_start",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr>{
		static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::trajectory::FreeformJointTrajectory); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->joint_names = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_names",true);
			rhs->joint_units = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"joint_units",true);
			rhs->waypoints = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>(node,"waypoints",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}