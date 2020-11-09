#pragma once
#include <string>
namespace RobotRaconteur{
namespace Companion{
namespace InfoParser{
namespace yaml{
int string_to_enum_ActionStatusCode(const std::string &input);
int string_to_enum_ActuatorTypeCode(const std::string &input);
int string_to_enum_ActuatorMode(const std::string &input);
int string_to_enum_DataTypeCode(const std::string &input);
int string_to_enum_ArrayTypeCode(const std::string &input);
int string_to_enum_ContainerTypeCode(const std::string &input);
int string_to_enum_ClockTypeCode(const std::string &input);
int string_to_enum_EventLogLevel(const std::string &input);
int string_to_enum_MeshType(const std::string &input);
int string_to_enum_JoystickCapabilities(const std::string &input);
int string_to_enum_GamepadButtons(const std::string &input);
int string_to_enum_JoystickHatState(const std::string &input);
int string_to_enum_ImageEncoding(const std::string &input);
int string_to_enum_TriggerMode(const std::string &input);
int string_to_enum_Capabilities(const std::string &input);
int string_to_enum_OcTreeEncoding(const std::string &input);
int string_to_enum_JointPositionUnits(const std::string &input);
int string_to_enum_JointVelocityUnits(const std::string &input);
int string_to_enum_JointAccelerationUnits(const std::string &input);
int string_to_enum_JointJerkUnits(const std::string &input);
int string_to_enum_JointEffortUnits(const std::string &input);
int string_to_enum_JointType(const std::string &input);
int string_to_enum_PlannerStatusCode(const std::string &input);
int string_to_enum_PlannerMotionTypeCode(const std::string &input);
int string_to_enum_PlannerAlgorithmCapabilityFlags(const std::string &input);
int string_to_enum_FilterAlgorithmCapabilityFlags(const std::string &input);
int string_to_enum_PlanningSceneCapabilityFlags(const std::string &input);
int string_to_enum_ContactTestTypeCode(const std::string &input);
int string_to_enum_RobotTypeCode(const std::string &input);
int string_to_enum_RobotCommandMode(const std::string &input);
int string_to_enum_RobotOperationalMode(const std::string &input);
int string_to_enum_RobotControllerState(const std::string &input);
int string_to_enum_RobotCapabilities(const std::string &input);
int string_to_enum_RobotStateFlags(const std::string &input);
int string_to_enum_ToolTypeCode(const std::string &input);
int string_to_enum_ToolCapabilities(const std::string &input);
int string_to_enum_ToolStateFlags(const std::string &input);
int string_to_enum_InterpolationMode(const std::string &input);
int string_to_enum_TrajectoryWaypointType(const std::string &input);
int string_to_enum_SensorTypeCode(const std::string &input);
int string_to_enum_ServoTypeCode(const std::string &input);
int string_to_enum_ServoCapabilities(const std::string &input);
int string_to_enum_ServoMode(const std::string &input);
int string_to_enum_SignalType(const std::string &input);
int string_to_enum_SignalAccessLevel(const std::string &input);
}
}
}
}
