#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{
template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBA>
{
    static Node encode(const com::robotraconteur::color::ColorRGBA& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBA& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBAf>
{
    static Node encode(const com::robotraconteur::color::ColorRGBAf& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAf& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBAu>
{
    static Node encode(const com::robotraconteur::color::ColorRGBAu& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAu& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBAh>
{
    static Node encode(const com::robotraconteur::color::ColorRGBAh& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBAh& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGB>
{
    static Node encode(const com::robotraconteur::color::ColorRGB& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGB& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBf>
{
    static Node encode(const com::robotraconteur::color::ColorRGBf& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBf& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBu>
{
    static Node encode(const com::robotraconteur::color::ColorRGBu& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBu& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::color::ColorRGBh>
{
    static Node encode(const com::robotraconteur::color::ColorRGBh& rhs);
    static bool decode(const Node& node, com::robotraconteur::color::ColorRGBh& rhs);
};

} // namespace YAML
