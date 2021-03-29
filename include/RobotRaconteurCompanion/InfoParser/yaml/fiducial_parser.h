#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::fiducial::FiducialPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::Fiducial);
			rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
			rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
			rhs->fiducial_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"fiducial_pose",true);
			rhs->fiducial_scale = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"fiducial_scale",true);
			rhs->foreground_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"foreground_color",true);
			rhs->background_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"background_color",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::fiducial::FiducialInfoPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialInfo);
			rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
			rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
			rhs->fiducial_marker_range = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker_range",true);
			rhs->default_size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"default_size",true);
			rhs->default_foreground_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"default_foreground_color",true);
			rhs->default_background_color = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"default_background_color",true);
			rhs->marker_template = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::CompressedImagePtr>(node,"marker_template",true);
			rhs->marker_template_centroid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"marker_template_centroid",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::fiducial::RecognizedFiducialPtr>{
		static Node encode(const com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::RecognizedFiducial);
			rhs->fiducial_marker_class = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"fiducial_marker_class",true);
			rhs->fiducial_marker = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"fiducial_marker",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>(node,"pose",true);
			rhs->confidence = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"confidence",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::fiducial::RecognizedFiducialsPtr>{
		static Node encode(const com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::RecognizedFiducials);
			rhs->recognized_fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::RecognizedFiducialPtr>(node,"recognized_fiducials",true);
			// TODO: parse field varvalue source_data
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::fiducial::FiducialSensorInfoPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialSensorInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->range = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"range",true);
			rhs->resolution = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"resolution",true);
			rhs->param_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::param::ParameterInfoPtr>(node,"param_info",true);
			rhs->fiducial_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialInfoPtr>(node,"fiducial_info",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::fiducial::FiducialSensorDataPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::fiducial::FiducialSensorData);
			rhs->sensor_data = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"sensor_data",true);
			rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::fiducial::RecognizedFiducialsPtr>(node,"fiducials",true);
			return true;
		}
	};



}