#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{
template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Vector2>
{
    static Node encode(const com::robotraconteur::geometryi::Vector2& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Vector2& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Vector3>
{
    static Node encode(const com::robotraconteur::geometryi::Vector3& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Vector3& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Vector6>
{
    static Node encode(const com::robotraconteur::geometryi::Vector6& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Vector6& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Point2D>
{
    static Node encode(const com::robotraconteur::geometryi::Point2D& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Point2D& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Point>
{
    static Node encode(const com::robotraconteur::geometryi::Point& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Point& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Size2D>
{
    static Node encode(const com::robotraconteur::geometryi::Size2D& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Size2D& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Size>
{
    static Node encode(const com::robotraconteur::geometryi::Size& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Size& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Rect>
{
    static Node encode(const com::robotraconteur::geometryi::Rect& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Rect& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Box>
{
    static Node encode(const com::robotraconteur::geometryi::Box& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Box& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Quaternion>
{
    static Node encode(const com::robotraconteur::geometryi::Quaternion& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Quaternion& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Plane>
{
    static Node encode(const com::robotraconteur::geometryi::Plane& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Plane& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Transform>
{
    static Node encode(const com::robotraconteur::geometryi::Transform& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Transform& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Pose>
{
    static Node encode(const com::robotraconteur::geometryi::Pose& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Pose& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Pose2D>
{
    static Node encode(const com::robotraconteur::geometryi::Pose2D& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Pose2D& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::SpatialVelocity>
{
    static Node encode(const com::robotraconteur::geometryi::SpatialVelocity& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialVelocity& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::SpatialAcceleration>
{
    static Node encode(const com::robotraconteur::geometryi::SpatialAcceleration& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialAcceleration& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::Wrench>
{
    static Node encode(const com::robotraconteur::geometryi::Wrench& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::Wrench& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::SpatialInertia>
{
    static Node encode(const com::robotraconteur::geometryi::SpatialInertia& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::SpatialInertia& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedTransformPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedTransformPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedTransformPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedPosePtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedPosePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPosePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::PoseWithCovariancePtr>
{
    static Node encode(const com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::PoseWithCovariancePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedPoseWithCovariancePtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPoseWithCovariancePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedPose2DPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedPose2DPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedPose2DPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedSpatialVelocityPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialVelocityPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedSpatialAccelerationPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialAccelerationPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedWrenchPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedWrenchPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedWrenchPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::NamedSpatialInertiaPtr>
{
    static Node encode(const com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::NamedSpatialInertiaPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::BoundingBox2DPtr>
{
    static Node encode(const com::robotraconteur::geometryi::BoundingBox2DPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBox2DPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::geometryi::BoundingBoxPtr>
{
    static Node encode(const com::robotraconteur::geometryi::BoundingBoxPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::geometryi::BoundingBoxPtr& rhs);
};

} // namespace YAML
