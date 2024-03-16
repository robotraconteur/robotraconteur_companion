#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometryi::Vector2>{
		static Node encode(const com::robotraconteur::geometryi::Vector2& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector2& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Vector3>{
		static Node encode(const com::robotraconteur::geometryi::Vector3& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector3& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Vector6>{
		static Node encode(const com::robotraconteur::geometryi::Vector6& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector6& rhs){
			rhs.s.alpha = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"alpha",false);
			rhs.s.beta = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"beta",false);
			rhs.s.gamma = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"gamma",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Point2D>{
		static Node encode(const com::robotraconteur::geometryi::Point2D& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Point2D& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Point>{
		static Node encode(const com::robotraconteur::geometryi::Point& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Point& rhs){
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Size2D>{
		static Node encode(const com::robotraconteur::geometryi::Size2D& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Size2D& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"height",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Size>{
		static Node encode(const com::robotraconteur::geometryi::Size& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Size& rhs){
			rhs.s.width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"width",false);
			rhs.s.height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"height",false);
			rhs.s.depth = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"depth",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Rect>{
		static Node encode(const com::robotraconteur::geometryi::Rect& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Rect& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point2D>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Box>{
		static Node encode(const com::robotraconteur::geometryi::Box& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Box& rhs){
			rhs.s.origin = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point>(node,"origin",false);
			rhs.s.size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size>(node,"size",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Quaternion>{
		static Node encode(const com::robotraconteur::geometryi::Quaternion& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Quaternion& rhs){
			rhs.s.w = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"w",false);
			rhs.s.x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"x",false);
			rhs.s.y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"y",false);
			rhs.s.z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"z",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Plane>{
		static Node encode(const com::robotraconteur::geometryi::Plane& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Plane& rhs){
			rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"normal",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Transform>{
		static Node encode(const com::robotraconteur::geometryi::Transform& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Transform& rhs){
			rhs.s.rotation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Quaternion>(node,"rotation",false);
			rhs.s.translation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"translation",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Pose>{
		static Node encode(const com::robotraconteur::geometryi::Pose& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Pose& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Quaternion>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Pose2D>{
		static Node encode(const com::robotraconteur::geometryi::Pose2D& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Pose2D& rhs){
			rhs.s.orientation = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"orientation",false);
			rhs.s.position = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Point2D>(node,"position",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometryi::SpatialVelocity& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialVelocity& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometryi::SpatialAcceleration& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialAcceleration& rhs){
			rhs.s.angular = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"angular",false);
			rhs.s.linear = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"linear",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Wrench>{
		static Node encode(const com::robotraconteur::geometryi::Wrench& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Wrench& rhs){
			rhs.s.torque = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"torque",false);
			rhs.s.force = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"force",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometryi::SpatialInertia& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialInertia& rhs){
			rhs.s.m = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"m",false);
			rhs.s.com = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Vector3>(node,"com",false);
			rhs.s.ixx = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixx",false);
			rhs.s.ixy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixy",false);
			rhs.s.ixz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"ixz",false);
			rhs.s.iyy = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"iyy",false);
			rhs.s.iyz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"iyz",false);
			rhs.s.izz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int32_t>(node,"izz",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometryi::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedTransformPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedTransformPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedTransform); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->child_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"child_frame",true);
			rhs->transform = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Transform>(node,"transform",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPosePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPosePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::PoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<int32_t>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPoseWithCovariance); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPosePtr>(node,"pose",true);
			rhs->covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<int32_t>(node,"covariance",true,6,6);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose2D); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->pose = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Pose2D>(node,"pose",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialVelocity); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->velocity = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialVelocity>(node,"velocity",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialAcceleration); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->acceleration = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialAcceleration>(node,"acceleration",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedWrench); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->parent_frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"parent_frame",true);
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->wrench = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Wrench>(node,"wrench",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialInertia); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->frame = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"frame",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::SpatialInertia>(node,"inertia",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox2D); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPose2DPtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size2D>(node,"size",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->center = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryi::NamedPosePtr>(node,"center",true);
			rhs->size = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryi::Size>(node,"size",true);
			return true;
		}
	};



}