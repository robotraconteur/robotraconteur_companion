#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::datetime::clock::ClockDeviceInfoPtr>
{
    static Node encode(const com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::datetime::clock::ClockDeviceInfoPtr& rhs);
};

} // namespace YAML
