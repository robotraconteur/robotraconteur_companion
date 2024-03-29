#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::lighting::LightInfoPtr>
{
    static Node encode(const com::robotraconteur::lighting::LightInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::lighting::LightInfoPtr& rhs);
};

} // namespace YAML
