#include "RobotRaconteurCompanion/InfoParser/yaml/yaml_loader_enums.h"
#include <string>

namespace RobotRaconteur{
namespace Companion{
namespace InfoParser{
namespace yaml{
int string_to_enum_ActionStatusCode(const std::string &input, const YAML::Node& node){
	if(input =="error") return -3;
	if(input =="failed") return -2;
	if(input =="cancelled") return -1;
	if(input =="unknown") return 0;
	if(input =="queued") return 1;
	if(input =="running") return 2;
	if(input =="complete") return 3;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ActuatorTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="generic") return 1;
	if(input =="position") return 2;
	if(input =="velocity") return 3;
	if(input =="acceleration") return 4;
	if(input =="effort") return 5;
	if(input =="motor_position") return 6;
	if(input =="motor_velocity") return 7;
	if(input =="motor_acceleration") return 8;
	if(input =="motor_effort") return 9;
	if(input =="solenoid") return 10;
	if(input =="voice_coil") return 11;
	if(input =="piezoelectric") return 12;
	if(input =="pneumatic_pressure") return 13;
	if(input =="vacuum_pressure") return 14;
	if(input =="heater_power") return 15;
	if(input =="chiller_power") return 16;
	if(input =="valve") return 17;
	if(input =="conveyor") return 18;
	if(input =="voltage") return 19;
	if(input =="current") return 20;
	if(input =="pneumatic_cylinder") return 21;
	if(input =="hydraulic_cylinder") return 22;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ActuatorMode(const std::string &input, const YAML::Node& node){
	if(input =="error") return -2;
	if(input =="disabled") return -1;
	if(input =="halt") return 0;
	if(input =="reduced_performance") return 1;
	if(input =="normal") return 2;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ActuatorStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="ready") return 1;
	if(input =="streaming") return 2;
	if(input =="warning") return 4;
	if(input =="error") return 8;
	if(input =="fatal_error") return 16;
	if(input =="e_stop") return 32;
	if(input =="homed") return 64;
	if(input =="homing_required") return 128;
	if(input =="communication_failure") return 256;
	if(input =="valid_command") return 512;
	if(input =="enabled") return 1024;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_DataTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="void_c") return 0;
	if(input =="double_c") return 1;
	if(input =="single_c") return 2;
	if(input =="int8_c") return 3;
	if(input =="uint8_c") return 4;
	if(input =="int16_c") return 5;
	if(input =="uint16_c") return 6;
	if(input =="int32_c") return 7;
	if(input =="uint32_c") return 8;
	if(input =="int64_c") return 9;
	if(input =="uint64_c") return 10;
	if(input =="string_c") return 11;
	if(input =="cdouble_c") return 12;
	if(input =="csingle_c") return 13;
	if(input =="bool_c") return 14;
	if(input =="structure_c") return 101;
	if(input =="vector_c") return 102;
	if(input =="dictionary_c") return 103;
	if(input =="object_c") return 104;
	if(input =="varvalue_c") return 105;
	if(input =="varobject_c") return 106;
	if(input =="list_c") return 108;
	if(input =="pod_c") return 109;
	if(input =="pod_array_c") return 110;
	if(input =="pod_multidimarray_c") return 111;
	if(input =="enum_c") return 112;
	if(input =="namedtype_c") return 113;
	if(input =="namedarray_c") return 114;
	if(input =="namedarray_array_c") return 115;
	if(input =="namedarray_multidimarray_c") return 116;
	if(input =="multidimarray_c") return 117;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ArrayTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="none_c") return 0;
	if(input =="array_c") return 1;
	if(input =="multidimarray_c") return 2;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ContainerTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="none_c") return 0;
	if(input =="list_c") return 1;
	if(input =="map_int32_c") return 2;
	if(input =="map_string_c") return 3;
	if(input =="generator_c") return 4;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ClockTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="default") return 1;
	if(input =="system_rtc_clock") return 2;
	if(input =="system_ntp_clock") return 3;
	if(input =="system_ptp_clock") return 4;
	if(input =="system_arb_clock") return 5;
	if(input =="system_gps_clock") return 6;
	if(input =="system_tai_clock") return 7;
	if(input =="system_other_clock") return 8;
	if(input =="sim_clock_realtime") return 9;
	if(input =="sim_clock_scaled") return 10;
	if(input =="node_default") return 11;
	if(input =="node_rtc_clock") return 12;
	if(input =="node_ntp_clock") return 13;
	if(input =="node_ptp_clock") return 14;
	if(input =="node_arb_clock") return 15;
	if(input =="node_gps_clock") return 16;
	if(input =="node_tai_clock") return 17;
	if(input =="node_other_clock") return 18;
	if(input =="aux_0") return 4096;
	if(input =="aux_1") return 4097;
	if(input =="aux_2") return 4098;
	if(input =="aux_3") return 4099;
	if(input =="aux_4") return 4100;
	if(input =="aux_5") return 4101;
	if(input =="aux_6") return 4102;
	if(input =="aux_7") return 4103;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_EventLogLevel(const std::string &input, const YAML::Node& node){
	if(input =="undefined") return 0;
	if(input =="trace") return 1;
	if(input =="debug") return 2;
	if(input =="info") return 3;
	if(input =="warning") return 4;
	if(input =="error") return 5;
	if(input =="safety_violation_error") return 6;
	if(input =="fatal_error") return 7;
	if(input =="emergency_error") return 8;
	if(input =="catastrophic_error") return 9;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_MeshType(const std::string &input, const YAML::Node& node){
	if(input =="mesh") return 0;
	if(input =="convex_mesh") return 1;
	if(input =="sdf_mesh") return 2;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_GpsMeasurementStatusCode(const std::string &input, const YAML::Node& node){
	if(input =="no_fix") return -1;
	if(input =="fix") return 0;
	if(input =="sbas_fix") return 1;
	if(input =="gbas_fix") return 2;
	if(input =="dgps_fix") return 18;
	if(input =="waas_fix") return 33;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_GpsMeasureSourceFlags(const std::string &input, const YAML::Node& node){
	if(input =="none") return 0;
	if(input =="gps") return 1;
	if(input =="points") return 2;
	if(input =="doppler") return 4;
	if(input =="altimeter") return 8;
	if(input =="magnetic") return 16;
	if(input =="gyro") return 32;
	if(input =="accel") return 64;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_GpsCovarianceTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="approximated") return 1;
	if(input =="diagonal_known") return 2;
	if(input =="known") return 3;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JoystickCapabilities(const std::string &input, const YAML::Node& node){
	if(input =="none") return 0;
	if(input =="rumble") return 1;
	if(input =="force_feedback") return 2;
	if(input =="standard_gamepad") return 4;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_GamepadButtons(const std::string &input, const YAML::Node& node){
	if(input =="button_A") return 1;
	if(input =="button_B") return 2;
	if(input =="button_X") return 4;
	if(input =="button_Y") return 8;
	if(input =="button_back") return 16;
	if(input =="button_guide") return 32;
	if(input =="button_start") return 64;
	if(input =="button_left_stick") return 128;
	if(input =="button_right_stick") return 256;
	if(input =="button_left_shoulder") return 512;
	if(input =="button_right_shoulder") return 1024;
	if(input =="button_dpad_up") return 2048;
	if(input =="button_dpad_down") return 4096;
	if(input =="button_dpad_left") return 8192;
	if(input =="button_dpad_right") return 16384;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JoystickHatState(const std::string &input, const YAML::Node& node){
	if(input =="hat_centered") return 0;
	if(input =="hat_up") return 1;
	if(input =="hat_right") return 2;
	if(input =="hat_down") return 4;
	if(input =="hat_left") return 8;
	if(input =="hat_rightup") return 3;
	if(input =="hat_rightdown") return 6;
	if(input =="hat_leftup") return 9;
	if(input =="hat_leftdown") return 12;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ImageEncoding(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="rgb888") return 4096;
	if(input =="rgba8888") return 4097;
	if(input =="bgr888") return 4098;
	if(input =="bgra8888") return 4099;
	if(input =="rgba16_16_16_16") return 4100;
	if(input =="bgra16_16_16_16") return 4101;
	if(input =="mono8") return 8192;
	if(input =="mono16") return 8193;
	if(input =="mono32") return 8194;
	if(input =="mono_f16") return 8195;
	if(input =="mono_f32") return 8196;
	if(input =="mono_f64") return 8197;
	if(input =="bayer_rggb8888") return 12288;
	if(input =="bayer_bggr8888") return 12289;
	if(input =="bayer_gbrg8888") return 12290;
	if(input =="bayer_grbg8888") return 12291;
	if(input =="depth_u16") return 16384;
	if(input =="depth_i16") return 16385;
	if(input =="depth_u32") return 16386;
	if(input =="depth_i32") return 16387;
	if(input =="depth_u64") return 16388;
	if(input =="depth_i64") return 16389;
	if(input =="depth_f32") return 16390;
	if(input =="depth_f64") return 16391;
	if(input =="freeform") return 20480;
	if(input =="compressed") return 24576;
	if(input =="other") return 32768;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_TriggerMode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="software") return 1;
	if(input =="continuous") return 2;
	if(input =="external") return 3;
	if(input =="aux1") return 4;
	if(input =="aux2") return 5;
	if(input =="aux3") return 6;
	if(input =="aux4") return 7;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_Capabilities(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="still") return 1;
	if(input =="stream") return 2;
	if(input =="preview") return 4;
	if(input =="software_trigger") return 16;
	if(input =="continuous_trigger") return 32;
	if(input =="external_trigger") return 64;
	if(input =="aux_trigger") return 128;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_CameraStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="ready") return 1;
	if(input =="streaming") return 2;
	if(input =="warning") return 4;
	if(input =="error") return 8;
	if(input =="fatal_error") return 16;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_OcTreeEncoding(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="octomap_ot") return 1;
	if(input =="octomap_bt") return 2;
	if(input =="other") return 3;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointPositionUnits(const std::string &input, const YAML::Node& node){
	if(input =="implicit") return 0;
	if(input =="meter") return 1;
	if(input =="radian") return 2;
	if(input =="degree") return 3;
	if(input =="ticks_lin") return 4;
	if(input =="ticks_rot") return 5;
	if(input =="nanoticks_lin") return 6;
	if(input =="nanoticks_rot") return 7;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointVelocityUnits(const std::string &input, const YAML::Node& node){
	if(input =="implicit") return 0;
	if(input =="meter_second") return 16;
	if(input =="radian_second") return 17;
	if(input =="degree_second") return 18;
	if(input =="ticks_lin_second") return 19;
	if(input =="ticks_rot_second") return 20;
	if(input =="nanoticks_lin_second") return 21;
	if(input =="nanoticks_rot_second") return 22;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointAccelerationUnits(const std::string &input, const YAML::Node& node){
	if(input =="implicit") return 0;
	if(input =="meter_second2") return 32;
	if(input =="radian_second2") return 33;
	if(input =="degree_second2") return 34;
	if(input =="ticks_lin_second2") return 35;
	if(input =="ticks_rot_second2") return 36;
	if(input =="nanoticks_lin_second2") return 37;
	if(input =="nanoticks_rot_second2") return 38;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointJerkUnits(const std::string &input, const YAML::Node& node){
	if(input =="implicit") return 0;
	if(input =="meter_second2") return 48;
	if(input =="radian_second3") return 49;
	if(input =="degree_second3") return 50;
	if(input =="ticks_lin_second3") return 51;
	if(input =="ticks_rot_second3") return 52;
	if(input =="nanoticks_lin_second3") return 53;
	if(input =="nanoticks_rot_second3") return 54;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointEffortUnits(const std::string &input, const YAML::Node& node){
	if(input =="implicit") return 0;
	if(input =="newton") return 64;
	if(input =="newton_meter") return 65;
	if(input =="ampere") return 66;
	if(input =="volt") return 67;
	if(input =="pascal") return 68;
	if(input =="coulomb") return 69;
	if(input =="tesla") return 70;
	if(input =="weber") return 71;
	if(input =="meter_second2") return 72;
	if(input =="radian_second2") return 73;
	if(input =="degree_second2") return 74;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_JointType(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="revolute") return 1;
	if(input =="continuous") return 2;
	if(input =="prismatic") return 3;
	if(input =="wheel") return 4;
	if(input =="screw") return 5;
	if(input =="other") return 6;
	if(input =="revolute2") return 7;
	if(input =="universal") return 8;
	if(input =="ball") return 9;
	if(input =="planar") return 10;
	if(input =="floating") return 11;
	if(input =="other_compound") return 12;
	if(input =="fixed") return 13;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="serial") return 1;
	if(input =="dual_arm") return 2;
	if(input =="differential_drive") return 3;
	if(input =="planar") return 4;
	if(input =="floating") return 5;
	if(input =="freeform") return 6;
	if(input =="other") return 7;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotCommandMode(const std::string &input, const YAML::Node& node){
	if(input =="invalid_state") return -1;
	if(input =="halt") return 0;
	if(input =="jog") return 1;
	if(input =="trajectory") return 2;
	if(input =="position_command") return 3;
	if(input =="velocity_command") return 4;
	if(input =="homing") return 5;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotOperationalMode(const std::string &input, const YAML::Node& node){
	if(input =="undefined") return 0;
	if(input =="manual_reduced_speed") return 1;
	if(input =="manual_full_speed") return 2;
	if(input =="auto") return 3;
	if(input =="cobot") return 4;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotControllerState(const std::string &input, const YAML::Node& node){
	if(input =="undefined") return 0;
	if(input =="init") return 1;
	if(input =="motor_on") return 2;
	if(input =="motor_off") return 3;
	if(input =="guard_stop") return 4;
	if(input =="emergency_stop") return 5;
	if(input =="emergency_stop_reset") return 6;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotCapabilities(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="jog_command") return 1;
	if(input =="trajectory_command") return 2;
	if(input =="position_command") return 4;
	if(input =="velocity_command") return 8;
	if(input =="homing_command") return 16;
	if(input =="software_reset_errors") return 32;
	if(input =="software_enable") return 64;
	if(input =="interpolated_trajectory") return 128;
	if(input =="raster_trajectory") return 256;
	if(input =="trajectory_queueing") return 512;
	if(input =="speed_ratio") return 1024;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_RobotStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="error") return 1;
	if(input =="fatal_error") return 2;
	if(input =="estop") return 4;
	if(input =="estop_button1") return 8;
	if(input =="estop_button2") return 16;
	if(input =="estop_button3") return 32;
	if(input =="estop_button4") return 64;
	if(input =="estop_guard1") return 128;
	if(input =="estop_guard2") return 256;
	if(input =="estop_guard3") return 512;
	if(input =="estop_guard4") return 1024;
	if(input =="estop_software") return 2048;
	if(input =="estop_fault") return 4096;
	if(input =="estop_internal") return 8192;
	if(input =="estop_other") return 16384;
	if(input =="estop_released") return 32768;
	if(input =="enabling_switch") return 65536;
	if(input =="enabled") return 131072;
	if(input =="ready") return 262144;
	if(input =="homed") return 524288;
	if(input =="homing_required") return 1048576;
	if(input =="communication_failure") return 2097152;
	if(input =="valid_position_command") return 16777216;
	if(input =="valid_velocity_command") return 33554432;
	if(input =="trajectory_running") return 67108864;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ToolTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="basic_gripper") return 1;
	if(input =="basic_continuous_gripper") return 2;
	if(input =="pneumatic_gripper") return 3;
	if(input =="electric_gripper") return 4;
	if(input =="vacuum_gripper") return 5;
	if(input =="soft_gripper") return 6;
	if(input =="welder") return 7;
	if(input =="hand") return 8;
	if(input =="palletizer") return 9;
	if(input =="other") return 10;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ToolCapabilities(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="open_close_command") return 1;
	if(input =="continuous_command") return 2;
	if(input =="homing_command") return 4;
	if(input =="software_reset_errors") return 8;
	if(input =="software_enable") return 16;
	if(input =="sensor_feedback") return 32;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ToolStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="error") return 1;
	if(input =="fatal_error") return 2;
	if(input =="estop") return 4;
	if(input =="communication_failure") return 8;
	if(input =="enabled") return 16;
	if(input =="ready") return 32;
	if(input =="opened") return 64;
	if(input =="closed") return 128;
	if(input =="between") return 256;
	if(input =="actuating") return 512;
	if(input =="homing") return 1024;
	if(input =="requires_homing") return 2048;
	if(input =="homed") return 4096;
	if(input =="gripping") return 8192;
	if(input =="missed") return 16384;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_InterpolationMode(const std::string &input, const YAML::Node& node){
	if(input =="default") return 0;
	if(input =="joint") return 1;
	if(input =="linear") return 2;
	if(input =="cylindrical") return 3;
	if(input =="spherical") return 4;
	if(input =="joint_cubic_spline") return 5;
	if(input =="cubic_spline") return 6;
	if(input =="custom") return 7;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_TrajectoryWaypointType(const std::string &input, const YAML::Node& node){
	if(input =="unspecified") return 0;
	if(input =="start") return 1;
	if(input =="path") return 2;
	if(input =="goal") return 3;
	if(input =="intermediate_stop") return 4;
	if(input =="raster") return 5;
	if(input =="other") return 6;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_SensorTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="generic_digital") return 1;
	if(input =="generic_analog") return 2;
	if(input =="pushbutton") return 3;
	if(input =="dial") return 4;
	if(input =="limitswitch") return 5;
	if(input =="infrared") return 6;
	if(input =="pressure") return 7;
	if(input =="vacuum") return 8;
	if(input =="temperature") return 9;
	if(input =="humidity") return 10;
	if(input =="level") return 11;
	if(input =="contact") return 12;
	if(input =="ultrasonic") return 13;
	if(input =="magnetic") return 14;
	if(input =="encoder") return 15;
	if(input =="potentiometer") return 16;
	if(input =="resolver") return 17;
	if(input =="linear_encoder") return 18;
	if(input =="linear_potentiometer") return 19;
	if(input =="lvds") return 20;
	if(input =="accelerometer") return 21;
	if(input =="gyroscopic") return 22;
	if(input =="velocity") return 23;
	if(input =="angular_velocity") return 24;
	if(input =="spatial_velocity") return 25;
	if(input =="torque") return 26;
	if(input =="force") return 27;
	if(input =="proximity") return 28;
	if(input =="voltage") return 29;
	if(input =="current") return 30;
	if(input =="laser") return 31;
	if(input =="flow") return 32;
	if(input =="pyrometer") return 33;
	if(input =="forcetorque") return 34;
	if(input =="light_color") return 35;
	if(input =="light_intensity") return 36;
	if(input =="object_color") return 37;
	if(input =="altitude") return 38;
	if(input =="generic_word") return 39;
	if(input =="generic_vector") return 40;
	if(input =="position") return 41;
	if(input =="angle") return 42;
	if(input =="acceleration") return 43;
	if(input =="angular_acceleration") return 44;
	if(input =="inclinometer") return 45;
	if(input =="tilt") return 46;
	if(input =="motion") return 47;
	if(input =="radiation") return 48;
	if(input =="photoelectric") return 49;
	if(input =="leak") return 50;
	if(input =="chemical") return 51;
	if(input =="particle") return 52;
	if(input =="metal") return 53;
	if(input =="smoke") return 54;
	if(input =="flame") return 55;
	if(input =="vibration") return 56;
	if(input =="mark") return 57;
	if(input =="contamination") return 58;
	if(input =="inertial") return 59;
	if(input =="magnetometer") return 60;
	if(input =="navigation") return 61;
	if(input =="tactile") return 62;
	if(input =="meteorological") return 63;
	if(input =="horizon") return 64;
	if(input =="sun") return 65;
	if(input =="star") return 66;
	if(input =="moon") return 67;
	if(input =="attitude") return 68;
	if(input =="airspeed") return 69;
	if(input =="distance") return 70;
	if(input =="heading") return 71;
	if(input =="safety") return 72;
	if(input =="door") return 73;
	if(input =="security") return 74;
	if(input =="other") return 32768;
	if(input =="vendor_defined") return 524288;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_SensorDataFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="enabled") return 1;
	if(input =="streaming") return 2;
	if(input =="calibrated") return 4;
	if(input =="calibration_error") return 8;
	if(input =="out_of_range") return 16;
	if(input =="out_of_range_high") return 32;
	if(input =="out_of_range_low") return 64;
	if(input =="warning") return 128;
	if(input =="error") return 256;
	if(input =="fatal_error") return 512;
	if(input =="ready") return 1024;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ServoTypeCode(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="generic_revolute") return 1;
	if(input =="generic_prismatic") return 2;
	if(input =="revolute_electric") return 3;
	if(input =="prismatic_electric") return 4;
	if(input =="rc_servo") return 5;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ServoCapabilities(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="position_command") return 1;
	if(input =="velocity_command") return 2;
	if(input =="effort_command") return 4;
	if(input =="trapezoidal_command") return 8;
	if(input =="signals") return 4096;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ServoMode(const std::string &input, const YAML::Node& node){
	if(input =="error") return -2;
	if(input =="disabled") return -1;
	if(input =="halt") return 0;
	if(input =="position_command") return 1;
	if(input =="velocity_command") return 2;
	if(input =="effort_command") return 3;
	if(input =="trapezoidal_command") return 4;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_ServoStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="ready") return 1;
	if(input =="streaming") return 2;
	if(input =="warning") return 4;
	if(input =="error") return 8;
	if(input =="fatal_error") return 16;
	if(input =="e_stop") return 32;
	if(input =="homed") return 64;
	if(input =="homing_required") return 128;
	if(input =="communication_failure") return 256;
	if(input =="valid_command") return 512;
	if(input =="enabled") return 1024;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_SignalType(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="digital") return 1;
	if(input =="analog") return 2;
	if(input =="digital_port") return 3;
	if(input =="analog_port") return 4;
	if(input =="vector3") return 5;
	if(input =="vector6") return 6;
	if(input =="wrench") return 7;
	if(input =="pose") return 8;
	if(input =="transform") return 9;
	if(input =="other") return 10;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_SignalAccessLevel(const std::string &input, const YAML::Node& node){
	if(input =="undefined") return 0;
	if(input =="internal") return 1;
	if(input =="restricted") return 2;
	if(input =="readonly") return 3;
	if(input =="all") return 4;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

int string_to_enum_SignalDeviceStateFlags(const std::string &input, const YAML::Node& node){
	if(input =="unknown") return 0;
	if(input =="ready") return 1;
	if(input =="streaming") return 2;
	if(input =="warning") return 4;
	if(input =="error") return 8;
	if(input =="fatal_error") return 16;
	if(input =="calibrated") return 32;
	if(input =="calibration_required") return 64;
	if(input =="communication_failure") return 128;
	throw RobotRaconteur::InvalidArgumentException("Invalid enum value");
}

}
}
}
}
