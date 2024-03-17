#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::octree::OcTreeInfoPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::octree::OcTreePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::octree::OcTreePartPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePartPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePartPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::octree::OcTreeResourcePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeResourcePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeResourcePtr& rhs);
	};


}