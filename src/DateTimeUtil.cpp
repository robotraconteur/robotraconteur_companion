/**
 * @file DateTimeUtil.cpp
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

#include "RobotRaconteurCompanion/Util/DateTimeUtil.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

com::robotraconteur::datetime::DateTimeUTC UtcNow(const RobotRaconteur::RobotRaconteurNodePtr& node,
                                                  const com::robotraconteur::device::DeviceInfoPtr& info)
{
    RobotRaconteur::RobotRaconteurNodePtr node1 = node;
    if (!node1)
    {
        node1 = RobotRaconteur::RobotRaconteurNode::sp();
    }

    RobotRaconteur::TimeSpec now = RobotRaconteur::ptimeToTimeSpec(node1->NowUTC());
    com::robotraconteur::datetime::DateTimeUTC ret{};
    ret.seconds = now.seconds;
    ret.nanoseconds = now.nanoseconds;
    ret.clock_info.clock_type = (int)com::robotraconteur::datetime::ClockTypeCode::default_;
    if (info)
    {
        if (info->device)
        {
            ret.clock_info.clock_uuid.a = info->device->uuid.a;
        }
    }

    return ret;
}

com::robotraconteur::datetime::TimeSpec2 TimeSpec2Now(const RobotRaconteur::RobotRaconteurNodePtr& node,
                                                      const com::robotraconteur::device::DeviceInfoPtr& info)
{
    RobotRaconteur::RobotRaconteurNodePtr node1 = node;
    if (!node1)
    {
        node1 = RobotRaconteur::RobotRaconteurNode::sp();
    }

    RobotRaconteur::TimeSpec now = node1->NowTimeSpec();
    com::robotraconteur::datetime::TimeSpec2 ret{};
    ret.seconds = now.seconds;
    ret.nanoseconds = now.nanoseconds;
    ret.clock_info.clock_type = (int)com::robotraconteur::datetime::ClockTypeCode::default_;
    if (info)
    {
        if (info->device)
        {
            ret.clock_info.clock_uuid.a = info->device->uuid.a;
        }
    }

    return ret;
}

com::robotraconteur::datetime::TimeSpec3 TimeSpec3Now(const RobotRaconteur::RobotRaconteurNodePtr& node)
{
    RobotRaconteur::RobotRaconteurNodePtr node1 = node;
    if (!node1)
    {
        node1 = RobotRaconteur::RobotRaconteurNode::sp();
    }

    RobotRaconteur::TimeSpec now = node1->NowTimeSpec();
    com::robotraconteur::datetime::TimeSpec3 ret{};
    ret.s.microseconds = now.seconds * 1000000 + now.nanoseconds / 1000;
    return ret;
}

com::robotraconteur::device::clock::DeviceTime FillDeviceTime(
    const RobotRaconteur::RobotRaconteurNodePtr& node, const com::robotraconteur::device::DeviceInfoPtr& device_info,
    uint64_t seqno)
{
    com::robotraconteur::device::clock::DeviceTime ret{};
    ret.device_seqno = seqno;
    ret.device_ts = TimeSpec2Now(node, device_info);
    ret.device_utc = UtcNow(node, device_info);
    return ret;
}

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
