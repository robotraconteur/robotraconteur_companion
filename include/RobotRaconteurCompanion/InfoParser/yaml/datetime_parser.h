#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{
template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::datetime::TimeSpec3>
{
    static Node encode(const com::robotraconteur::datetime::TimeSpec3& rhs);
    static bool decode(const Node& node, com::robotraconteur::datetime::TimeSpec3& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::datetime::DateTimeLocalPtr>
{
    static Node encode(const com::robotraconteur::datetime::DateTimeLocalPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::datetime::DateTimeLocalPtr& rhs);
};

} // namespace YAML
