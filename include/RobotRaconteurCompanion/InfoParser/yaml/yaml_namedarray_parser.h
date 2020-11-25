#include <RobotRaconteur/DataTypes.h>
#include "yaml-cpp/yaml.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace InfoParser
{
namespace yaml
{

template<typename T>
T parse_namedarray(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return node[key].as<T>();
    }
    else
    {
        if (optional)
        {
            T ret;
            memset(&ret,0,sizeof(T));
            return ret;
        }
        else
        {
            throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
        }
    }
}

template<typename T>
RobotRaconteur::RRNamedArrayPtr<T> parse_namedarray_array(const YAML::Node& node, const std::string& key, bool optional, bool varlength=true, size_t len=0)
{
    if (node[key])
    {
        auto vec = node[key].as<std::vector<T>>();
        if (len != 0)
        {
            if (!varlength)
            {
                if (vec.size() != len)
                {
                    throw RobotRaconteur::InvalidArgumentException("Bad conversion");
                }                
            }
            else if (len != 0)
            {
                if (vec.size() >= len)
                {
                    throw RobotRaconteur::InvalidArgumentException("Bad conversion");
                } 
            }
        }
        auto ret = RobotRaconteur::AllocateEmptyRRNamedArray<T>(vec.size());
        for (size_t i=0; i<vec.size(); i++)
        {
            ret->at(i) = vec.at(i);
        }
        return ret;        
    }
    else
    {
        if (optional)
        {
            if (varlength)
            {            
                return RobotRaconteur::AllocateEmptyRRNamedArray<T>(0);
            }
            else
            {
                return RobotRaconteur::AllocateEmptyRRNamedArray<T>(len);
            }
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