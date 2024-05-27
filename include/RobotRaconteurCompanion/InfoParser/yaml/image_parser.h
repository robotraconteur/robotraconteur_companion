#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{
template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::PixelRGB>
{
    static Node encode(const com::robotraconteur::image::PixelRGB& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::PixelRGB& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::PixelRGBA>
{
    static Node encode(const com::robotraconteur::image::PixelRGBA& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::PixelRGBA& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::PixelRGBFloatPacked>
{
    static Node encode(const com::robotraconteur::image::PixelRGBFloatPacked& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPacked& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::PixelRGBFloatPackedf>
{
    static Node encode(const com::robotraconteur::image::PixelRGBFloatPackedf& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::PixelRGBFloatPackedf& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::ImageInfoPtr>
{
    static Node encode(const com::robotraconteur::image::ImageInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::ImageInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::FreeformImageInfoPtr>
{
    static Node encode(const com::robotraconteur::image::FreeformImageInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::FreeformImageInfoPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::ImagePtr>
{
    static Node encode(const com::robotraconteur::image::ImagePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::ImagePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::CompressedImagePtr>
{
    static Node encode(const com::robotraconteur::image::CompressedImagePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::FreeformImagePtr>
{
    static Node encode(const com::robotraconteur::image::FreeformImagePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::ImagePartPtr>
{
    static Node encode(const com::robotraconteur::image::ImagePartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::ImagePartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::CompressedImagePartPtr>
{
    static Node encode(const com::robotraconteur::image::CompressedImagePartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::CompressedImagePartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::FreeformImagePartPtr>
{
    static Node encode(const com::robotraconteur::image::FreeformImagePartPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::FreeformImagePartPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::image::ImageResourcePtr>
{
    static Node encode(const com::robotraconteur::image::ImageResourcePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::image::ImageResourcePtr& rhs);
};

} // namespace YAML
