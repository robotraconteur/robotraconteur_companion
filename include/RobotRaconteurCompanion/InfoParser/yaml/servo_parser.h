#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::servo::ServoInfoPtr>
{
    static Node encode(const com::robotraconteur::servo::ServoInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::servo::ServoInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::servo::ServoStatePtr>
{
    static Node encode(const com::robotraconteur::servo::ServoStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::servo::ServoStatePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::servo::ServoStateSensorDataPtr>
{
    static Node encode(const com::robotraconteur::servo::ServoStateSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::servo::ServoStateSensorDataPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::servo::ServoCommandPtr>
{
    static Node encode(const com::robotraconteur::servo::ServoCommandPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::servo::ServoCommandPtr& rhs);
};

} // namespace YAML
