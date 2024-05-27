#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API
    convert<com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr>
{
    static Node encode(const com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::PlumbBobDistortionInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr>
{
    static Node encode(const com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraCalibrationPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::imaging::camerainfo::CameraInfoPtr>
{
    static Node encode(const com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::CameraInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr>
{
    static Node encode(const com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::imaging::camerainfo::MultiCameraInfoPtr& rhs);
};

} // namespace YAML
