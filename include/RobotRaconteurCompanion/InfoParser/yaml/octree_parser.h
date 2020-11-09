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
	struct convert<com::robotraconteur::octree::OcTreeInfoPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeInfo);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			if(node["encoding"]){
				std::string enum_val_string= node["encoding"].as<std::string>();
				rhs->encoding = com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding(string_to_enum_OcTreeEncoding(enum_val_string));
			}
			if(node["id"]){
				rhs->id = node["id"].as<std::string>();
			}
			if(node["resolution"]){
				rhs->resolution = node["resolution"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::octree::OcTreePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTree);
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
	struct convert<com::robotraconteur::octree::OcTreePartPtr>{
		static Node encode(const com::robotraconteur::octree::OcTreePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreePart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
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
	struct convert<com::robotraconteur::octree::OcTreeResourcePtr>{
		static Node encode(const com::robotraconteur::octree::OcTreeResourcePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::octree::OcTreeResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::octree::OcTreeResource);
			if(node["octree_resource"]){
				rhs->octree_resource = node["octree_resource"].as<com::robotraconteur::resource::ResourceIdentifierPtr>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::octree::OcTree 
// com::robotraconteur::octree::OcTreePart 

}