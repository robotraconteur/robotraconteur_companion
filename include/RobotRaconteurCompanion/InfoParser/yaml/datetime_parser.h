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
	struct convert<com::robotraconteur::datetime::DateTimeLocalPtr>{
		static Node encode(const com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datetime::DateTimeLocalPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datetime::DateTimeLocal);
			if(node["seconds"]){
				rhs->seconds = node["seconds"].as<int64_t>();
			}
			if(node["nanoseconds"]){
				rhs->nanoseconds = node["nanoseconds"].as<int>();
			}
			if(node["utc_offset_seconds"]){
				rhs->utc_offset_seconds = node["utc_offset_seconds"].as<int>();
			}
			if(node["timezone_name"]){
				rhs->timezone_name = node["timezone_name"].as<std::string>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::datetime::DateTimeLocal 

}