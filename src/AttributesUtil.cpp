/**
 * @file AttributesUtil.cpp
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2024 Wason Technology, LLC
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

#include "RobotRaconteurCompanion/Util/AttributesUtil.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
namespace detail
{
bool TryAddIdentifier(std::map<std::string, RobotRaconteur::RRValuePtr>& o, const std::string& name,
                      const com::robotraconteur::identifier::IdentifierPtr& id)
{
    if (!IsIdentifierAny(id))
    {
        o.insert(std::make_pair(name, RobotRaconteur::stringToRRArray(IdentifierToString(id))));
        return true;
    }
    return false;
}

bool TryAddString(std::map<std::string, RobotRaconteur::RRValuePtr>& o, const std::string& name, const std::string& str)
{
    if (!str.empty())
    {
        o.insert(std::make_pair(name, RobotRaconteur::stringToRRArray(str)));
        return true;
    }
    return false;
}
} // namespace detail

std::map<std::string, RobotRaconteur::RRValuePtr> GetDefaultServiceAttributesFromDeviceInfo(
    const com::robotraconteur::device::DeviceInfoPtr& info)
{
    std::map<std::string, RobotRaconteur::RRValuePtr> o;
    detail::TryAddIdentifier(o, "device", info->device);
    detail::TryAddIdentifier(o, "parent_device", info->parent_device);
    detail::TryAddIdentifier(o, "manufacturer", info->manufacturer);
    detail::TryAddIdentifier(o, "model", info->model);
    detail::TryAddString(o, "serial_number", info->serial_number);
    detail::TryAddString(o, "user_description", info->user_description);
    return o;
}

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
