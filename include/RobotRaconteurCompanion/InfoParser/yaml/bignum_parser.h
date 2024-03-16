#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::bignum::BigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::BigNumPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::BigNumPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigNum); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::bignum::UnsignedBigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::UnsignedBigNumPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::UnsignedBigNum); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::bignum::BigFloatPtr>{
		static Node encode(const com::robotraconteur::bignum::BigFloatPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::bignum::BigFloatPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::bignum::BigFloat); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->num = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"num",true);
			rhs->den = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"den",true);
			rhs->radix = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::bignum::BigNumPtr>(node,"radix",true);
			return true;
		}
	};



}