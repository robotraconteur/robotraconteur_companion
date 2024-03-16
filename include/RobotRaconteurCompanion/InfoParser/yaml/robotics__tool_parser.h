#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::robotics::tool::ToolInfoPtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->tool_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode>(node,"tool_type",true);
			rhs->tool_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_flags<com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities>(node,"tool_capabilities",true);
			rhs->tcp = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Transform>(node,"tcp",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
			rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
			rhs->actuation_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"actuation_time",true);
			rhs->close_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"close_position",true);
			rhs->open_position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"open_position",true);
			rhs->command_min = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_min",true);
			rhs->command_max = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_max",true);
			rhs->command_close = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_close",true);
			rhs->command_open = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command_open",true);
			rhs->sensor_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum_list<com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode>(node,"sensor_type",true);
			rhs->sensor_min = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_min",true,true,0);
			rhs->sensor_max = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_max",true,true,0);
			rhs->sensor_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"sensor_units",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::tool::ToolStatePtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolState); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->ts = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::datetime::TimeSpec3>(node,"ts",true);
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->tool_state_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"tool_state_flags",true);
			rhs->position = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"position",true);
			rhs->command = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"command",true);
			rhs->sensor = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::robotics::tool::ToolStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::robotics::tool::ToolStateSensorData); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->robot_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::robotics::tool::ToolStatePtr>(node,"robot_state",true);
			return true;
		}
	};



}