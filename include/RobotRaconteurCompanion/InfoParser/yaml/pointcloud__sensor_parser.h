#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudSensorDataPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloudPartSensorDataPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2SensorDataPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::sensor::PointCloud2PartSensorDataPtr& rhs);
};

} // namespace YAML
