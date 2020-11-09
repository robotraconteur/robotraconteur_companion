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
	struct convert<com::robotraconteur::pointcloud::PointCloud2Point>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Point& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Point& rhs){
			rhs.s.point = node["point"].as<com::robotraconteur::geometry::Point>();
			rhs.s.intensity = node["intensity"].as<double>();
			rhs.s.normal = node["normal"].as<com::robotraconteur::geometry::Vector3>();
			rhs.s.rgb = node["rgb"].as<com::robotraconteur::image::PixelRGBFloatPacked>();
			for (int i = 0; i < node["moment_invariants"].size(); i++) {
				rhs.s.moment_invariants[i]= node["moment_invariants"][i].as<double>();
			}
			rhs.s.channel = node["channel"].as<double>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2Pointf>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
			rhs.s.point = node["point"].as<com::robotraconteur::geometryf::Point>();
			rhs.s.intensity = node["intensity"].as<float>();
			rhs.s.normal = node["normal"].as<com::robotraconteur::geometryf::Vector3>();
			rhs.s.rgb = node["rgb"].as<com::robotraconteur::image::PixelRGBFloatPackedf>();
			for (int i = 0; i < node["moment_invariants"].size(); i++) {
				rhs.s.moment_invariants[i]= node["moment_invariants"][i].as<float>();
			}
			rhs.s.channel = node["channel"].as<float>();
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPart);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points_offset"]){
				rhs->points_offset = node["points_offset"].as<uint32_t>();
			}
			if(node["points_total_len"]){
				rhs->points_total_len = node["points_total_len"].as<uint32_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudf);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPartfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPartf);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points_offset"]){
				rhs->points_offset = node["points_offset"].as<uint32_t>();
			}
			if(node["points_total_len"]){
				rhs->points_total_len = node["points_total_len"].as<uint32_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2Ptr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2PartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Part);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points_offset"]){
				rhs->points_offset = node["points_offset"].as<uint32_t>();
			}
			if(node["points_total_len"]){
				rhs->points_total_len = node["points_total_len"].as<uint32_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2fPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2f);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2PartfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Partf);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points_offset"]){
				rhs->points_offset = node["points_offset"].as<uint32_t>();
			}
			if(node["points_total_len"]){
				rhs->points_total_len = node["points_total_len"].as<uint32_t>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::FreeformPointCloudPtr>{
		static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloud);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["encoding"]){
				rhs->encoding = node["encoding"].as<std::string>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points"]){
				std::string type = node["points"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["points"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["points"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["points"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["points"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->points=varval;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<uint32_t>();
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



	template<> 
	struct convert<com::robotraconteur::pointcloud::FreeformPointCloudPartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloudPart);
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["encoding"]){
				rhs->encoding = node["encoding"].as<std::string>();
			}
			if(node["is_dense"]){
				rhs->is_dense = node["is_dense"].as<bool>();
			}
			if(node["points_offset"]){
				rhs->points_offset = node["points_offset"].as<uint32_t>();
			}
			if(node["points_total_len"]){
				rhs->points_total_len = node["points_total_len"].as<uint32_t>();
			}
			if(node["points"]){
				std::string type = node["points"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["points"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["points"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["points"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["points"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["points"]["value"].size());
					for (int i = 0; i < node["points"]["value"].size(); i++) {
						my_array->at(i) = node["points"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->points=varval;
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
						RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<double>();
						}
						varval=my_array;
					}
					if(type=="int32[]"){
						RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<int>();
						}
						varval=my_array;
					}
					if(type=="uint32[]"){
						RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["extended"]["value"].size());
						for (int i = 0; i < node["extended"]["value"].size(); i++) {
							my_array->at(i) = node["extended"]["value"][i].as<uint32_t>();
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