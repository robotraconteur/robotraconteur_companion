#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::sensordata::SensorDataHeaderPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataHeader);
			// TODO: parse field com.robotraconteur.datetime.TimeSpec2 ts
			rhs->seqno = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"seqno",true);
			rhs->source_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>(node,"source_info",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::sensordata::SensorDataSourceInfo);
			rhs->source = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"source",true);
			rhs->source_world_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"source_world_pose",true);
			rhs->source_config_nonce = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_config_nonce",true);
			// TODO: parse field varvalue{string} source_params
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}