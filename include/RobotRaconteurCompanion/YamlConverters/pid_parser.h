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
	struct convert<com::robotraconteur::pid::PIDParamPtr>{
		static Node encode(const com::robotraconteur::pid::PIDParamPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pid::PIDParamPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pid::PIDParam);
			if(node["p"]){
				rhs->p = node["p"].as<double>();
			}
			if(node["i"]){
				rhs->i = node["i"].as<double>();
			}
			if(node["d"]){
				rhs->d = node["d"].as<double>();
			}
			if(node["imax"]){
				rhs->imax = node["imax"].as<double>();
			}
			if(node["imin"]){
				rhs->imin = node["imin"].as<double>();
			}
			if(node["cmdMax"]){
				rhs->cmdMax = node["cmdMax"].as<double>();
			}
			if(node["cmdMin"]){
				rhs->cmdMin = node["cmdMin"].as<double>();
			}
			return true;
		}
	};



}