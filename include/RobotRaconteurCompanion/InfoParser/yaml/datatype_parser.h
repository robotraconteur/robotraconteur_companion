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
	struct convert<com::robotraconteur::datatype::DataTypePtr>{
		static Node encode(const com::robotraconteur::datatype::DataTypePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::datatype::DataTypePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::datatype::DataType);
			if(node["name"]){
				rhs->name = node["name"].as<std::string>();
			}
			if(node["type_code"]){
				std::string enum_val_string= node["type_code"].as<std::string>();
				rhs->type_code = com::robotraconteur::datatype::DataTypeCode::DataTypeCode(string_to_enum_DataTypeCode(enum_val_string));
			}
			if(node["type_string"]){
				rhs->type_string = node["type_string"].as<std::string>();
			}
			if(node["array_type_code"]){
				std::string enum_val_string= node["array_type_code"].as<std::string>();
				rhs->array_type_code = com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode(string_to_enum_ArrayTypeCode(enum_val_string));
			}
			if(node["array_var_len"]){
				rhs->array_var_len = node["array_var_len"].as<bool>();
			}
			if(node["array_len"]){
				RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["array_len"].size());
				for (int i = 0; i < node["array_len"].size(); i++) {
					my_array->at(i) = node["array_len"][i].as<uint32_t>();
				}
				rhs->array_len = my_array;
			}
			if(node["container_type_code"]){
				std::string enum_val_string= node["container_type_code"].as<std::string>();
				rhs->container_type_code = com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode(string_to_enum_ContainerTypeCode(enum_val_string));
			}
			return true;
		}
	};



}