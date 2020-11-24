#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::resource::ResourceIdentifierPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourceIdentifierPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceIdentifier);
			rhs->bucket = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"bucket",true);
			rhs->key = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"key",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::BucketInfoPtr>{
		static Node encode(const com::robotraconteur::resource::BucketInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::BucketInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::BucketInfo);
			rhs->identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"identifier",true);
			rhs->keys = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"keys",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::ResourceInfoPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourceInfo);
			rhs->identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"identifier",true);
			rhs->key = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"key",true);
			// TODO: parse field com.robotraconteur.datetime.DateTimeUTC created
			// TODO: parse field com.robotraconteur.datetime.DateTimeUTC modified
			rhs->total_size = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"total_size",true);
			rhs->description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"description",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::ResourcePtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::Resource);
			rhs->info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceInfoPtr>(node,"info",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::resource::ResourcePartPtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::resource::ResourcePart);
			rhs->info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceInfoPtr>(node,"info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint64_t>(node,"data_offset",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



}