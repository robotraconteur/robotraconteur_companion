#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::RobotKinChainInfoPtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotKinChainInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::RobotInfoPtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::RobotInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::RobotStatePtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::RobotStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStatePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::AdvancedRobotStatePtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::AdvancedRobotStatePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::RobotStateSensorDataPtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotStateSensorDataPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::robotics::robot::RobotJointCommandPtr>
{
    static Node encode(const com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::robotics::robot::RobotJointCommandPtr& rhs);
};

} // namespace YAML
