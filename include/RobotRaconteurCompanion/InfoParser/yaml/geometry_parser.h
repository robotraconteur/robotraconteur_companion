#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Vector2>{
		static Node encode(const com::robotraconteur::geometry::Vector2& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Vector2& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Vector3>{
		static Node encode(const com::robotraconteur::geometry::Vector3& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Vector3& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Vector6>{
		static Node encode(const com::robotraconteur::geometry::Vector6& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Vector6& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Point2D>{
		static Node encode(const com::robotraconteur::geometry::Point2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Point2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Point>{
		static Node encode(const com::robotraconteur::geometry::Point& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Point& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Size2D>{
		static Node encode(const com::robotraconteur::geometry::Size2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Size2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Size>{
		static Node encode(const com::robotraconteur::geometry::Size& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Size& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Rect>{
		static Node encode(const com::robotraconteur::geometry::Rect& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Rect& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Box>{
		static Node encode(const com::robotraconteur::geometry::Box& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Box& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Quaternion>{
		static Node encode(const com::robotraconteur::geometry::Quaternion& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Quaternion& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Plane>{
		static Node encode(const com::robotraconteur::geometry::Plane& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Plane& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Transform>{
		static Node encode(const com::robotraconteur::geometry::Transform& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Transform& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Pose>{
		static Node encode(const com::robotraconteur::geometry::Pose& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Pose& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Pose2D>{
		static Node encode(const com::robotraconteur::geometry::Pose2D& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Pose2D& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometry::SpatialVelocity& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialVelocity& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometry::SpatialAcceleration& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialAcceleration& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::Wrench>{
		static Node encode(const com::robotraconteur::geometry::Wrench& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::Wrench& rhs);
	};

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometry::SpatialInertia& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::SpatialInertia& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedTransformPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedTransformPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPosePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPosePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometry::PoseWithCovariancePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::PoseWithCovariancePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPoseWithCovariancePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedPose2DPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedPose2DPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialVelocityPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialAccelerationPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedWrenchPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedWrenchPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::NamedSpatialInertiaPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometry::BoundingBox2DPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::BoundingBox2DPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometry::BoundingBoxPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::BoundingBoxPtr& rhs);
	};


}