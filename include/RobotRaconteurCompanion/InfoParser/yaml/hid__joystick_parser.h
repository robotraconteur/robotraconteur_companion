#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::hid::joystick::JoystickInfoPtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::hid::joystick::JoystickStatePtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickStatePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStatePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::hid::joystick::GamepadStatePtr>{
		static Node encode(const com::robotraconteur::hid::joystick::GamepadStatePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::hid::joystick::GamepadStatePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr& rhs);
	};


}