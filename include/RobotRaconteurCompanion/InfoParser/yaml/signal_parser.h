#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::signal::SignalInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::signal::SignalInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::signal::SignalDeviceStatePtr>{
		static Node encode(const com::robotraconteur::signal::SignalDeviceStatePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::signal::SignalDeviceStatePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::signal::SignalGroupInfoPtr>{
		static Node encode(const com::robotraconteur::signal::SignalGroupInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::signal::SignalGroupInfoPtr& rhs);
	};


}