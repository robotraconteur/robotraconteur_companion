#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::datatype::DataTypePtr>{
		static Node encode(const com::robotraconteur::datatype::DataTypePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datatype::DataTypePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datatype::DataType);
			rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"name",true);
			rhs->type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::DataTypeCode::DataTypeCode>(node,"type_code",true);
			rhs->type_string = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"type_string",true);
			rhs->array_type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode>(node,"array_type_code",true);
			rhs->array_var_len = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"array_var_len",true);
			rhs->array_len = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint32_t>(node,"array_len",true,true,0);
			rhs->container_type_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode>(node,"container_type_code",true);
			return true;
		}
	};



}