#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::hid::joystick::JoystickInfoPtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickInfo);
			rhs->device_info = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::device::DeviceInfoPtr>(node,"device_info",true);
			rhs->id = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"id",true);
			rhs->axes_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"axes_count",true);
			rhs->button_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"button_count",true);
			rhs->hat_count = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"hat_count",true);
			rhs->joystick_capabilities = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"joystick_capabilities",true);
			rhs->joystick_device_vendor = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_vendor",true);
			rhs->joystick_device_product = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_product",true);
			rhs->joystick_device_version = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"joystick_device_version",true);
			rhs->joystick_uuid = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::uuid::UUID>(node,"joystick_uuid",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::hid::joystick::JoystickStatePtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickState);
			rhs->axes = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int16_t>(node,"axes",true,true,0);
			rhs->buttons = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"buttons",true,true,0);
			rhs->hats = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<uint8_t>(node,"hats",true,true,0);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::hid::joystick::GamepadStatePtr>{
		static Node encode(const com::robotraconteur::hid::joystick::GamepadStatePtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::hid::joystick::GamepadStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::GamepadState);
			rhs->left_x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"left_x",true);
			rhs->left_y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"left_y",true);
			rhs->right_x = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"right_x",true);
			rhs->right_y = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"right_y",true);
			rhs->trigger_left = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"trigger_left",true);
			rhs->trigger_right = RobotRaconteur::Companion::InfoParser::yaml::parse_number<int16_t>(node,"trigger_right",true);
			rhs->buttons = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"buttons",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickStateSensorData);
			rhs->data_header = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::sensordata::SensorDataHeaderPtr>(node,"data_header",true);
			rhs->joystick_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::hid::joystick::JoystickStatePtr>(node,"joystick_state",true);
			rhs->gamepad_state = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::hid::joystick::GamepadStatePtr>(node,"gamepad_state",true);
			return true;
		}
	};



}