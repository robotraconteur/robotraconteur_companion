#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfo);
			rhs->k1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k1",true);
			rhs->k2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k2",true);
			rhs->p1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p1",true);
			rhs->p2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"p2",true);
			rhs->k3 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"k3",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraCalibration);
			rhs->image_size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"image_size",true);
			rhs->distortion_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>(node,"distortion_info",true);
			rhs->K = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"K",true,3,3);
			rhs->parent_device = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_device",true);
			rhs->camera_pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"camera_pose",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::CameraInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->calibration = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>(node,"calibration",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr>{
		static Node encode(const com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imaging::camerainfo::MultiCameraInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->camera_info_all = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_map_int32<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>(node,"camera_info_all",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}