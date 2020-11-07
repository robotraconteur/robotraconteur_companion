#pragma once
#include <RobotRaconteur.h>
#include "yaml-cpp/yaml.h"
#include <boost/uuid/uuid_io.hpp>
#include "robotraconteur_generated.h"
#include "yaml_loader_enums.h"

using namespace RobotRaconteur;
using namespace Companion;
using namespace boost;

namespace RR = RobotRaconteur;

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometry::Vector2>{
		static Node encode(const com::robotraconteur::geometry::Vector2& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::Vector2& rhs){
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
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
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
			rhs.s.z = node["z"].as<double>();
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
			rhs.s.alpha = node["alpha"].as<double>();
			rhs.s.beta = node["beta"].as<double>();
			rhs.s.gamma = node["gamma"].as<double>();
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
			rhs.s.z = node["z"].as<double>();
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
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
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
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
			rhs.s.z = node["z"].as<double>();
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
			rhs.s.width = node["width"].as<double>();
			rhs.s.height = node["height"].as<double>();
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
			rhs.s.width = node["width"].as<double>();
			rhs.s.height = node["height"].as<double>();
			rhs.s.depth = node["depth"].as<double>();
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
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometry::Point2D>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometry::Size2D>();
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
			rhs.s.origin = node["origin"].as<com::robotraconteur::geometry::Point>();
			rhs.s.size = node["size"].as<com::robotraconteur::geometry::Size>();
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
			rhs.s.w = node["w"].as<double>();
			rhs.s.x = node["x"].as<double>();
			rhs.s.y = node["y"].as<double>();
			rhs.s.z = node["z"].as<double>();
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
			rhs.s.normal = node["normal"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.a = node["a"].as<double>();
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
			rhs.s.rotation = node["rotation"].as<com::robotraconteur::geometry::Quaternion>();
			rhs.s.translation = node["translation"].as<com::robotraconteur::geometry::Vector3>();
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
			rhs.s.orientation = node["orientation"].as<com::robotraconteur::geometry::Quaternion>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometry::Point>();
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
			rhs.s.orientation = node["orientation"].as<double>();
			rhs.s.position = node["position"].as<com::robotraconteur::geometry::Point2D>();
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
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometry::Vector3>();
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
			rhs.s.angular = node["angular"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.linear = node["linear"].as<com::robotraconteur::geometry::Vector3>();
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
			rhs.s.torque = node["torque"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.force = node["force"].as<com::robotraconteur::geometry::Vector3>();
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
			rhs.s.m = node["m"].as<double>();
			rhs.s.com = node["com"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.ixx = node["ixx"].as<double>();
			rhs.s.ixy = node["ixy"].as<double>();
			rhs.s.ixz = node["ixz"].as<double>();
			rhs.s.iyy = node["iyy"].as<double>();
			rhs.s.iyz = node["iyz"].as<double>();
			rhs.s.izz = node["izz"].as<double>();
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["child_frame"]){
				rhs->child_frame = node["child_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["transform"]){
				rhs->transform = node["transform"].as<com::robotraconteur::geometry::Transform>();
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometry::Pose>();
			}
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
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometry::Pose>();
			}
			if(node["covariance"]){
				std::vector<uint32_t> dims = {6,6};
				RRMultiDimArrayPtr<double> my_multidimarray = AllocateEmptyRRMultiDimArray<double>(dims);
				for(int i =0; i< 6; i++){
					for(int j=0; j< 6; j++){
						my_multidimarray->Array->at(i+(j * 6)) = node["covariance"][j+ (i * 6)].as<double>();
					}
				}
				rhs->covariance = my_multidimarray;
			}
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
			if(node["covariance"]){
				std::vector<uint32_t> dims = {6,6};
				RRMultiDimArrayPtr<double> my_multidimarray = AllocateEmptyRRMultiDimArray<double>(dims);
				for(int i =0; i< 6; i++){
					for(int j=0; j< 6; j++){
						my_multidimarray->Array->at(i+(j * 6)) = node["covariance"][j+ (i * 6)].as<double>();
					}
				}
				rhs->covariance = my_multidimarray;
			}
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
			if(node["parent_frame"]){
				rhs->parent_frame = node["parent_frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["pose"]){
				rhs->pose = node["pose"].as<com::robotraconteur::geometry::Pose2D>();
			}
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
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["velocity"]){
				rhs->velocity = node["velocity"].as<com::robotraconteur::geometry::SpatialVelocity>();
			}
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
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["Acceleration"]){
				rhs->Acceleration = node["Acceleration"].as<com::robotraconteur::geometry::SpatialAcceleration>();
			}
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
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["wrench"]){
				rhs->wrench = node["wrench"].as<com::robotraconteur::geometry::Wrench>();
			}
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
			if(node["frame"]){
				rhs->frame = node["frame"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometry::SpatialInertia>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::geometry::NamedPoseWithCovariance 

}