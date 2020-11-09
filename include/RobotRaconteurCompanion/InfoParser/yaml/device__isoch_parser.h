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
	struct convert<com::robotraconteur::device::isoch::IsochInfoPtr>{
		static Node encode(const com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::device::isoch::IsochInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::device::isoch::IsochInfo);
			if(node["update_rate"]){
				rhs->update_rate = node["update_rate"].as<double>();
			}
			if(node["max_downsample"]){
				rhs->max_downsample = node["max_downsample"].as<uint32_t>();
			}
			return true;
		}
	};



}