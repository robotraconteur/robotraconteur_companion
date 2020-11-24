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
T parse_number(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return node[key].as<T>();
    }
    else
    {
        if (optional)
        {
            return (T)0;
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

template<typename T>
RobotRaconteur::RRArrayPtr<T> parse_numeric_array(const YAML::Node& node, const std::string& key, bool optional, bool varlength=true, size_t len=0)
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
                    throw YAML::BadConversion(node[key].Mark());
                }                
            }
            else if (len != 0)
            {
                if (vec.size() >= len)
                {
                    throw YAML::BadConversion(node[key].Mark());
                } 
            }
        }
        return RobotRaconteur::VectorToRRArray<T>(vec);
    }
    else
    {
        if (optional)
        {
            if (varlength)
            {            
                return RobotRaconteur::AllocateRRArray<T>(0);
            }
            else
            {
                return RobotRaconteur::AllocateRRArray<T>(len);
            }
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

template<typename T, int N>
boost::array<T,N> parse_numeric_array_na(const YAML::Node& node, const std::string& key)
{
    if (node[key])
    {
        auto arr = node[key].as<std::array<T,N>>();
        boost::array<T,N> ret;
        std::copy(arr.begin(),arr.end(),ret.begin());
        return ret;
    }
    else
    {        
        throw YAML::KeyNotFound(node.Mark(), key);
    }
}


RobotRaconteur::rr_bool parse_bool(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        bool val =  node[key].as<bool>();
        RobotRaconteur::rr_bool ret;
        ret.value = (val) ? 1 : 0;
        return ret;
    }
    else
    {
        if (optional)
        {
            RobotRaconteur::rr_bool ret;
            ret.value = false;
            return ret;
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

std::string parse_string(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return node[key].as<std::string>();
        
    }
    else
    {
        if (optional)
        {
            return "";
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

RobotRaconteur::RRListPtr<RRArray<char> > parse_string_list(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return RobotRaconteur::stringVectorToRRList(node[key].as<std::vector<std::string> >());
        
    }
    else
    {
        if (optional)
        {
            return RobotRaconteur::RRListPtr<RRArray<char> >();
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

template<typename T>
RobotRaconteur::RRListPtr<RobotRaconteur::RRArray<T> > parse_numeric_array_list(const YAML::Node& node, const std::string& key, bool optional, bool varlength=true, size_t len=0)
{
    if (node[key])
    {
        if (!node[key].IsSequence())
        {
            throw YAML::BadConversion(node[key].Mark());
        }

        auto ret = RobotRaconteur::AllocateEmptyRRList<RRArray<double> >();
        for (auto e : node[key])
        {

            auto vec = e.as<std::vector<T>>();
            if (len != 0)
            {
                if (!varlength)
                {
                    if (vec.size() != len)
                    {
                        throw YAML::BadConversion(node[key].Mark());
                    }                
                }
                else if (len != 0)
                {
                    if (vec.size() >= len)
                    {
                        throw YAML::BadConversion(node[key].Mark());
                    } 
                }
            }
            ret->push_back(RobotRaconteur::VectorToRRArray<T>(vec));
        }
        return ret;
    }
    else
    {
        if (optional)
        {                      
            return RobotRaconteur::AllocateEmptyRRList<RRArray<T> >();            
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

template<typename T>
RobotRaconteur::RRMapPtr<std::string,RobotRaconteur::RRArray<T> > parse_numeric_array_map_string(const YAML::Node& node, const std::string& key, bool optional, bool varlength=true, size_t len=0)
{
    if (node[key])
    {
        if (!node[key].IsMap())
        {
            throw YAML::BadConversion(node[key].Mark());
        }

        auto ret = RobotRaconteur::AllocateEmptyRRMap<std::string,RRArray<double> >();
        for (auto e : node[key])
        {
            
            auto vec = e.second.as<std::vector<T>>();
            if (len != 0)
            {
                if (!varlength)
                {
                    if (vec.size() != len)
                    {
                        throw YAML::BadConversion(node[key].Mark());
                    }                
                }
                else if (len != 0)
                {
                    if (vec.size() >= len)
                    {
                        throw YAML::BadConversion(node[key].Mark());
                    } 
                }
            }
            ret->insert(std::make_pair(e.first.as<std::string>(), RobotRaconteur::VectorToRRArray<T>(vec)));
        }
        return ret;
    }
    else
    {
        if (optional)
        {
            return RobotRaconteur::AllocateEmptyRRMap<std::string,RobotRaconteur::RRArray<T> >();
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

template<typename T>
RobotRaconteur::RRMultiDimArrayPtr<T> parse_numeric_multidimarray(const YAML::Node& node, const std::string& key, bool optional, uint32_t m, uint32_t n)
{
    if (node[key])
    {
        auto vec = node[key].as<std::vector<T>>();
        if (vec.size() != m*n)
        {
            throw YAML::BadConversion(node[key].Mark());
        }
        std::vector<uint32_t> dims = {m,n};
        auto ret = RobotRaconteur::AllocateEmptyRRMultiDimArray<T>(dims);
        std::copy(vec.begin(),vec.end(),ret->Array->begin());
        
        return ret;
    }
    else
    {
        if (optional)
        {                     
            std::vector<uint32_t> dims = {m,n};      
            return RobotRaconteur::AllocateEmptyRRMultiDimArray<T>(dims);     
        }
        else
        {
            throw YAML::KeyNotFound(node.Mark(), key);
        }
    }
}

}
}
}
}