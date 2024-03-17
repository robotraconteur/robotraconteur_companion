#include "yaml_parser_common_include.h"

#pragma once

namespace YAML
{

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::eventlog::EventLogTypePtr>
{
    static Node encode(const com::robotraconteur::eventlog::EventLogTypePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogTypePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::eventlog::EventLogMessageHeaderPtr>
{
    static Node encode(const com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessageHeaderPtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::eventlog::EventLogMessagePtr>
{
    static Node encode(const com::robotraconteur::eventlog::EventLogMessagePtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogMessagePtr& rhs);
};

template <>
struct ROBOTRACONTEUR_COMPANION_INFOPARSER_API convert<com::robotraconteur::eventlog::EventLogInfoPtr>
{
    static Node encode(const com::robotraconteur::eventlog::EventLogInfoPtr& rhs);
    static bool decode(const Node& node, com::robotraconteur::eventlog::EventLogInfoPtr& rhs);
};

} // namespace YAML
