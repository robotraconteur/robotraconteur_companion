#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::joints::JointLimitsPtr>
{
    static Node encode(const com::robotraconteur::robotics::joints::JointLimitsPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointLimitsPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::joints::JointInfoPtr>
{
    static Node encode(const com::robotraconteur::robotics::joints::JointInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::joints::JointInfoPtr& rhs);
};

} // namespace YAML
