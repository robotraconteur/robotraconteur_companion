#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::MeshTriangle>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTriangle& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTriangle& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::BoxPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::BoxPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::BoxPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::SpherePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::SpherePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::SpherePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::CylinderPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CylinderPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CylinderPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::ConePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ConePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ConePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::CapsulePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CapsulePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CapsulePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::PlanePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::PlanePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::PlanePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::MeshTexturePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::MeshPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::MaterialPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MaterialPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MaterialPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometry::shapes::ShapeObjectPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs);
	};


}