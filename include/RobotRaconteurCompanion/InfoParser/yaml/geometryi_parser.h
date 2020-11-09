#pragma once
#include <RobotRaconteur.h>
#include "yaml-cpp/yaml.h"
#include <boost/uuid/uuid_io.hpp>
#include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"
#include "yaml_loader_enums.h"

using namespace RobotRaconteur;
using namespace Companion;
using namespace boost;

#pragma once

namespace RR = RobotRaconteur;

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometryi::Vector2>{
		static Node encode(const com::robotraconteur::geometryi::Vector2& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector2& rhs){
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Vector3>{
		static Node encode(const com::robotraconteur::geometryi::Vector3& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector3& rhs){
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			rhs.s.z = node["z"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Vector6>{
		static Node encode(const com::robotraconteur::geometryi::Vector6& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Vector6& rhs){
			rhs.s.alpha = node["alpha"].as<int>();
			rhs.s.beta = node["beta"].as<int>();
			rhs.s.gamma = node["gamma"].as<int>();
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			rhs.s.z = node["z"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Point2D>{
		static Node encode(const com::robotraconteur::geometryi::Point2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Point2D& rhs){
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Point>{
		static Node encode(const com::robotraconteur::geometryi::Point& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Point& rhs){
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			rhs.s.z = node["z"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Size2D>{
		static Node encode(const com::robotraconteur::geometryi::Size2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Size2D& rhs){
			rhs.s.width = node["width"].as<int>();
			rhs.s.height = node["height"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Size>{
		static Node encode(const com::robotraconteur::geometryi::Size& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Size& rhs){
			rhs.s.width = node["width"].as<int>();
			rhs.s.height = node["height"].as<int>();
			rhs.s.depth = node["depth"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Rect>{
		static Node encode(const com::robotraconteur::geometryi::Rect& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Rect& rhs){
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometryi::Point2D>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometryi::Size2D>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Box>{
		static Node encode(const com::robotraconteur::geometryi::Box& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Box& rhs){
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometryi::Point>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometryi::Size>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Quaternion>{
		static Node encode(const com::robotraconteur::geometryi::Quaternion& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Quaternion& rhs){
			rhs.s.w = node["w"].as<int>();
			rhs.s.x = node["x"].as<int>();
			rhs.s.y = node["y"].as<int>();
			rhs.s.z = node["z"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Plane>{
		static Node encode(const com::robotraconteur::geometryi::Plane& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Plane& rhs){
			rhs.s.normal = node["normal"].as<com::robotraconteur::geometryi::Vector3>();
			rhs.s.a = node["a"].as<int>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Transform>{
		static Node encode(const com::robotraconteur::geometryi::Transform& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Transform& rhs){
			rhs.s.rotation = node["rotation"].as<com::robotraconteur::geometryi::Quaternion>();
			rhs.s.translation = node["translation"].as<com::robotraconteur::geometryi::Vector3>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Pose>{
		static Node encode(const com::robotraconteur::geometryi::Pose& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Pose& rhs){
			rhs.s.orientation = node["orientation"].as<com::robotraconteur::geometryi::Quaternion>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometryi::Point>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Pose2D>{
		static Node encode(const com::robotraconteur::geometryi::Pose2D& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Pose2D& rhs){
			rhs.s.orientation = node["orientation"].as<int>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometryi::Point2D>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialVelocity>{
		static Node encode(const com::robotraconteur::geometryi::SpatialVelocity& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialVelocity& rhs){
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometryi::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometryi::Vector3>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialAcceleration>{
		static Node encode(const com::robotraconteur::geometryi::SpatialAcceleration& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialAcceleration& rhs){
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometryi::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometryi::Vector3>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::Wrench>{
		static Node encode(const com::robotraconteur::geometryi::Wrench& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::Wrench& rhs){
			rhs.s.torque = node["torque"].as<com::robotraconteur::geometryi::Vector3>();
			rhs.s.force = node["force"].as<com::robotraconteur::geometryi::Vector3>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::geometryi::SpatialInertia>{
		static Node encode(const com::robotraconteur::geometryi::SpatialInertia& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialInertia& rhs){
			rhs.s.m = node["m"].as<int>();
			rhs.s.com = node["com"].as<com::robotraconteur::geometryi::Vector3>();
			rhs.s.ixx = node["ixx"].as<int>();
			rhs.s.ixy = node["ixy"].as<int>();
			rhs.s.ixz = node["ixz"].as<int>();
			rhs.s.iyy = node["iyy"].as<int>();
			rhs.s.iyz = node["iyz"].as<int>();
			rhs.s.izz = node["izz"].as<int>();
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometryi::NamedTransformPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedTransformPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedTransformPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedTransform);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["child_frame"]){
				rhs->child_frame = node["child_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["transform"]){
				rhs->transform = node["transform"].as<com::robotraconteur::geometryi::Transform>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPosePtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPosePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPosePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryi::Pose>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::PoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::PoseWithCovariance);
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryi::Pose>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPoseWithCovariancePtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPoseWithCovariance);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedPose2DPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPose2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedPose2D);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryi::Pose2D>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialVelocityPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialVelocity);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["velocity"]){
				rhs->velocity = node["velocity"].as<com::robotraconteur::geometryi::SpatialVelocity>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialAccelerationPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialAcceleration);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["Acceleration"]){
				rhs->Acceleration = node["Acceleration"].as<com::robotraconteur::geometryi::SpatialAcceleration>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedWrenchPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedWrenchPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedWrench);
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["wrench"]){
				rhs->wrench = node["wrench"].as<com::robotraconteur::geometryi::Wrench>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::NamedSpatialInertiaPtr>{
		static Node encode(const com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::NamedSpatialInertia);
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometryi::SpatialInertia>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::BoundingBox2DPtr>{
		static Node encode(const com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBox2DPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox2D);
			if(node["size"]){
				rhs->size = node["size"].as<com::robotraconteur::geometryi::Size2D>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometryi::BoundingBoxPtr>{
		static Node encode(const com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometryi::BoundingBox);
			if(node["size"]){
				rhs->size = node["size"].as<com::robotraconteur::geometryi::Size>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::geometryi::NamedPoseWithCovariance 
// com::robotraconteur::geometryi::BoundingBox2D 
// com::robotraconteur::geometryi::BoundingBox 

}