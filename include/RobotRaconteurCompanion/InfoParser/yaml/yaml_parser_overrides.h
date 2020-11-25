#include <string>
#include "yaml-cpp/yaml.h"
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace InfoParser
{
namespace yaml
{
    static boost::array<uint8_t,16> parse_uuid_bytes_override(const YAML::Node& node, const std::string& key)
    {
        if (node[key])
        {
            auto string_uuid = node[key].as<std::string>();
            auto boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
            boost::array<uint8_t,16> ret;
            std::copy(boost_uuid.begin(),boost_uuid.end(),ret.begin());
            return ret;
        }
        else
        {        
            throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
        }
    }

    
    static uint64_t parse_planner_algorithm_flags_override(const YAML::Node& node, const std::string& key, bool optional)
    {
        if (node[key])
        {
            uint32_t ret = 0;
            std::vector<std::string> vals = node[key].as<std::vector<std::string> >();
            for (auto v : vals)
            {
                try
                {
                    ret |= string_to_enum_FilterAlgorithmCapabilityFlags(v,node[key]);
                    continue;
                }
                catch(const std::exception&)
                {
                    
                }                
                
                ret |= string_to_enum_PlanningSceneCapabilityFlags(v,node[key]);
            }
            return ret;
        }
        else
        {
            if (optional)
            {
                return 0;
            }
            else
            {
                throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
            }
        }        
    }
}
}
}
}

namespace YAML
{
    template<> 
	struct convert<com::robotraconteur::uuid::UUID>{
		static Node encode(const com::robotraconteur::uuid::UUID& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::uuid::UUID& rhs){
            auto string_uuid = node.as<std::string>();
            auto boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
            std::copy(boost_uuid.begin(),boost_uuid.end(),rhs.s.uuid_bytes.begin());
			return true;
		}
	};

    template<> 
	struct convert<com::robotraconteur::identifier::IdentifierPtr>{
		static Node encode(const com::robotraconteur::identifier::IdentifierPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::identifier::IdentifierPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::identifier::Identifier);
            if (node.IsScalar())
            {
                rhs->name = node.as<std::string>();
                std::fill(rhs->uuid.a.begin(),rhs->uuid.a.end(),0);
                return true;
            }
			rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"name",true);
			rhs->uuid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::uuid::UUID>(node,"uuid",true);
			return true;
		}
	};
}