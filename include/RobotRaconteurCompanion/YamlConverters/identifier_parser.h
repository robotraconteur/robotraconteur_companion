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
	struct convert<com::robotraconteur::identifier::IdentifierPtr>{
		static Node encode(const com::robotraconteur::identifier::IdentifierPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::identifier::IdentifierPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::identifier::Identifier);
			if(node["name"]){
				rhs->name = node["name"].as<std::string>();
			}
			if(node["uuid"]){
				rhs->uuid = node["uuid"].as<com::robotraconteur::uuid::UUID>();
			}
			return true;
		}
	};



}