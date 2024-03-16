#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {

	template<> 
	struct convert<com::robotraconteur::gps::GpsStatusPtr>{
		static Node encode(const com::robotraconteur::gps::GpsStatusPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::gps::GpsStatusPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsStatus); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->satellites_used = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"satellites_used",true);
			rhs->satellite_used_prn = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_used_prn",true,true,0);
			rhs->satellites_visible = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"satellites_visible",true);
			rhs->satellite_visible_prn = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_prn",true,true,0);
			rhs->satellite_visible_z = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_z",true,true,0);
			rhs->satellite_visible_azimuth = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_azimuth",true,true,0);
			rhs->satellite_visible_snr = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array<int32_t>(node,"satellite_visible_snr",true,true,0);
			rhs->status_code = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::gps::GpsMeasurementStatusCode::GpsMeasurementStatusCode>(node,"status_code",true);
			rhs->motion_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"motion_source_flags",true);
			rhs->orientation_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"orientation_source_flags",true);
			rhs->position_source_flags = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint16_t>(node,"position_source_flags",true);
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::gps::GpsStatePtr>{
		static Node encode(const com::robotraconteur::gps::GpsStatePtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::gps::GpsStatePtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::gps::GpsState); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->status = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::gps::GpsStatusPtr>(node,"status",true);
			// TODO: parse field com.robotraconteur.datetime.DateTimeUTC time
			rhs->latitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"latitude_deg",true);
			rhs->longitude_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"longitude_deg",true);
			rhs->altitude = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"altitude",true);
			rhs->track_deg = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"track_deg",true);
			rhs->speed = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"speed",true);
			rhs->climb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"climb",true);
			rhs->pitch = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"pitch",true);
			rhs->roll = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"roll",true);
			rhs->dip = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"dip",true);
			rhs->gdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"gdop",true);
			rhs->pdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"pdop",true);
			rhs->hdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"hdop",true);
			rhs->vdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"vdop",true);
			rhs->tdop = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"tdop",true);
			rhs->err = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err",true);
			rhs->err_horz = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_horz",true);
			rhs->err_track = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_track",true);
			rhs->err_speed = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_speed",true);
			rhs->err_climb = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_climb",true);
			rhs->err_time = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_time",true);
			rhs->err_pitch = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_pitch",true);
			rhs->err_roll = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_roll",true);
			rhs->err_dip = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"err_dip",true);
			rhs->position_covariance = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_multidimarray<double>(node,"position_covariance",true,3,3);
			rhs->position_covariance_type = RobotRaconteur::Companion::InfoParser::yaml::parse_enum<com::robotraconteur::gps::GpsCovarianceTypeCode::GpsCovarianceTypeCode>(node,"position_covariance_type",true);
			return true;
		}
	};



}