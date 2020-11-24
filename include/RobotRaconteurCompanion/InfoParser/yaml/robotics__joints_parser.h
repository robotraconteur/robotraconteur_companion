#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::joints::JointLimitsPtr>{
		static Node encode(const com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointLimitsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointLimits);
			rhs->lower = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"lower",true);
			rhs->upper = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"upper",true);
			rhs->home = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"home",true);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"velocity",true);
			rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"acceleration",true);
			rhs->jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"jerk",true);
			rhs->effort = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"effort",true);
			rhs->reduced_velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_velocity",true);
			rhs->reduced_acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_acceleration",true);
			rhs->reduced_jerk = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_jerk",true);
			rhs->reduced_effort = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"reduced_effort",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::joints::JointInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::joints::JointInfo);
			rhs->joint_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"joint_identifier",true);
			rhs->joint_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointType::JointType>(node,"joint_type",true);
			rhs->joint_limits = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::joints::JointLimitsPtr>(node,"joint_limits",true);
			rhs->default_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"default_units",true);
			rhs->default_effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"default_effort_units",true);
			rhs->passive = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"passive",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}