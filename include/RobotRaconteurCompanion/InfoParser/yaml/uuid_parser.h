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
	struct convert<com::robotraconteur::uuid::UUID>{
		static Node encode(const com::robotraconteur::uuid::UUID& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::uuid::UUID& rhs){
			std::string uuid_long = node.as<std::string>();
			auto uuid_boost = boost::lexical_cast<boost::uuids::uuid>(uuid_long);
			com::robotraconteur::uuid::UUID uuid;
			std::copy(uuid_boost.begin(), uuid_boost.end(), uuid.a.begin());
			return true;
		}
	};


}