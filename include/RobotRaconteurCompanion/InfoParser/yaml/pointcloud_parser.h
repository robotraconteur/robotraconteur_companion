#include "yaml_parser_common_include.h"

#pragma once

namespace YAML {
	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2Point>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Point& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Point& rhs){
			rhs.s.point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Point>(node,"point",false);
			rhs.s.intensity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"intensity",false);
			rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometry::Vector3>(node,"normal",false);
			rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::image::PixelRGBFloatPacked>(node,"rgb",false);
			rhs.s.moment_invariants = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_na<double,3>(node,"moment_invariants");
			rhs.s.channel = RobotRaconteur::Companion::InfoParser::yaml::parse_number<double>(node,"channel",false);
			return true;
		}
	};

	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2Pointf>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Pointf& rhs){
			rhs.s.point = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Point>(node,"point",false);
			rhs.s.intensity = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"intensity",false);
			rhs.s.normal = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::geometryf::Vector3>(node,"normal",false);
			rhs.s.rgb = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray<com::robotraconteur::image::PixelRGBFloatPackedf>(node,"rgb",false);
			rhs.s.moment_invariants = RobotRaconteur::Companion::InfoParser::yaml::parse_numeric_array_na<float,3>(node,"moment_invariants");
			rhs.s.channel = RobotRaconteur::Companion::InfoParser::yaml::parse_number<float>(node,"channel",false);
			return true;
		}
	};


	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
			rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometry::Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudf); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometryf::Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloudPartfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloudPartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloudPartf); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
			rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::geometryf::Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2Ptr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2Ptr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2PartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Part); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
			rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Point>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2fPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2fPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2f); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Pointf>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::PointCloud2PartfPtr>{
		static Node encode(const com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::PointCloud2PartfPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::PointCloud2Partf); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometryf::BoundingBoxPtr>(node,"bounds",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
			rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
			rhs->points = RobotRaconteur::Companion::InfoParser::yaml::parse_namedarray_array<com::robotraconteur::pointcloud::PointCloud2Pointf>(node,"points",true,true,0);
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::FreeformPointCloudPtr>{
		static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloud); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			// TODO: parse field varvalue points
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



	template<> 
	struct convert<com::robotraconteur::pointcloud::FreeformPointCloudPartPtr>{
		static Node encode(const com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
			RR_UNUSED(rhs);
			Node node;
			return node;
		}

		static bool decode(const Node& node, com::robotraconteur::pointcloud::FreeformPointCloudPartPtr& rhs){
			if (!rhs) rhs.reset(new com::robotraconteur::pointcloud::FreeformPointCloudPart); // NOLINT(cppcoreguidelines-owning-memory)
			rhs->bounds = RobotRaconteur::Companion::InfoParser::yaml::parse_structure<com::robotraconteur::geometry::BoundingBoxPtr>(node,"bounds",true);
			rhs->encoding = RobotRaconteur::Companion::InfoParser::yaml::parse_string(node,"encoding",true);
			rhs->is_dense = RobotRaconteur::Companion::InfoParser::yaml::parse_bool(node,"is_dense",true);
			rhs->points_offset = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_offset",true);
			rhs->points_total_len = RobotRaconteur::Companion::InfoParser::yaml::parse_number<uint32_t>(node,"points_total_len",true);
			// TODO: parse field varvalue points
			// TODO: parse field varvalue{string} extended
			return true;
		}
	};



}