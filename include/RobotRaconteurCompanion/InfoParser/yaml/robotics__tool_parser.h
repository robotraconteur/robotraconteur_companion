#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::tool::ToolInfoPtr>
{
    static Node encode(const com::robotraconteur::robotics::tool::ToolInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::tool::ToolStatePtr>
{
    static Node encode(const com::robotraconteur::robotics::tool::ToolStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStatePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::tool::ToolStateSensorDataPtr>
{
    static Node encode(const com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::tool::ToolStateSensorDataPtr& rhs);
};

} // namespace YAML
