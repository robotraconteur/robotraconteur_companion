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
	struct convert<com::robotraconteur::color::ColorRGBA>{
		static Node encode(const com::robotraconteur::color::ColorRGBA& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBA& rhs){
			rhs.s.r = node["r"].as<double>();
			rhs.s.g = node["g"].as<double>();
			rhs.s.b = node["b"].as<double>();
			rhs.s.a = node["a"].as<double>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAf>{
		static Node encode(const com::robotraconteur::color::ColorRGBAf& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAf& rhs){
			rhs.s.r = node["r"].as<float>();
			rhs.s.g = node["g"].as<float>();
			rhs.s.b = node["b"].as<float>();
			rhs.s.a = node["a"].as<float>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAu>{
		static Node encode(const com::robotraconteur::color::ColorRGBAu& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAu& rhs){
			rhs.s.r = node["r"].as<uint8_t>();
			rhs.s.g = node["g"].as<uint8_t>();
			rhs.s.b = node["b"].as<uint8_t>();
			rhs.s.a = node["a"].as<uint8_t>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBAh>{
		static Node encode(const com::robotraconteur::color::ColorRGBAh& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAh& rhs){
			rhs.s.r = node["r"].as<uint16_t>();
			rhs.s.g = node["g"].as<uint16_t>();
			rhs.s.b = node["b"].as<uint16_t>();
			rhs.s.a = node["a"].as<uint16_t>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGB>{
		static Node encode(const com::robotraconteur::color::ColorRGB& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGB& rhs){
			rhs.s.r = node["r"].as<double>();
			rhs.s.g = node["g"].as<double>();
			rhs.s.b = node["b"].as<double>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBf>{
		static Node encode(const com::robotraconteur::color::ColorRGBf& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBf& rhs){
			rhs.s.r = node["r"].as<float>();
			rhs.s.g = node["g"].as<float>();
			rhs.s.b = node["b"].as<float>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBu>{
		static Node encode(const com::robotraconteur::color::ColorRGBu& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBu& rhs){
			rhs.s.r = node["r"].as<uint8_t>();
			rhs.s.g = node["g"].as<uint8_t>();
			rhs.s.b = node["b"].as<uint8_t>();
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::color::ColorRGBh>{
		static Node encode(const com::robotraconteur::color::ColorRGBh& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::color::ColorRGBh& rhs){
			rhs.s.r = node["r"].as<uint16_t>();
			rhs.s.g = node["g"].as<uint16_t>();
			rhs.s.b = node["b"].as<uint16_t>();
			return true;
		}
	};


}