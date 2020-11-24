#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogTypePtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogTypePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogTypePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogType);
			rhs->event_category = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"event_category",true);
			rhs->event_type = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"event_type",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessageHeader);
			rhs->type = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::eventlog::EventLogTypePtr>(node,"type",true);
			rhs->level = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::eventlog::EventLogLevel::EventLogLevel>(node,"level",true);
			rhs->source_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"source_device",true);
			rhs->source_component = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_component",true);
			rhs->source_object = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"source_object",true);
			rhs->message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"message_number",true);
			// TODO: parse field com.robotraconteur.datetime.DateTimeUTC timestamp
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogMessagePtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogMessage);
			rhs->header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>(node,"header",true);
			rhs->title = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"title",true);
			rhs->message = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"message",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::eventlog::EventLogInfoPtr>{
		static Node encode(const com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::eventlog::EventLogInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->logged_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"logged_device",true);
			rhs->min_message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"min_message_number",true);
			rhs->max_message_number = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"max_message_number",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}