#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::param::ParameterInfoPtr>
{
    static Node encode(const com::robotraconteur::param::ParameterInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::param::ParameterInfoPtr& rhs);
};

} // namespace YAML
