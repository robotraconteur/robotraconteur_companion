#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionTemplatePtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::objectrecognition::RecognizedObjectPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::objectrecognition::RecognizedObjectsPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::objectrecognition::RecognizedObjectsPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr>{
		static Node encode(const com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::objectrecognition::ObjectRecognitionSensorDataPtr& rhs);
	};


}