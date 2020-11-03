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
	struct convert<com::robotraconteur::bignum::BigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::BigNumPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::BigNumPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigNum);
			if(node["data"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data"].size());
				for (int i = 0; i < node["data"].size(); i++) {
					my_array->at(i) = node["data"][i].as<uint8_t>();
				}
				rhs->data = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::bignum::UnsignedBigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::UnsignedBigNum);
			if(node["data"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data"].size());
				for (int i = 0; i < node["data"].size(); i++) {
					my_array->at(i) = node["data"][i].as<uint8_t>();
				}
				rhs->data = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::bignum::BigFloatPtr>{
		static Node encode(const com::robotraconteur::bignum::BigFloatPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::BigFloatPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigFloat);
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::bignum::BigFloat 

}