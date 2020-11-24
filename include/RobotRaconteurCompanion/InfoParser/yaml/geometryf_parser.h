#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometryf::Vector2>{
		static Node encode(const com::robotraconteur::geometryf::Vector2& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector2& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Vector3>{
		static Node encode(const com::robotraconteur::geometryf::Vector3& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector3& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Vector6>{
		static Node encode(const com::robotraconteur::geometryf::Vector6& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector6& rhs){
			rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"alpha",false);
			rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"beta",false);
			rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"gamma",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Point2D>{
		static Node encode(const com::robotraconteur::geometryf::Point2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Point2D& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Point>{
		static Node encode(const com::robotraconteur::geometryf::Point& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Point& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Size2D>{
		static Node encode(const com::robotraconteur::geometryf::Size2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Size2D& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"height",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Size>{
		static Node encode(const com::robotraconteur::geometryf::Size& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Size& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"height",false);
			rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"depth",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Rect>{
		static Node encode(const com::robotraconteur::geometryf::Rect& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Rect& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point2D>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size2D>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Box>{
		static Node encode(const com::robotraconteur::geometryf::Box& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Box& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Quaternion>{
		static Node encode(const com::robotraconteur::geometryf::Quaternion& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Quaternion& rhs){
			rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"w",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Plane>{
		static Node encode(const com::robotraconteur::geometryf::Plane& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Plane& rhs){
			rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"normal",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Transform>{
		static Node encode(const com::robotraconteur::geometryf::Transform& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Transform& rhs){
			rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Quaternion>(node,"rotation",false);
			rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"translation",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Pose>{
		static Node encode(const com::robotraconteur::geometryf::Pose& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Pose& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Quaternion>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Pose2D>{
		static Node encode(const com::robotraconteur::geometryf::Pose2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Pose2D& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point2D>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometryf::SpatialVelocity& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialVelocity& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometryf::SpatialAcceleration& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialAcceleration& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::Wrench>{
		static Node encode(const com::robotraconteur::geometryf::Wrench& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Wrench& rhs){
			rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"torque",false);
			rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"force",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryf::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometryf::SpatialInertia& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialInertia& rhs){
			rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"m",false);
			rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"com",false);
			rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixx",false);
			rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixy",false);
			rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"ixz",false);
			rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"iyy",false);
			rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"iyz",false);
			rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"izz",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometryf::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedTransformPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedTransformPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedTransform);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
			rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Transform>(node,"transform",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPosePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPosePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPose);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::PoseWithCovariance);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<float>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPoseWithCovariance);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPosePtr>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<float>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPose2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPose2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedPose2D);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Pose2D>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialVelocity);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialVelocity>(node,"velocity",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialAcceleration);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->Acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialAcceleration>(node,"Acceleration",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedWrenchPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedWrenchPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedWrench);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Wrench>(node,"wrench",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::NamedSpatialInertia);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::SpatialInertia>(node,"inertia",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometryf::BoundingBox2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::BoundingBox2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::BoundingBox2D);
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPose2DPtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size2D>(node,"size",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryf::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometryf::BoundingBoxPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::BoundingBoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryf::BoundingBox);
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::NamedPosePtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Size>(node,"size",true);
			return true;
		}
	};



}