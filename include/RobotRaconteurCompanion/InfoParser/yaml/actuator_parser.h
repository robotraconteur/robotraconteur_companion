#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::actuator::ActuatorStatePtr>
{
    static Node encode(const com::robotraconteur::actuator::ActuatorStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::actuator::ActuatorStatePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::actuator::ActuatorInfoPtr>
{
    static Node encode(const com::robotraconteur::actuator::ActuatorInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::actuator::ActuatorInfoPtr& rhs);
};

} // namespace YAML
