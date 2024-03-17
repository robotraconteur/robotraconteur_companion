#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanInfoPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanInfofPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanInfofPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanInfofPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanfPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanfPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanfPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanPartPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanPartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::laserscan::LaserScanPartfPtr>
{
    static Node encode(const com::robotraconteur::laserscan::LaserScanPartfPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::laserscan::LaserScanPartfPtr& rhs);
};

} // namespace YAML
