#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::sensordata::SensorDataHeaderPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataHeaderPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::sensordata::SensorDataSourceInfoPtr>{
		static Node encode(const com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::sensordata::SensorDataSourceInfoPtr& rhs);
	};


}