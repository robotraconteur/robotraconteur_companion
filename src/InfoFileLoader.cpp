/**
 * @file InfoFileLoader.cpp
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

#include "RobotRaconteurCompanion/Util/InfoFileLoader.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
namespace detail
{

bool LoadInfoFile_traits<com::robotraconteur::device::DeviceInfoPtr>::LoadDeviceIdentifier(const com::robotraconteur::device::DeviceInfoPtr& info_file, const std::string& category, std::vector<LocalIdentifierLockPtr>& locks,  const boost::shared_ptr<RobotRaconteur::RobotRaconteurNode>& node)
{
    if (info_file && info_file && info_file->device && !IsIdentifierAnyName(info_file->device) && IsIdentifierAnyUuid(info_file->device))
    {
        LocalIdentifierLockPtr l = GetIdentifierForNameAndLock(category, info_file->device->name, node);
        info_file->device = l->GetIdentifier();
        locks.push_back(l);
        return true;
    }
    return false;
}

}
}
}
}