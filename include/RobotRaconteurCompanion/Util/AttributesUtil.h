/**
 * @file AttributesUtil.h
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2023 Wason Technology, LLC
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * @par
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "IdentifierUtil.h"
#include "UtilMacros.h"

#include "com__robotraconteur__device.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
namespace detail
{
ROBOTRACONTEUR_COMPANION_UTIL_API bool TryAddIdentifier(std::map<std::string, RobotRaconteur::RRValuePtr>& o,
                                                        const std::string& name,
                                                        const com::robotraconteur::identifier::IdentifierPtr& id);

ROBOTRACONTEUR_COMPANION_UTIL_API bool TryAddString(std::map<std::string, RobotRaconteur::RRValuePtr>& o,
                                                    const std::string& name, const std::string& str);
} // namespace detail

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
ROBOTRACONTEUR_COMPANION_UTIL_API std::map<std::string, RobotRaconteur::RRValuePtr>
GetDefaultServiceAttributesFromDeviceInfo(const com::robotraconteur::device::DeviceInfoPtr& info);

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
