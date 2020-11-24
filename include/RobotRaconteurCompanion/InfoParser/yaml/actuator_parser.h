#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::actuator::ActuatorInfoPtr>{
		static Node encode(const com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::actuator::ActuatorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::actuator::ActuatorInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->actuator_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode>(node,"actuator_type",true);
			rhs->command_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"command_units",true);
			rhs->command_data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"command_data_type",true);
			rhs->command_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"command_resolution",true,true,0);
			rhs->analog_output = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"analog_output",true);
			rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}