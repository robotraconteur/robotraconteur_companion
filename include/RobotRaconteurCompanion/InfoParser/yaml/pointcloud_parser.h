#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{
template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2Point>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2Point& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Point& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2Pointf>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2Pointf& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Pointf& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloudPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloudPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloudPartPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloudPartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloudfPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloudfPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudfPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloudPartfPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2Ptr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2Ptr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Ptr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2PartPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2fPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2fPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2fPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::PointCloud2PartfPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::FreeformPointCloudPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::pointcloud::FreeformPointCloudPartPtr>
{
    static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs);
};

} // namespace YAML
