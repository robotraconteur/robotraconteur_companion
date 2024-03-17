#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::FiducialPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::FiducialInfoPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::RecognizedFiducialPtr>{
		static Node encode(const com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::RecognizedFiducialsPtr>{
		static Node encode(const com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::RecognizedFiducialsPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::FiducialSensorInfoPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorInfoPtr& rhs);
	};


	template<> 
	struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::fiducial::FiducialSensorDataPtr>{
		static Node encode(const com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs);
		static bool decode(const Node& node, com::robotraconteur::fiducial::FiducialSensorDataPtr& rhs);
	};


}