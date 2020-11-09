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
	struct convert<com::robotraconteur::geometryf::Vector2>{
		static Node encode(const com::robotraconteur::geometryf::Vector2& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometryf::Vector2& rhs){
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
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
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
			rhs.s.z = node["z"].as<float>();
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
			rhs.s.alpha = node["alpha"].as<float>();
			rhs.s.beta = node["beta"].as<float>();
			rhs.s.gamma = node["gamma"].as<float>();
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
			rhs.s.z = node["z"].as<float>();
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
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
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
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
			rhs.s.z = node["z"].as<float>();
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
			rhs.s.width = node["width"].as<float>();
			rhs.s.height = node["height"].as<float>();
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
			rhs.s.width = node["width"].as<float>();
			rhs.s.height = node["height"].as<float>();
			rhs.s.depth = node["depth"].as<float>();
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
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometryf::Point2D>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometryf::Size2D>();
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
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometryf::Point>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometryf::Size>();
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
			rhs.s.w = node["w"].as<float>();
			rhs.s.x = node["x"].as<float>();
			rhs.s.y = node["y"].as<float>();
			rhs.s.z = node["z"].as<float>();
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
			rhs.s.normal = node["normal"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.a = node["a"].as<float>();
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
			rhs.s.rotation = node["rotation"].as<com::robotraconteur::geometryf::Quaternion>();
			rhs.s.translation = node["translation"].as<com::robotraconteur::geometryf::Vector3>();
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
			rhs.s.orientation = node["orientation"].as<com::robotraconteur::geometryf::Quaternion>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometryf::Point>();
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
			rhs.s.orientation = node["orientation"].as<float>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometryf::Point2D>();
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
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometryf::Vector3>();
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
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometryf::Vector3>();
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
			rhs.s.torque = node["torque"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.force = node["force"].as<com::robotraconteur::geometryf::Vector3>();
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
			rhs.s.m = node["m"].as<float>();
			rhs.s.com = node["com"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.ixx = node["ixx"].as<float>();
			rhs.s.ixy = node["ixy"].as<float>();
			rhs.s.ixz = node["ixz"].as<float>();
			rhs.s.iyy = node["iyy"].as<float>();
			rhs.s.iyz = node["iyz"].as<float>();
			rhs.s.izz = node["izz"].as<float>();
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["child_frame"]){
				rhs->child_frame = node["child_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["transform"]){
				rhs->transform = node["transform"].as<com::robotraconteur::geometryf::Transform>();
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryf::Pose>();
			}
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
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryf::Pose>();
			}
			if(node["covariance"]){
				std::vector<uint32_t> dims = {6,6};
				RRMultiDimArrayPtr<float> my_multidimarray = AllocateEmptyRRMultiDimArray<float>(dims);
				for(int i =0; i< 6; i++){
					for(int j=0; j< 6; j++){
						my_multidimarray->Array->at(i+(j * 6)) = node["covariance"][j+ (i * 6)].as<float>();
					}
				}
				rhs->covariance = my_multidimarray;
			}
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
			if(node["covariance"]){
				std::vector<uint32_t> dims = {6,6};
				RRMultiDimArrayPtr<float> my_multidimarray = AllocateEmptyRRMultiDimArray<float>(dims);
				for(int i =0; i< 6; i++){
					for(int j=0; j< 6; j++){
						my_multidimarray->Array->at(i+(j * 6)) = node["covariance"][j+ (i * 6)].as<float>();
					}
				}
				rhs->covariance = my_multidimarray;
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometryf::Pose2D>();
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["velocity"]){
				rhs->velocity = node["velocity"].as<com::robotraconteur::geometryf::SpatialVelocity>();
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["Acceleration"]){
				rhs->Acceleration = node["Acceleration"].as<com::robotraconteur::geometryf::SpatialAcceleration>();
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["wrench"]){
				rhs->wrench = node["wrench"].as<com::robotraconteur::geometryf::Wrench>();
			}
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
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometryf::SpatialInertia>();
			}
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
			if(node["size"]){
				rhs->size = node["size"].as<com::robotraconteur::geometryf::Size2D>();
			}
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
			if(node["size"]){
				rhs->size = node["size"].as<com::robotraconteur::geometryf::Size>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::geometryf::NamedPoseWithCovariance 
// com::robotraconteur::geometryf::BoundingBox2D 
// com::robotraconteur::geometryf::BoundingBox 

}