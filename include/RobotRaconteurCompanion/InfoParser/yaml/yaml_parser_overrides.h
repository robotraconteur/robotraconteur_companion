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
static boost::array<uint8_t, 16> parse_uuid_bytes_override(const YAML::Node& node, const std::string& key)
{
    if (node[key])
    {
        auto string_uuid = node[key].as<std::string>();
        auto boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
        boost::array<uint8_t, 16> ret{};
        std::copy(boost_uuid.begin(), boost_uuid.end(), ret.begin());
        return ret;
    }
    else
    {
        throw RobotRaconteur::InvalidArgumentException("Key not found: " + key);
    }
}

static void device_info_extra_parse(const YAML::Node& node, com::robotraconteur::device::DeviceInfoPtr& rhs)
{
    RobotRaconteur::RRListPtr<RobotRaconteur::RRValue> tags_out =
        RobotRaconteur::AllocateEmptyRRList<RobotRaconteur::RRValue>();

    if (node["tags"])
    {
        auto tags = node["tags"].as<std::vector<com::robotraconteur::identifier::IdentifierPtr> >();
        for (auto& e : tags)
        {
            tags_out->push_back(e);
        }
    }

    if (node["extended"])
    {
        auto extended = node["extended"];
        if (extended["tags"])
        {
            auto tags = extended["tags"].as<std::vector<com::robotraconteur::identifier::IdentifierPtr> >();
            for (auto& e : tags)
            {
                tags_out->push_back(e);
            }
        }
    }

    if (tags_out->empty())
    {
        return;
    }

    if (!rhs->extended)
    {
        rhs->extended = RobotRaconteur::AllocateEmptyRRMap<std::string, RobotRaconteur::RRValue>();
    }

    rhs->extended->insert(std::make_pair("tags", tags_out));
}

} // namespace yaml
} // namespace InfoParser
} // namespace Companion
} // namespace RobotRaconteur

namespace YAML
{
template <>
struct convert<com::robotraconteur::uuid::UUID>
{
    static Node encode(const com::robotraconteur::uuid::UUID& rhs)
    {
        RR_UNUSED(rhs);
        Node node;
        return node;
    }

    static bool decode(const Node& node, com::robotraconteur::uuid::UUID& rhs)
    {
        auto string_uuid = node.as<std::string>();
        auto boost_uuid = boost::lexical_cast<boost::uuids::uuid>(string_uuid);
        std::copy(boost_uuid.begin(), boost_uuid.end(), rhs.s.uuid_bytes.begin());
        return true;
    }
};

template <>
struct convert<com::robotraconteur::identifier::IdentifierPtr>
{
    static Node encode(const com::robotraconteur::identifier::IdentifierPtr& rhs)
    {
        RR_UNUSED(rhs);
        Node node;
        return node;
    }

    static bool decode(const Node& node, com::robotraconteur::identifier::IdentifierPtr& rhs)
    {
        if (!rhs)
            rhs.reset(new com::robotraconteur::identifier::Identifier); // NOLINT(cppcoreguidelines-owning-memory)
        if (node.IsScalar())
        {
            rhs->name = node.as<std::string>();
            std::fill(rhs->uuid.a.begin(), rhs->uuid.a.end(), 0);
            return true;
        }
        rhs->name = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node, "name", true);
        rhs->uuid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::uuid::UUID>(
            node, "uuid", true);
        return true;
    }
};
} // namespace YAML
