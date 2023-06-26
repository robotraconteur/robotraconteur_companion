#include "IdentifierUtil.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
namespace detail
{
    static bool TryAddIdentifier(std::map<std::string,RobotRaconteur::RRValuePtr>& o, const std::string& name, const com::robotraconteur::identifier::IdentifierPtr& id)
    {
        if (!IsIdentifierAny(id))
        {
            o.insert(std::make_pair(name, RobotRaconteur::stringToRRArray(IdentifierToString(id))));
            return true;
        }
        return false;
    }

    static bool TryAddString(std::map<std::string,RobotRaconteur::RRValuePtr>& o, const std::string& name, const std::string& str)
    {
        if (!str.empty())
        {
            o.insert(std::make_pair(name, RobotRaconteur::stringToRRArray(str)));
            return true;
        }
        return false;
    }
}

/**
 * @brief Get the Default Service Attributes From Device Info object
 * 
 * Get the default attributes from a DeviceInfo object. These attributes are
 * used to populate the default service attributes when registering a service
 * with a device.
 * 
 * The following attributes are used:
 * 
 * - device
 * - parent_device
 * - manufacturer
 * - model
 * - serial_number
 * - user_description
 *  
 * @param info The DeviceInfo object
 * @return std::map<std::string,RobotRaconteur::RRValuePtr> The default attributes
 */
static std::map<std::string,RobotRaconteur::RRValuePtr> GetDefaultServiceAttributesFromDeviceInfo(const com::robotraconteur::device::DeviceInfoPtr& info)
{
    std::map<std::string,RobotRaconteur::RRValuePtr> o;
    detail::TryAddIdentifier(o,"device", info->device);
    detail::TryAddIdentifier(o, "parent_device", info->parent_device);
    detail::TryAddIdentifier(o, "manufacturer", info->manufacturer);
    detail::TryAddIdentifier(o, "model", info->model);
    detail::TryAddString(o, "serial_number", info->serial_number);
    detail::TryAddString(o, "user_description", info->user_description);
    return o;
}

}
}
}