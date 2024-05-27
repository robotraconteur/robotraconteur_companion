#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::imu::ImuStatePtr>
{
    static Node encode(const com::robotraconteur::imu::ImuStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::imu::ImuStatePtr& rhs);
};

} // namespace YAML
