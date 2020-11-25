#pragma once
#include <RobotRaconteur/DataTypes.h>
#include "yaml-cpp/yaml.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace InfoParser
{
namespace yaml
{

template<typename T>
T parse_structure(const YAML::Node& node, const std::string& key, bool optional)
{
    if (node[key])
    {
        return node[key].as<T>();
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
class parse_structure_container_traits {};

template<typename T>
struct parse_structure_container_traits<boost::intrusive_ptr<T> >
{
    typedef T type;
    static RobotRaconteur::RRListPtr<T> parse_structure_list(const YAML::Node& node, const std::string& key, bool optional)
    {
        if (node[key])
        {
            RobotRaconteur::RRListPtr<T> ret = RobotRaconteur::AllocateEmptyRRList<T>();
            auto val = node[key].as<std::list<boost::intrusive_ptr<T> > >();
            std::copy(val.begin(), val.end(), std::back_inserter(*ret));
            return ret;
        }
        else
        {
            if (optional)
            {
                return RobotRaconteur::RRListPtr<T>();
            }
            else
            {
                throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
            }
        }
    }

    static RobotRaconteur::RRMapPtr<int32_t,T> parse_structure_map_int32(const YAML::Node& node, const std::string& key, bool optional)
    {
        if (node[key])
        {
            RobotRaconteur::RRMapPtr<int32_t,T> ret = RobotRaconteur::AllocateEmptyRRMap<int32_t,T>();
            auto val = node[key].as<std::map<int32_t,boost::intrusive_ptr<T> > >();
            //std::copy(val.begin(), val.end(), std::inserter(*ret,ret->end()));
            ret->insert(val.begin(),val.end());
            return ret;
        }
        else
        {
            if (optional)
            {
                return RobotRaconteur::RRMapPtr<int32_t,T>();
            }
            else
            {
                throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
            }
        }
    }

    static RobotRaconteur::RRMapPtr<std::string,T> parse_structure_map_string(const YAML::Node& node, const std::string& key, bool optional)
    {
        if (node[key])
        {
            RobotRaconteur::RRMapPtr<std::string,T> ret = RobotRaconteur::AllocateEmptyRRMap<std::string,T>();
            auto val = node[key].as<std::map<std::string,boost::intrusive_ptr<T> > >();
            //std::copy(val.begin(), val.end(), std::inserter(*ret,ret->end()));
            ret->insert(val.begin(),val.end());
            return ret;
        }
        else
        {
            if (optional)
            {
                return RobotRaconteur::RRMapPtr<std::string,T>();
            }
            else
            {
                throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
            }
        }
    }
};

template <typename T>
RobotRaconteur::RRListPtr<typename parse_structure_container_traits<T>::type> parse_structure_list(const YAML::Node& node, const std::string& key, bool optional)
{
    return parse_structure_container_traits<T>::parse_structure_list(node,key,optional);
}

template <typename T>
RobotRaconteur::RRMapPtr<int32_t,typename parse_structure_container_traits<T>::type> parse_structure_map_int32(const YAML::Node& node, const std::string& key, bool optional)
{
    return parse_structure_container_traits<T>::parse_structure_map_int32(node,key,optional);
}

template <typename T>
RobotRaconteur::RRMapPtr<std::string,typename parse_structure_container_traits<T>::type> parse_structure_map_string(const YAML::Node& node, const std::string& key, bool optional)
{
    return parse_structure_container_traits<T>::parse_structure_map_string(node,key,optional);
}

}
}
}
}