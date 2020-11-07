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
	struct convert<com::robotraconteur::geometry::shapes::MeshTriangle>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTriangle& rhs){
			rhs.s.v1 = node["v1"].as<uint32_t>();
			rhs.s.v2 = node["v2"].as<uint32_t>();
			rhs.s.v3 = node["v3"].as<uint32_t>();
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::geometry::shapes::BoxPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::BoxPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::BoxPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Box);
			if(node["x"]){
				rhs->x = node["x"].as<double>();
			}
			if(node["y"]){
				rhs->y = node["y"].as<double>();
			}
			if(node["z"]){
				rhs->z = node["z"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::SpherePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::SpherePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::SpherePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Sphere);
			if(node["radius"]){
				rhs->radius = node["radius"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::CylinderPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CylinderPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cylinder);
			if(node["height"]){
				rhs->height = node["height"].as<double>();
			}
			if(node["radius"]){
				rhs->radius = node["radius"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::ConePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ConePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ConePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Cone);
			if(node["height"]){
				rhs->height = node["height"].as<double>();
			}
			if(node["radius"]){
				rhs->radius = node["radius"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::CapsulePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::CapsulePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Capsule);
			if(node["height"]){
				rhs->height = node["height"].as<double>();
			}
			if(node["radius"]){
				rhs->radius = node["radius"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::PlanePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::PlanePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::PlanePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Plane);
			if(node["a"]){
				rhs->a = node["a"].as<double>();
			}
			if(node["b"]){
				rhs->b = node["b"].as<double>();
			}
			if(node["c"]){
				rhs->c = node["c"].as<double>();
			}
			if(node["d"]){
				rhs->d = node["d"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MeshTexturePtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshTexturePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::MeshTexture);
			if(node["image"]){
				rhs->image = node["image"].as<com::robotraconteur::image::CompressedImagePtr>();
			}
			if(node["uvs"]){
				rhs->uvs = node["uvs"].as<com::robotraconteur::geometry::Vector2>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MeshPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MeshPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MeshPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Mesh);
			if(node["mesh_type"]){
				std::string enum_val_string= node["mesh_type"].as<std::string>();
				rhs->mesh_type = com::robotraconteur::geometry::shapes::MeshType::MeshType(string_to_enum_MeshType(enum_val_string));
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::MaterialPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::MaterialPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::Material);
			if(node["albedo"]){
				rhs->albedo = node["albedo"].as<com::robotraconteur::color::ColorRGB>();
			}
			if(node["alpha"]){
				rhs->alpha = node["alpha"].as<double>();
			}
			if(node["reflectivity"]){
				rhs->reflectivity = node["reflectivity"].as<com::robotraconteur::color::ColorRGB>();
			}
			if(node["roughness"]){
				rhs->roughness = node["roughness"].as<double>();
			}
			if(node["emissivity"]){
				rhs->emissivity = node["emissivity"].as<double>();
			}
			if(node["pbr"]){
				std::string type = node["pbr"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["pbr"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["pbr"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["pbr"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["pbr"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
					for (int i = 0; i < node["%s"]["value"].size(); i++) {
						my_array->at(i) = node["%s"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
					for (int i = 0; i < node["%s"]["value"].size(); i++) {
						my_array->at(i) = node["%s"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
					for (int i = 0; i < node["%s"]["value"].size(); i++) {
						my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->pbr=varval;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::geometry::shapes::ShapeObjectPtr>{
		static Node encode(const com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::geometry::shapes::ShapeObjectPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::geometry::shapes::ShapeObject);
			if(node["name"]){
				rhs->name = node["name"].as<com::robotraconteur::identifier::IdentifierPtr>();
			}
			if(node["shape_poses"]){
				RobotRaconteur::RRListPtr<RRNamedArray<com::robotraconteur::geometry::Pose>> listy = AllocateEmptyRRList<RRNamedArray<com::robotraconteur::geometry::Pose>>();
				for(int j=0; j< node["shape_poses"].size(); j++){
					com::robotraconteur::geometry::Pose item= node["shape_poses"][j].as<com::robotraconteur::geometry::Pose>();
					listy->push_back(RobotRaconteur::ScalarToRRNamedArray(item));
				}
				rhs->shape_poses = listy;
			}
			if(node["inertia"]){
				rhs->inertia = node["inertia"].as<com::robotraconteur::geometry::SpatialInertia>();
			}
			if(node["extended"]){
				RR::RRMapPtr<std::string, RR::RRValue> vars;
				for (YAML::const_iterator it = node["extended"].begin(); it != node["extended"].end(); ++it) {
					std::string name = it->first.as<std::string>();
					std::string type = node["extended"]["type"].as<std::string>();
					RR::RRValuePtr varval;
					if(type=="string"){
						std::string value = node["extended"]["value"].as<std::string>();
						varval=RR::stringToRRArray(value);
					}
					if(type=="double"){
						double value = node["extended"]["value"].as<double>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="int32"){
						int value = node["extended"]["value"].as<int>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="uint32"){
						uint32_t value = node["extended"]["value"].as<uint32_t>();
						varval=RR::ScalarToRRArray(value);
					}
					if(type=="double[]"){
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["%s"]["value"].size());
						for (int i = 0; i < node["%s"]["value"].size(); i++) {
							my_array->at(i) = node["%s"]["value"][i].as<uint32_t>();
						}
						varval=my_array;
					}
					vars->insert(std::make_pair(name,varval));
				}
				rhs->extended = vars;
			}
			return true;
		}
	};



}