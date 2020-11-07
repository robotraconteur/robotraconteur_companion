#pragma once
#include <RobotRaconteur.h>
#include "yaml-cpp/yaml.h"
#include <boost/uuid/uuid_io.hpp>
#include "robotraconteur_generated.h"
#include "yaml_loader_enums.h"

using namespace RobotRaconteur;
using namespace Companion;
using namespace boost;

namespace RR = RobotRaconteur;

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::hid::joystick::JoystickInfoPtr>{
		static Node encode(const com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::hid::joystick::JoystickInfoPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::hid::joystick::JoystickInfo);
			if(node["device_info"]){
				rhs->device_info = node["device_info"].as<com::robotraconteur::device::DeviceInfoPtr>();
			}
			if(node["id"]){
				rhs->id = node["id"].as<uint32_t>();
			}
			if(node["axes_count"]){
				rhs->axes_count = node["axes_count"].as<uint32_t>();
			}
			if(node["button_count"]){
				rhs->button_count = node["button_count"].as<uint32_t>();
			}
			if(node["hat_count"]){
				rhs->hat_count = node["hat_count"].as<uint32_t>();
			}
			if(node["joystick_capabilities"]){
				rhs->joystick_capabilities = node["joystick_capabilities"].as<uint32_t>();
			}
			if(node["joystick_device_vendor"]){
				rhs->joystick_device_vendor = node["joystick_device_vendor"].as<uint16_t>();
			}
			if(node["joystick_device_product"]){
				rhs->joystick_device_product = node["joystick_device_product"].as<uint16_t>();
			}
			if(node["joystick_device_version"]){
				rhs->joystick_device_version = node["joystick_device_version"].as<uint16_t>();
			}
			if(node["joystick_uuid"]){
				rhs->joystick_uuid = node["joystick_uuid"].as<com::robotraconteur::uuid::UUID>();
			}
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
			if(node["axes"]){
				RRArrayPtr<int16_t> my_array = AllocateEmptyRRArray<int16_t>(node["axes"].size());
				for (int i = 0; i < node["axes"].size(); i++) {
					my_array->at(i) = node["axes"][i].as<int16_t>();
				}
				rhs->axes = my_array;
			}
			if(node["buttons"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["buttons"].size());
				for (int i = 0; i < node["buttons"].size(); i++) {
					my_array->at(i) = node["buttons"][i].as<uint8_t>();
				}
				rhs->buttons = my_array;
			}
			if(node["hats"]){
				RRArrayPtr<uint8_t> my_array = AllocateEmptyRRArray<uint8_t>(node["hats"].size());
				for (int i = 0; i < node["hats"].size(); i++) {
					my_array->at(i) = node["hats"][i].as<uint8_t>();
				}
				rhs->hats = my_array;
			}
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
			if(node["left_x"]){
				rhs->left_x = node["left_x"].as<int16_t>();
			}
			if(node["left_y"]){
				rhs->left_y = node["left_y"].as<int16_t>();
			}
			if(node["right_x"]){
				rhs->right_x = node["right_x"].as<int16_t>();
			}
			if(node["right_y"]){
				rhs->right_y = node["right_y"].as<int16_t>();
			}
			if(node["trigger_left"]){
				rhs->trigger_left = node["trigger_left"].as<int16_t>();
			}
			if(node["trigger_right"]){
				rhs->trigger_right = node["trigger_right"].as<int16_t>();
			}
			if(node["buttons"]){
				rhs->buttons = node["buttons"].as<uint16_t>();
			}
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
			if(node["data_header"]){
				rhs->data_header = node["data_header"].as<com::robotraconteur::sensordata::SensorDataHeaderPtr>();
			}
			return true;
		}
	};


//TODO: Fix the following structures or namedarrays: 
// com::robotraconteur::hid::joystick::JoystickStateSensorData 

}