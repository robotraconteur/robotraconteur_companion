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
	struct convert<com::robotraconteur::image::PixelRGB>{
		static Node encode(const com::robotraconteur::image::PixelRGB& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGB& rhs){
			rhs.s.r = node["r"].as<uint8_t>();
			rhs.s.g = node["g"].as<uint8_t>();
			rhs.s.b = node["b"].as<uint8_t>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBA>{
		static Node encode(const com::robotraconteur::image::PixelRGBA& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBA& rhs){
			rhs.s.r = node["r"].as<uint8_t>();
			rhs.s.g = node["g"].as<uint8_t>();
			rhs.s.b = node["b"].as<uint8_t>();
			rhs.s.a = node["a"].as<uint8_t>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBFloatPacked>{
		static Node encode(const com::robotraconteur::image::PixelRGBFloatPacked& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPacked& rhs){
			rhs.s.rgb = node["rgb"].as<double>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBFloatPackedf>{
		static Node encode(const com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
			rhs.s.rgb = node["rgb"].as<float>();
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::image::ImageInfoPtr>{
		static Node encode(const com::robotraconteur::image::ImageInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImageInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImageInfo);
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			if(node["height"]){
				rhs->height = node["height"].as<uint32_t>();
			}
			if(node["width"]){
				rhs->width = node["width"].as<uint32_t>();
			}
			if(node["step"]){
				rhs->step = node["step"].as<uint32_t>();
			}
			if(node["encoding"]){
				std::string enum_val_string= node["encoding"].as<std::string>();
				rhs->encoding = com::robotraconteur::image::ImageEncoding::ImageEncoding(RobotRaconteur::Companion::InfoParser::yaml::string_to_enum_ImageEncoding(enum_val_string));
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformImageInfoPtr>{
		static Node encode(const com::robotraconteur::image::FreeformImageInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImageInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImageInfo);
			if(node["encoding"]){
				rhs->encoding = node["encoding"].as<std::string>();
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
	struct convert<com::robotraconteur::image::ImagePtr>{
		static Node encode(const com::robotraconteur::image::ImagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::Image);
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
	struct convert<com::robotraconteur::image::CompressedImagePtr>{
		static Node encode(const com::robotraconteur::image::CompressedImagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImage);
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
	struct convert<com::robotraconteur::image::FreeformImagePtr>{
		static Node encode(const com::robotraconteur::image::FreeformImagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImage);
			if(node["data"]){
				std::string type = node["data"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["data"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["data"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["data"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["data"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["data"]["value"].size());
					for (int i = 0; i < node["data"]["value"].size(); i++) {
						my_array->at(i) = node["data"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["data"]["value"].size());
					for (int i = 0; i < node["data"]["value"].size(); i++) {
						my_array->at(i) = node["data"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["data"]["value"].size());
					for (int i = 0; i < node["data"]["value"].size(); i++) {
						my_array->at(i) = node["data"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->data=varval;
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
	struct convert<com::robotraconteur::image::ImagePartPtr>{
		static Node encode(const com::robotraconteur::image::ImagePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImagePart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
			if(node["data_part"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data_part"].size());
				for (int i = 0; i < node["data_part"].size(); i++) {
					my_array->at(i) = node["data_part"][i].as<uint8_t>();
				}
				rhs->data_part = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::CompressedImagePartPtr>{
		static Node encode(const com::robotraconteur::image::CompressedImagePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImagePart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
			if(node["data_part"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["data_part"].size());
				for (int i = 0; i < node["data_part"].size(); i++) {
					my_array->at(i) = node["data_part"][i].as<uint8_t>();
				}
				rhs->data_part = my_array;
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformImagePartPtr>{
		static Node encode(const com::robotraconteur::image::FreeformImagePartPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImagePart);
			if(node["data_offset"]){
				rhs->data_offset = node["data_offset"].as<uint32_t>();
			}
			if(node["data_total_len"]){
				rhs->data_total_len = node["data_total_len"].as<uint32_t>();
			}
			if(node["data_part"]){
				std::string type = node["data_part"]["type"].as<std::string>();
				RR::RRValuePtr varval;
				if(type=="string"){
					std::string value = node["data_part"]["value"].as<std::string>();
					varval =RR::stringToRRArray(value);
				}
				if(type=="double"){
					double value = node["data_part"]["value"].as<double>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="int32"){
					int value= node["data_part"]["value"].as<int>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="uint32"){
					uint32_t value= node["data_part"]["value"].as<uint32_t>();
					varval=RR::ScalarToRRArray(value);
				}
				if(type=="double[]"){
					RRArrayPtr<double> my_array = AllocateEmptyRRArray<double>(node["data_part"]["value"].size());
					for (int i = 0; i < node["data_part"]["value"].size(); i++) {
						my_array->at(i) = node["data_part"]["value"][i].as<double>();
					}
					varval=my_array;
				}
				if(type=="int32[]"){
					RR::RRArrayPtr<int> my_array = AllocateEmptyRRArray<int>(node["data_part"]["value"].size());
					for (int i = 0; i < node["data_part"]["value"].size(); i++) {
						my_array->at(i) = node["data_part"]["value"][i].as<int>();
					}
					varval=my_array;
				}
				if(type=="uint32[]"){
					RR::RRArrayPtr<uint32_t> my_array = AllocateEmptyRRArray<uint32_t>(node["data_part"]["value"].size());
					for (int i = 0; i < node["data_part"]["value"].size(); i++) {
						my_array->at(i) = node["data_part"]["value"][i].as<uint32_t>();
					}
					varval=my_array;
				}
				rhs->data_part=varval;
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
	struct convert<com::robotraconteur::image::DepthImagePtr>{
		static Node encode(const com::robotraconteur::image::DepthImagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::DepthImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::DepthImage);
			if(node["depth_ticks_per_meter"]){
				rhs->depth_ticks_per_meter = node["depth_ticks_per_meter"].as<double>();
			}
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformDepthImagePtr>{
		static Node encode(const com::robotraconteur::image::FreeformDepthImagePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformDepthImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformDepthImage);
			if(node["depth_ticks_per_meter"]){
				rhs->depth_ticks_per_meter = node["depth_ticks_per_meter"].as<double>();
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
	struct convert<com::robotraconteur::image::ImageResourcePtr>{
		static Node encode(const com::robotraconteur::image::ImageResourcePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImageResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImageResource);
			if(node["image_resource"]){
				rhs->image_resource = node["image_resource"].as<com::robotraconteur::resource::ResourceIdentifierPtr>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::image::FreeformImageInfo 
// com::robotraconteur::image::Image 
// com::robotraconteur::image::CompressedImage 
// com::robotraconteur::image::FreeformImage 
// com::robotraconteur::image::ImagePart 
// com::robotraconteur::image::CompressedImagePart 
// com::robotraconteur::image::FreeformImagePart 
// com::robotraconteur::image::DepthImage 
// com::robotraconteur::image::FreeformDepthImage 

}