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
	struct convert<com::robotraconteur::units::SIUnitPtr>{
		static Node encode(const com::robotraconteur::units::SIUnitPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::units::SIUnitPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::units::SIUnit);
			if(node["display_units"]){
				rhs->display_units = node["display_units"].as<std::string>();
			}
			if(node["encoded_units"]){
				rhs->encoded_units = node["encoded_units"].as<std::string>();
			}
			return true;
		}
	};



}