#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MeshTriangle>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
			rhs.s.v1 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v1",false);
			rhs.s.v2 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v2",false);
			rhs.s.v3 = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"v3",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometry::shapes::BoxPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::BoxPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::BoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Box); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"x",true);
			rhs->y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"y",true);
			rhs->z = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"z",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::SpherePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::SpherePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::SpherePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Sphere); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::CylinderPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cylinder); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
			rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::ConePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ConePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ConePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cone); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
			rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::CapsulePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Capsule); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"height",true);
			rhs->radius = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"radius",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::PlanePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::PlanePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::PlanePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Plane); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",true);
			rhs->b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",true);
			rhs->c = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"c",true);
			rhs->d = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"d",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MeshTexturePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::MeshTexture); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::CompressedImagePtr>(node,"image",true);
			rhs->uvs = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector2>(node,"uvs",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MeshPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Mesh); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->triangles = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::shapes::MeshTriangle>(node,"triangles",true,true,0);
			rhs->vertices = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"vertices",true,true,0);
			rhs->normals = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Vector3>(node,"normals",true,true,0);
			rhs->colors = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::color::ColorRGB>(node,"colors",true,true,0);
			rhs->textures = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::MeshTexturePtr>(node,"textures",true);
			rhs->mesh_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::geometry::shapes::MeshType::MeshType>(node,"mesh_type",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MaterialPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Material); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->base_color_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"base_color_factor",true);
			rhs->metallic_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"metallic_factor",true);
			rhs->roughness_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"roughness_factor",true);
			rhs->emissive_factor = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::color::ColorRGBA>(node,"emissive_factor",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::ShapeObjectPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::ShapeObject); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::identifier::IdentifierPtr>(node,"name",true);
			// TODO: parse field varvalue{list} shapes
			// TODO: parse field com.robotraconteur.geometry.Pose{list} shape_poses
			rhs->shape_materials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::geometry::shapes::MaterialPtr>(node,"shape_materials",true);
			rhs->inertia = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::SpatialInertia>(node,"inertia",true);
			rhs->fiducials = RobotRaconteur::Companion::InfoParser::yaml::parse_structure_list<com::robotraconteur::fiducial::FiducialPtr>(node,"fiducials",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}