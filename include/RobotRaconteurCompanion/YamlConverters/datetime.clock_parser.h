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
	struct convert<com::robotraconteur::datetime::clock::ClockDeviceInfoPtr>{
		static Node encode(const com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datetime::clock::ClockDeviceInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["clock_type"]){
				std::string enum_val_string= node["clock_type"].as<std::string>();
				rhs->clock_type = com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode(string_to_enum_ClockTypeCode(enum_val_string));
			}
			return true;
		}
	};



}