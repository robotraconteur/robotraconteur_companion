#pragma once
#include <string>
#include "yaml-cpp/yaml.h"
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include "yaml_loader_enums_impl.h"

namespace RobotRaconteur{
namespace Companion{
namespace InfoParser{
namespace yaml{

template<typename T>
T parse_enum(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return string_to_enum_traits<T>::string_to_enum(node[key].as<std::string>(),node[key]);
    }
    else
    {
        if (optional)
        {
            return T();
        }
        else
        {
            throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
        }
    }
}

template<typename T>
RobotRaconteur::RRListPtr<RRArray<int32_t> > parse_enum_list(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        auto ret = RobotRaconteur::AllocateEmptyRRList<RRArray<int32_t> >();
        std::vector<std::string> vals = node[key].as<std::vector<std::string> >();
        for (const auto& v : vals)
        {
            ret->push_back(RobotRaconteur::ScalarToRRArray((int32_t)string_to_enum_traits<T>::string_to_enum(v,node[key])));
        }
        return ret;
    }
    else
    {
        if (optional)
        {
            return RobotRaconteur::AllocateEmptyRRList<RRArray<int32_t> >();
        }
        else
        {
            throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
        }
    }
}

template<typename T>
uint32_t parse_enum_flags(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        uint32_t ret = 0;
        std::vector<std::string> vals = node[key].as<std::vector<std::string> >();
        for (const auto& v : vals)
        {
            ret |= ((int32_t)string_to_enum_traits<T>::string_to_enum(v,node[key]));
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
