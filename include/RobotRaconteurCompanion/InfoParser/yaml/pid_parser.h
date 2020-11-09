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
			if(node["cmd_max"]){
				rhs->cmd_max = node["cmd_max"].as<double>();
			}
			if(node["cmd_min"]){
				rhs->cmd_min = node["cmd_min"].as<double>();
			}
			return true;
		}
	};



}