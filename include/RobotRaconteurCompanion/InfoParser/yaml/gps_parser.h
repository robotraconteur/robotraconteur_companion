#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::gps::GpsStatusPtr>
{
    static Node encode(const com::robotraconteur::gps::GpsStatusPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::gps::GpsStatusPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::gps::GpsStatePtr>
{
    static Node encode(const com::robotraconteur::gps::GpsStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::gps::GpsStatePtr& rhs);
};

} // namespace YAML
