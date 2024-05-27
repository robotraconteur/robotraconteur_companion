#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryWaypointPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::trajectory::JointTrajectoryPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::JointTrajectoryPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::TrajectoryStatusPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs);
    static bool decode(const Node& node,
                       com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDeviceWaypointPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs);
    static bool decode(const Node& node,
                       com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryWaypointPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs);
    static bool decode(const Node& node,
                       com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryDevicePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::AdvancedJointTrajectoryPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs);
    static bool decode(const Node& node,
                       com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryWaypointPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr>
{
    static Node encode(const com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::trajectory::FreeformJointTrajectoryPtr& rhs);
};

} // namespace YAML
