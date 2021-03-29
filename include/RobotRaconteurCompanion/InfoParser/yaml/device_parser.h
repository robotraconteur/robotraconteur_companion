#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::device::DeviceOptionPtr>{
		static Node encode(const com::robotraconteur::device::DeviceOptionPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceOptionPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceOption);
			rhs->option_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"option_identifier",true);
			rhs->suboptions = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceSubOptionPtr>(node,"suboptions",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceSubOptionPtr>{
		static Node encode(const com::robotraconteur::device::DeviceSubOptionPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceSubOptionPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubOption);
			rhs->suboption_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"suboption_name",true);
			rhs->suboption_level = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"suboption_level",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceCapabilityPtr>{
		static Node encode(const com::robotraconteur::device::DeviceCapabilityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceCapabilityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceCapability);
			rhs->capability_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"capability_identifier",true);
			rhs->subcapabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceSubCapabilityPtr>(node,"subcapabilities",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceSubCapabilityPtr>{
		static Node encode(const com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceSubCapabilityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceSubCapability);
			rhs->subcapability_name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"subcapability_name",true);
			rhs->subcapability_level = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"subcapability_level",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceClassPtr>{
		static Node encode(const com::robotraconteur::device::DeviceClassPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceClassPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceClass);
			rhs->class_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"class_identifier",true);
			rhs->subclasses = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"subclasses",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::device::DeviceInfoPtr>{
		static Node encode(const com::robotraconteur::device::DeviceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::DeviceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::DeviceInfo);
			rhs->device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"device",true);
			rhs->parent_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_device",true);
			rhs->manufacturer = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"manufacturer",true);
			rhs->model = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"model",true);
			rhs->options = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceOptionPtr>(node,"options",true);
			rhs->capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceCapabilityPtr>(node,"capabilities",true);
			rhs->serial_number = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"serial_number",true);
			rhs->device_classes = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceClassPtr>(node,"device_classes",true);
			rhs->user_description = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"user_description",true);
			rhs->description_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"description_resource",true);
			rhs->implemented_types = RobotRaconteur::Companion::InfoParser::yaml::parse_string_list(node,"implemented_types",true);
			rhs->device_origin_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"device_origin_pose",true);
			rhs->associated_devices = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_string<com::robotraconteur::identifier::IdentifierPtr>(node,"associated_devices",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}