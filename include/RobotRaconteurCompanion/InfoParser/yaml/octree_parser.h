#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::octree::OcTreeInfoPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeInfo);
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding>(node,"encoding",true);
			rhs->id = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"id",true);
			rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"resolution",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::octree::OcTreePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTree);
			rhs->octree_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::octree::OcTreeInfoPtr>(node,"octree_info",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::octree::OcTreePartPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreePart);
			rhs->octree_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::octree::OcTreeInfoPtr>(node,"octree_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::octree::OcTreeResourcePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeResourcePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeResource);
			rhs->octree_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"octree_resource",true);
			return true;
		}
	};



}