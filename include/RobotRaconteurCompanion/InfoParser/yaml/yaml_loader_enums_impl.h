#pragma once
#include <string>
#include "yaml-cpp/yaml.h"
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/InfoParser/InfoParserMacros.h>
namespace RobotRaconteur
{
namespace Companion
{
namespace InfoParser
{
namespace yaml
{
template <typename T>
struct string_to_enum_traits
{
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ActionStatusCode(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::action::ActionStatusCode::ActionStatusCode>
{
    static com::robotraconteur::action::ActionStatusCode::ActionStatusCode string_to_enum(const std::string& s,
                                                                                          const YAML::Node& node)
    {
        return (com::robotraconteur::action::ActionStatusCode::ActionStatusCode)string_to_enum_ActionStatusCode(s,
                                                                                                                node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ActuatorMode(const std::string& input,
                                                                        const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::actuator::ActuatorMode::ActuatorMode>
{
    static com::robotraconteur::actuator::ActuatorMode::ActuatorMode string_to_enum(const std::string& s,
                                                                                    const YAML::Node& node)
    {
        return (com::robotraconteur::actuator::ActuatorMode::ActuatorMode)string_to_enum_ActuatorMode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ActuatorStateFlags(const std::string& input,
                                                                              const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::actuator::ActuatorStateFlags::ActuatorStateFlags>
{
    static com::robotraconteur::actuator::ActuatorStateFlags::ActuatorStateFlags string_to_enum(const std::string& s,
                                                                                                const YAML::Node& node)
    {
        return (com::robotraconteur::actuator::ActuatorStateFlags::ActuatorStateFlags)string_to_enum_ActuatorStateFlags(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ActuatorTypeCode(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode>
{
    static com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode string_to_enum(const std::string& s,
                                                                                            const YAML::Node& node)
    {
        return (com::robotraconteur::actuator::ActuatorTypeCode::ActuatorTypeCode)string_to_enum_ActuatorTypeCode(s,
                                                                                                                  node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ArrayTypeCode(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode>
{
    static com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::datatype::ArrayTypeCode::ArrayTypeCode)string_to_enum_ArrayTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_CameraStateFlags(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::imaging::CameraStateFlags::CameraStateFlags>
{
    static com::robotraconteur::imaging::CameraStateFlags::CameraStateFlags string_to_enum(const std::string& s,
                                                                                           const YAML::Node& node)
    {
        return (com::robotraconteur::imaging::CameraStateFlags::CameraStateFlags)string_to_enum_CameraStateFlags(s,
                                                                                                                 node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_Capabilities(const std::string& input,
                                                                        const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::imaging::Capabilities::Capabilities>
{
    static com::robotraconteur::imaging::Capabilities::Capabilities string_to_enum(const std::string& s,
                                                                                   const YAML::Node& node)
    {
        return (com::robotraconteur::imaging::Capabilities::Capabilities)string_to_enum_Capabilities(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ClockTypeCode(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode>
{
    static com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::datetime::ClockTypeCode::ClockTypeCode)string_to_enum_ClockTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ContainerTypeCode(const std::string& input,
                                                                             const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode>
{
    static com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode string_to_enum(const std::string& s,
                                                                                              const YAML::Node& node)
    {
        return (com::robotraconteur::datatype::ContainerTypeCode::ContainerTypeCode)string_to_enum_ContainerTypeCode(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_DataTypeCode(const std::string& input,
                                                                        const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::datatype::DataTypeCode::DataTypeCode>
{
    static com::robotraconteur::datatype::DataTypeCode::DataTypeCode string_to_enum(const std::string& s,
                                                                                    const YAML::Node& node)
    {
        return (com::robotraconteur::datatype::DataTypeCode::DataTypeCode)string_to_enum_DataTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_EventLogLevel(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::eventlog::EventLogLevel::EventLogLevel>
{
    static com::robotraconteur::eventlog::EventLogLevel::EventLogLevel string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::eventlog::EventLogLevel::EventLogLevel)string_to_enum_EventLogLevel(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_GamepadButtons(const std::string& input,
                                                                          const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::hid::joystick::GamepadButtons::GamepadButtons>
{
    static com::robotraconteur::hid::joystick::GamepadButtons::GamepadButtons string_to_enum(const std::string& s,
                                                                                             const YAML::Node& node)
    {
        return (com::robotraconteur::hid::joystick::GamepadButtons::GamepadButtons)string_to_enum_GamepadButtons(s,
                                                                                                                 node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_GpsCovarianceTypeCode(const std::string& input,
                                                                                 const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::gps::GpsCovarianceTypeCode::GpsCovarianceTypeCode>
{
    static com::robotraconteur::gps::GpsCovarianceTypeCode::GpsCovarianceTypeCode string_to_enum(const std::string& s,
                                                                                                 const YAML::Node& node)
    {
        return (com::robotraconteur::gps::GpsCovarianceTypeCode::GpsCovarianceTypeCode)
            string_to_enum_GpsCovarianceTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_GpsMeasureSourceFlags(const std::string& input,
                                                                                 const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::gps::GpsMeasureSourceFlags::GpsMeasureSourceFlags>
{
    static com::robotraconteur::gps::GpsMeasureSourceFlags::GpsMeasureSourceFlags string_to_enum(const std::string& s,
                                                                                                 const YAML::Node& node)
    {
        return (com::robotraconteur::gps::GpsMeasureSourceFlags::GpsMeasureSourceFlags)
            string_to_enum_GpsMeasureSourceFlags(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_GpsMeasurementStatusCode(const std::string& input,
                                                                                    const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::gps::GpsMeasurementStatusCode::GpsMeasurementStatusCode>
{
    static com::robotraconteur::gps::GpsMeasurementStatusCode::GpsMeasurementStatusCode string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::gps::GpsMeasurementStatusCode::GpsMeasurementStatusCode)
            string_to_enum_GpsMeasurementStatusCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ImageEncoding(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::image::ImageEncoding::ImageEncoding>
{
    static com::robotraconteur::image::ImageEncoding::ImageEncoding string_to_enum(const std::string& s,
                                                                                   const YAML::Node& node)
    {
        return (com::robotraconteur::image::ImageEncoding::ImageEncoding)string_to_enum_ImageEncoding(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_InterpolationMode(const std::string& input,
                                                                             const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode>
{
    static com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::trajectory::InterpolationMode::InterpolationMode)
            string_to_enum_InterpolationMode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointAccelerationUnits(const std::string& input,
                                                                                  const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointAccelerationUnits::JointAccelerationUnits>
{
    static com::robotraconteur::robotics::joints::JointAccelerationUnits::JointAccelerationUnits string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointAccelerationUnits::JointAccelerationUnits)
            string_to_enum_JointAccelerationUnits(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointEffortUnits(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits>
{
    static com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointEffortUnits::JointEffortUnits)
            string_to_enum_JointEffortUnits(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointJerkUnits(const std::string& input,
                                                                          const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointJerkUnits::JointJerkUnits>
{
    static com::robotraconteur::robotics::joints::JointJerkUnits::JointJerkUnits string_to_enum(const std::string& s,
                                                                                                const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointJerkUnits::JointJerkUnits)string_to_enum_JointJerkUnits(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointPositionUnits(const std::string& input,
                                                                              const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits>
{
    static com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointPositionUnits::JointPositionUnits)
            string_to_enum_JointPositionUnits(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointType(const std::string& input, const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointType::JointType>
{
    static com::robotraconteur::robotics::joints::JointType::JointType string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointType::JointType)string_to_enum_JointType(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JointVelocityUnits(const std::string& input,
                                                                              const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::joints::JointVelocityUnits::JointVelocityUnits>
{
    static com::robotraconteur::robotics::joints::JointVelocityUnits::JointVelocityUnits string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::joints::JointVelocityUnits::JointVelocityUnits)
            string_to_enum_JointVelocityUnits(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JoystickCapabilities(const std::string& input,
                                                                                const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::hid::joystick::JoystickCapabilities::JoystickCapabilities>
{
    static com::robotraconteur::hid::joystick::JoystickCapabilities::JoystickCapabilities string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::hid::joystick::JoystickCapabilities::JoystickCapabilities)
            string_to_enum_JoystickCapabilities(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_JoystickHatState(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::hid::joystick::JoystickHatState::JoystickHatState>
{
    static com::robotraconteur::hid::joystick::JoystickHatState::JoystickHatState string_to_enum(const std::string& s,
                                                                                                 const YAML::Node& node)
    {
        return (com::robotraconteur::hid::joystick::JoystickHatState::JoystickHatState)string_to_enum_JoystickHatState(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_MeshType(const std::string& input, const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::geometry::shapes::MeshType::MeshType>
{
    static com::robotraconteur::geometry::shapes::MeshType::MeshType string_to_enum(const std::string& s,
                                                                                    const YAML::Node& node)
    {
        return (com::robotraconteur::geometry::shapes::MeshType::MeshType)string_to_enum_MeshType(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_OcTreeEncoding(const std::string& input,
                                                                          const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding>
{
    static com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::octree::OcTreeEncoding::OcTreeEncoding)string_to_enum_OcTreeEncoding(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotCapabilities(const std::string& input,
                                                                             const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities>
{
    static com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotCapabilities::RobotCapabilities)
            string_to_enum_RobotCapabilities(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotCommandMode(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode>
{
    static com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotCommandMode::RobotCommandMode)
            string_to_enum_RobotCommandMode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotControllerState(const std::string& input,
                                                                                const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState>
{
    static com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotControllerState::RobotControllerState)
            string_to_enum_RobotControllerState(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotOperationalMode(const std::string& input,
                                                                                const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode>
{
    static com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotOperationalMode::RobotOperationalMode)
            string_to_enum_RobotOperationalMode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotStateFlags(const std::string& input,
                                                                           const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotStateFlags::RobotStateFlags>
{
    static com::robotraconteur::robotics::robot::RobotStateFlags::RobotStateFlags string_to_enum(const std::string& s,
                                                                                                 const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotStateFlags::RobotStateFlags)string_to_enum_RobotStateFlags(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_RobotTypeCode(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode>
{
    static com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode string_to_enum(const std::string& s,
                                                                                             const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::robot::RobotTypeCode::RobotTypeCode)string_to_enum_RobotTypeCode(s,
                                                                                                                node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_SensorDataFlags(const std::string& input,
                                                                           const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::sensor::SensorDataFlags::SensorDataFlags>
{
    static com::robotraconteur::sensor::SensorDataFlags::SensorDataFlags string_to_enum(const std::string& s,
                                                                                        const YAML::Node& node)
    {
        return (com::robotraconteur::sensor::SensorDataFlags::SensorDataFlags)string_to_enum_SensorDataFlags(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_SensorTypeCode(const std::string& input,
                                                                          const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode>
{
    static com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode string_to_enum(const std::string& s,
                                                                                      const YAML::Node& node)
    {
        return (com::robotraconteur::sensor::SensorTypeCode::SensorTypeCode)string_to_enum_SensorTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ServoCapabilities(const std::string& input,
                                                                             const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::servo::ServoCapabilities::ServoCapabilities>
{
    static com::robotraconteur::servo::ServoCapabilities::ServoCapabilities string_to_enum(const std::string& s,
                                                                                           const YAML::Node& node)
    {
        return (com::robotraconteur::servo::ServoCapabilities::ServoCapabilities)string_to_enum_ServoCapabilities(s,
                                                                                                                  node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ServoMode(const std::string& input, const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::servo::ServoMode::ServoMode>
{
    static com::robotraconteur::servo::ServoMode::ServoMode string_to_enum(const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::servo::ServoMode::ServoMode)string_to_enum_ServoMode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ServoStateFlags(const std::string& input,
                                                                           const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::servo::ServoStateFlags::ServoStateFlags>
{
    static com::robotraconteur::servo::ServoStateFlags::ServoStateFlags string_to_enum(const std::string& s,
                                                                                       const YAML::Node& node)
    {
        return (com::robotraconteur::servo::ServoStateFlags::ServoStateFlags)string_to_enum_ServoStateFlags(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ServoTypeCode(const std::string& input,
                                                                         const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::servo::ServoTypeCode::ServoTypeCode>
{
    static com::robotraconteur::servo::ServoTypeCode::ServoTypeCode string_to_enum(const std::string& s,
                                                                                   const YAML::Node& node)
    {
        return (com::robotraconteur::servo::ServoTypeCode::ServoTypeCode)string_to_enum_ServoTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_SignalAccessLevel(const std::string& input,
                                                                             const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel>
{
    static com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel string_to_enum(const std::string& s,
                                                                                            const YAML::Node& node)
    {
        return (com::robotraconteur::signal::SignalAccessLevel::SignalAccessLevel)string_to_enum_SignalAccessLevel(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_SignalDeviceStateFlags(const std::string& input,
                                                                                  const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::signal::SignalDeviceStateFlags::SignalDeviceStateFlags>
{
    static com::robotraconteur::signal::SignalDeviceStateFlags::SignalDeviceStateFlags string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::signal::SignalDeviceStateFlags::SignalDeviceStateFlags)
            string_to_enum_SignalDeviceStateFlags(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_SignalType(const std::string& input, const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::signal::SignalType::SignalType>
{
    static com::robotraconteur::signal::SignalType::SignalType string_to_enum(const std::string& s,
                                                                              const YAML::Node& node)
    {
        return (com::robotraconteur::signal::SignalType::SignalType)string_to_enum_SignalType(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ToolCapabilities(const std::string& input,
                                                                            const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities>
{
    static com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::tool::ToolCapabilities::ToolCapabilities)string_to_enum_ToolCapabilities(
            s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ToolStateFlags(const std::string& input,
                                                                          const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::tool::ToolStateFlags::ToolStateFlags>
{
    static com::robotraconteur::robotics::tool::ToolStateFlags::ToolStateFlags string_to_enum(const std::string& s,
                                                                                              const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::tool::ToolStateFlags::ToolStateFlags)string_to_enum_ToolStateFlags(s,
                                                                                                                  node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_ToolTypeCode(const std::string& input,
                                                                        const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode>
{
    static com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode string_to_enum(const std::string& s,
                                                                                          const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::tool::ToolTypeCode::ToolTypeCode)string_to_enum_ToolTypeCode(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_TrajectoryWaypointType(const std::string& input,
                                                                                  const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType>
{
    static com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType string_to_enum(
        const std::string& s, const YAML::Node& node)
    {
        return (com::robotraconteur::robotics::trajectory::TrajectoryWaypointType::TrajectoryWaypointType)
            string_to_enum_TrajectoryWaypointType(s, node);
    }
};
ROBOTRACONTEUR_COMPANION_INFOPARSER_API int string_to_enum_TriggerMode(const std::string& input,
                                                                       const YAML::Node& node);
template <>
struct string_to_enum_traits<com::robotraconteur::imaging::TriggerMode::TriggerMode>
{
    static com::robotraconteur::imaging::TriggerMode::TriggerMode string_to_enum(const std::string& s,
                                                                                 const YAML::Node& node)
    {
        return (com::robotraconteur::imaging::TriggerMode::TriggerMode)string_to_enum_TriggerMode(s, node);
    }
};
} // namespace yaml
} // namespace InfoParser
} // namespace Companion
} // namespace RobotRaconteur
