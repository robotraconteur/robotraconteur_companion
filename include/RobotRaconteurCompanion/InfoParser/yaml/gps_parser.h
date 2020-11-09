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
	struct convert<com::robotraconteur::gps::GpsStatePtr>{
		static Node encode(const com::robotraconteur::gps::GpsStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::gps::GpsStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsState);
			if(node["altitude"]){
				rhs->altitude = node["altitude"].as<double>();
			}
			if(node["latitude_deg"]){
				rhs->latitude_deg = node["latitude_deg"].as<double>();
			}
			if(node["longitude_deg"]){
				rhs->longitude_deg = node["longitude_deg"].as<double>();
			}
			if(node["velocity_east"]){
				rhs->velocity_east = node["velocity_east"].as<double>();
			}
			if(node["velocity_north"]){
				rhs->velocity_north = node["velocity_north"].as<double>();
			}
			if(node["velocity_up"]){
				rhs->velocity_up = node["velocity_up"].as<double>();
			}
			return true;
		}
	};



}