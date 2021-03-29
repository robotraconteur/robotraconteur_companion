#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::servo::ServoInfoPtr>{
		static Node encode(const com::robotraconteur::servo::ServoInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->servo_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::servo::ServoTypeCode::ServoTypeCode>(node,"servo_type",true);
			rhs->capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::servo::ServoCapabilities::ServoCapabilities>(node,"capabilities",true);
			rhs->axis_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"axis_count",true);
			rhs->position_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>(node,"position_units",true);
			rhs->effort_units = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>(node,"effort_units",true);
			rhs->position_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_min",true,true,0);
			rhs->position_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_max",true,true,0);
			rhs->velocity_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_min",true,true,0);
			rhs->velocity_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_max",true,true,0);
			rhs->acceleration_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration_min",true,true,0);
			rhs->acceleration_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration_max",true,true,0);
			rhs->torque_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"torque_min",true,true,0);
			rhs->torque_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"torque_max",true,true,0);
			rhs->gear_ratio = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"gear_ratio",true,true,0);
			rhs->sensor_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_resolution",true,true,0);
			rhs->effort_command_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort_command_resolution",true,true,0);
			rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
			rhs->signal_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::signal::SignalInfoPtr>(node,"signal_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::servo::ServoStatePtr>{
		static Node encode(const com::robotraconteur::servo::ServoStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoState);
			rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->servo_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"servo_state_flags",true);
			rhs->mode = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::servo::ServoMode::ServoMode>(node,"mode",true);
			rhs->position = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position",true,true,0);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity",true,true,0);
			rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"acceleration",true,true,0);
			rhs->effort = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort",true,true,0);
			rhs->position_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"position_command",true,true,0);
			rhs->velocity_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"velocity_command",true,true,0);
			rhs->effort_command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"effort_command",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::servo::ServoStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoStateSensorData);
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->servo_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::servo::ServoStatePtr>(node,"servo_state",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::servo::ServoCommandPtr>{
		static Node encode(const com::robotraconteur::servo::ServoCommandPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::servo::ServoCommandPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::servo::ServoCommand);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->status_seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"status_seqno",true);
			rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command",true,true,0);
			return true;
		}
	};



}