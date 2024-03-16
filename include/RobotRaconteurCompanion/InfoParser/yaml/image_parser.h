#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::image::PixelRGB>{
		static Node encode(const com::robotraconteur::image::PixelRGB& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGB& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBA>{
		static Node encode(const com::robotraconteur::image::PixelRGBA& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBA& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBFloatPacked>{
		static Node encode(const com::robotraconteur::image::PixelRGBFloatPacked& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPacked& rhs){
			rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"rgb",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::image::PixelRGBFloatPackedf>{
		static Node encode(const com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPackedf& rhs){
			rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"rgb",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::image::ImageInfoPtr>{
		static Node encode(const com::robotraconteur::image::ImageInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImageInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImageInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->height = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"height",true);
			rhs->width = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"width",true);
			rhs->step = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"step",true);
			rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::image::ImageEncoding::ImageEncoding>(node,"encoding",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformImageInfoPtr>{
		static Node encode(const com::robotraconteur::image::FreeformImageInfoPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImageInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImageInfo); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
			rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::ImagePtr>{
		static Node encode(const com::robotraconteur::image::ImagePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::Image); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::CompressedImagePtr>{
		static Node encode(const com::robotraconteur::image::CompressedImagePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImage); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
			rhs->data = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformImagePtr>{
		static Node encode(const com::robotraconteur::image::FreeformImagePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImage); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::FreeformImageInfoPtr>(node,"image_info",true);
			// TODO: parse field varvalue data
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::ImagePartPtr>{
		static Node encode(const com::robotraconteur::image::ImagePartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImagePart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			rhs->data_part = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data_part",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::CompressedImagePartPtr>{
		static Node encode(const com::robotraconteur::image::CompressedImagePartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::CompressedImagePart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::ImageInfoPtr>(node,"image_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			rhs->data_part = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"data_part",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::FreeformImagePartPtr>{
		static Node encode(const com::robotraconteur::image::FreeformImagePartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::FreeformImagePart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::image::FreeformImageInfoPtr>(node,"image_info",true);
			rhs->data_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_offset",true);
			rhs->data_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"data_total_len",true);
			// TODO: parse field varvalue data_part
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::image::ImageResourcePtr>{
		static Node encode(const com::robotraconteur::image::ImageResourcePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::image::ImageResourcePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::image::ImageResource); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->image_resource = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::resource::ResourceIdentifierPtr>(node,"image_resource",true);
			return true;
		}
	};



}