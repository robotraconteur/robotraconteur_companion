#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::sensor::SensorInfoPtr>
{
    static Node encode(const com::robotraconteur::sensor::SensorInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::sensor::SensorInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::sensor::SensorDataPtr>
{
    static Node encode(const com::robotraconteur::sensor::SensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::sensor::SensorDataPtr& rhs);
};

} // namespace YAML
