#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::param::ParameterInfoPtr>{
		static Node encode(const com::robotraconteur::param::ParameterInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::param::ParameterInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::param::ParameterInfo);
			rhs->parameter_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parameter_identifier",true);
			rhs->parameter_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"parameter_class",true);
			rhs->data_type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::datatype::DataTypePtr>(node,"data_type",true);
			rhs->data_units = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::units::SIUnitPtr>(node,"data_units",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			// TODO: parse field varvalue default_value
			// TODO: parse field varvalue min_value
			// TODO: parse field varvalue max_value
			// TODO: parse field varvalue{string} enum_values
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}