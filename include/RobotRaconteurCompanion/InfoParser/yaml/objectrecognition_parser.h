#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionTemplate);
			rhs->object_identifier = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"object_identifier",true);
			rhs->object_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"object_class",true);
			rhs->object_shape = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::shapes::ShapeObjectPtr>(node,"object_shape",true);
			rhs->object_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"object_fiducials",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::objectrecognition::RecognizedObjectPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObject);
			rhs->recognized_object = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"recognized_object",true);
			rhs->recognized_object_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceClassPtr>(node,"recognized_object_class",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>(node,"pose",true);
			rhs->confidence = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"confidence",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::RecognizedObjects);
			rhs->recognized_objects = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::objectrecognition::RecognizedObjectPtr>(node,"recognized_objects",true);
			// TODO: parse field varvalue source_data
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->range = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"range",true);
			rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
			rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
			rhs->object_template_identifiers = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::identifier::IdentifierPtr>(node,"object_template_identifiers",true);
			rhs->object_template_classes = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::device::DeviceClassPtr>(node,"object_template_classes",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::objectrecognition::ObjectRecognitionSensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"sensor_data",true);
			rhs->recognized_objects = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>(node,"recognized_objects",true);
			return true;
		}
	};



}