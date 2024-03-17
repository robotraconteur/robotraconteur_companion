#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceOptionPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceOptionPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceOptionPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceSubOptionPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceSubOptionPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceSubOptionPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceCapabilityPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceCapabilityPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceCapabilityPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceSubCapabilityPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceSubCapabilityPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceSubCapabilityPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceClassPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceClassPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceClassPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::device::DeviceInfoPtr>
{
    static Node encode(const com::robotraconteur::device::DeviceInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::device::DeviceInfoPtr& rhs);
};

} // namespace YAML
