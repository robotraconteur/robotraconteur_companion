#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::color::ColorRGBA>{
		static Node encode(const com::robotraconteur::color::ColorRGBA& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBA& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAf>{
		static Node encode(const com::robotraconteur::color::ColorRGBAf& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAf& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"b",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAu>{
		static Node encode(const com::robotraconteur::color::ColorRGBAu& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAu& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAh>{
		static Node encode(const com::robotraconteur::color::ColorRGBAh& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAh& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"b",false);
			rhs.s.a = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"a",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGB>{
		static Node encode(const com::robotraconteur::color::ColorRGB& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGB& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"b",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBf>{
		static Node encode(const com::robotraconteur::color::ColorRGBf& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBf& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"b",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBu>{
		static Node encode(const com::robotraconteur::color::ColorRGBu& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBu& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint8_t>(node,"b",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBh>{
		static Node encode(const com::robotraconteur::color::ColorRGBh& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBh& rhs){
			rhs.s.r = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"r",false);
			rhs.s.g = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"g",false);
			rhs.s.b = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"b",false);
			return true;
		}
	};


}