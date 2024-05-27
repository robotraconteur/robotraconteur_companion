#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::isoch::IsochInfoPtr>
{
    static Node encode(const com::robotraconteur::device::isoch::IsochInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::isoch::IsochInfoPtr& rhs);
};

} // namespace YAML
