#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometry::Vector2>{
		static Node encode(const com::robotraconteur::geometry::Vector2& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Vector2& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Vector3>{
		static Node encode(const com::robotraconteur::geometry::Vector3& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Vector3& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Vector6>{
		static Node encode(const com::robotraconteur::geometry::Vector6& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Vector6& rhs){
			rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"alpha",false);
			rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"beta",false);
			rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"gamma",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Point2D>{
		static Node encode(const com::robotraconteur::geometry::Point2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Point2D& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Point>{
		static Node encode(const com::robotraconteur::geometry::Point& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Point& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Size2D>{
		static Node encode(const com::robotraconteur::geometry::Size2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Size2D& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Size>{
		static Node encode(const com::robotraconteur::geometry::Size& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Size& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",false);
			rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"depth",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Rect>{
		static Node encode(const com::robotraconteur::geometry::Rect& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Rect& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Box>{
		static Node encode(const com::robotraconteur::geometry::Box& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Box& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Quaternion>{
		static Node encode(const com::robotraconteur::geometry::Quaternion& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Quaternion& rhs){
			rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"w",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Plane>{
		static Node encode(const com::robotraconteur::geometry::Plane& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Plane& rhs){
			rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"normal",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Transform>{
		static Node encode(const com::robotraconteur::geometry::Transform& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Transform& rhs){
			rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Quaternion>(node,"rotation",false);
			rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"translation",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Pose>{
		static Node encode(const com::robotraconteur::geometry::Pose& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Pose& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Quaternion>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Pose2D>{
		static Node encode(const com::robotraconteur::geometry::Pose2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Pose2D& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point2D>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometry::SpatialVelocity& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialVelocity& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometry::SpatialAcceleration& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialAcceleration& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::Wrench>{
		static Node encode(const com::robotraconteur::geometry::Wrench& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Wrench& rhs){
			rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"torque",false);
			rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"force",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometry::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometry::SpatialInertia& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialInertia& rhs){
			rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"m",false);
			rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"com",false);
			rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixx",false);
			rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixy",false);
			rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"ixz",false);
			rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"iyy",false);
			rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"iyz",false);
			rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"izz",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometry::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedTransformPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedTransformPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedTransform);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
			rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Transform>(node,"transform",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPosePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPosePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPose);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometry::PoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::PoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::PoseWithCovariance);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPoseWithCovariance);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPose2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPose2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedPose2D);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Pose2D>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialVelocity);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialVelocity>(node,"velocity",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialAcceleration);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialAcceleration>(node,"acceleration",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedWrenchPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedWrenchPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedWrench);
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Wrench>(node,"wrench",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::NamedSpatialInertia);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometry::BoundingBox2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::BoundingBox2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::BoundingBox2D);
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPose2DPtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size2D>(node,"size",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometry::BoundingBoxPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::BoundingBoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::BoundingBox);
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::NamedPosePtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Size>(node,"size",true);
			return true;
		}
	};



}