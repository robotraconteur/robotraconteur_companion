#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::bignum::BigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::BigNumPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::bignum::BigNumPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::bignum::UnsignedBigNumPtr>{
		static Node encode(const com::robotraconteur::bignum::UnsignedBigNumPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::bignum::UnsignedBigNumPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::bignum::BigFloatPtr>{
		static Node encode(const com::robotraconteur::bignum::BigFloatPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::bignum::BigFloatPtr& rhs);
	};


}