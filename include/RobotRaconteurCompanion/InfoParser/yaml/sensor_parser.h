#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::sensor::SensorInfoPtr>{
		static Node encode(const com::robotraconteur::sensor::SensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensor::SensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->sensor_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode>(node,"sensor_type",true);
			rhs->units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"units",true);
			rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
			rhs->sensor_resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"sensor_resolution",true,true,0);
			rhs->analog_sensor = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"analog_sensor",true);
			rhs->update_frequency = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"update_frequency",true);
			rhs->parameter_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"parameter_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::sensor::SensorDataPtr>{
		static Node encode(const com::robotraconteur::sensor::SensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensor::SensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensor::SensorData);
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->data_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_flags",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<double>(node,"data",true,true,0);
			rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
			rhs->data_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"data_units",true);
			// TODO: parse field varvalue{string} parameters
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}