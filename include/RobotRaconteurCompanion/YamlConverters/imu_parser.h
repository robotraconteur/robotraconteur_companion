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
	struct convert<com::robotraconteur::imu::ImuStatePtr>{
		static Node encode(const com::robotraconteur::imu::ImuStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::imu::ImuStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::imu::ImuState);
			if(node["angular_velocity"]){
				rhs->angular_velocity = node["angular_velocity"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["linear_acceleration"]){
				rhs->linear_acceleration = node["linear_acceleration"].as<com::robotraconteur::geometry::Vector3>();
			}
			if(node["orientation"]){
				rhs->orientation = node["orientation"].as<com::robotraconteur::geometry::Quaternion>();
			}
			return true;
		}
	};



}