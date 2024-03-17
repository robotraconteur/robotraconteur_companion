#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscanner::LaserScannerInfoPtr>
{
    static Node encode(const com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscanner::LaserScannerInfoPtr& rhs);
};

} // namespace YAML
