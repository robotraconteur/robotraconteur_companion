#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Vector2>{
		static Node encode(const com::robotraconteur::geometryf::Vector2& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector2& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Vector3>{
		static Node encode(const com::robotraconteur::geometryf::Vector3& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector3& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Vector6>{
		static Node encode(const com::robotraconteur::geometryf::Vector6& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector6& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Point2D>{
		static Node encode(const com::robotraconteur::geometryf::Point2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Point2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Point>{
		static Node encode(const com::robotraconteur::geometryf::Point& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Point& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Size2D>{
		static Node encode(const com::robotraconteur::geometryf::Size2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Size2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Size>{
		static Node encode(const com::robotraconteur::geometryf::Size& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Size& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Rect>{
		static Node encode(const com::robotraconteur::geometryf::Rect& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Rect& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Box>{
		static Node encode(const com::robotraconteur::geometryf::Box& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Box& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Quaternion>{
		static Node encode(const com::robotraconteur::geometryf::Quaternion& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Quaternion& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Plane>{
		static Node encode(const com::robotraconteur::geometryf::Plane& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Plane& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Transform>{
		static Node encode(const com::robotraconteur::geometryf::Transform& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Transform& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Pose>{
		static Node encode(const com::robotraconteur::geometryf::Pose& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Pose& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Pose2D>{
		static Node encode(const com::robotraconteur::geometryf::Pose2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Pose2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometryf::SpatialVelocity& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialVelocity& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometryf::SpatialAcceleration& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialAcceleration& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::Wrench>{
		static Node encode(const com::robotraconteur::geometryf::Wrench& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::Wrench& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometryf::SpatialInertia& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::SpatialInertia& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedTransformPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedTransformPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPosePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPosePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::PoseWithCovariancePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPoseWithCovariancePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedPose2DPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedPose2DPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialVelocityPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialAccelerationPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedWrenchPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedWrenchPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::NamedSpatialInertiaPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometryf::BoundingBox2DPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::BoundingBox2DPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryf::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometryf::BoundingBoxPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometryf::BoundingBoxPtr& rhs);
	};


}