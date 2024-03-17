#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::resource::ResourceIdentifierPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceIdentifierPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::resource::ResourceIdentifierPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::resource::BucketInfoPtr>{
		static Node encode(const com::robotraconteur::resource::BucketInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::resource::BucketInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::resource::ResourceInfoPtr>{
		static Node encode(const com::robotraconteur::resource::ResourceInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::resource::ResourceInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::resource::ResourcePtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::resource::ResourcePartPtr>{
		static Node encode(const com::robotraconteur::resource::ResourcePartPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::resource::ResourcePartPtr& rhs);
	};


}