/**
 * @file DateTimeUtil.h
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

#include "UuidUtil.h"
#include "com__robotraconteur__datetime.h"
#include "com__robotraconteur__device__clock.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

/**
 * @brief Get the current DateTimeUTC from the node
 * 
 * @param node The node to use. If null, the default node is used
 * @param info The device info to use. If null, the default clock is used
 * @return com::robotraconteur::datetime::DateTimeUTC The current UTC time
 */
static com::robotraconteur::datetime::DateTimeUTC UtcNow(RobotRaconteur::RobotRaconteurNodePtr node, com::robotraconteur::device::DeviceInfoPtr info)
{
    if (!node)
    {
        node = RobotRaconteur::RobotRaconteurNode::sp();        
    }

    RobotRaconteur::TimeSpec now = RobotRaconteur::ptimeToTimeSpec(node->NowUTC());
    com::robotraconteur::datetime::DateTimeUTC ret;
    memset(&ret, 0, sizeof(ret));
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

/**
 * @brief Get the current TimeSpec from the node, stored as TimeSpec2
 * 
 * TimeSpec is based on the performance counter, and is not guaranteed to be
 * synchronized between nodes or with the system real-time clock. It is expected
 * to be close to the system real-time clock, but may drift over time and is 
 * guaranteed to remain stable even if the system real-time clock is changed.
 * 
 * @param node The node to use. If null, the default node is used
 * @param info The device info to use. If null, the default clock is used
 * @return com::robotraconteur::datetime::TimeSpec2 The current TimeSpec as TimeSpec2
 */
static com::robotraconteur::datetime::TimeSpec2 TimeSpec2Now(RobotRaconteur::RobotRaconteurNodePtr node, com::robotraconteur::device::DeviceInfoPtr info)
{
    if (!node)
    {
        node = RobotRaconteur::RobotRaconteurNode::sp();        
    }

    RobotRaconteur::TimeSpec now = node->NowTimeSpec();
    com::robotraconteur::datetime::TimeSpec2 ret;
    memset(&ret, 0, sizeof(ret));
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

/**
 * @brief Get the current TimeSpec from the node, stored as TimeSpec3
 * 
 * The TimeSpec3 is a 64-bit integer representing microseconds since the epoch
 * of the real-time clock. It is intended to be a compact representation of the
 * current time that can be used for timestamping data.
 * 
 * TimeSpec is based on the performance counter, and is not guaranteed to be
 * synchronized between nodes or with the system real-time clock. It is expected
 * to be close to the system real-time clock, but may drift over time and is 
 * guaranteed to remain stable even if the system real-time clock is changed.
 * 
 * @param node The node to use. If null, the default node is used
 * @return com::robotraconteur::datetime::TimeSpec3 The current TimeSpec as TimeSpec3
 */
static com::robotraconteur::datetime::TimeSpec3 TimeSpec3Now(RobotRaconteur::RobotRaconteurNodePtr node)
{
    if (!node)
    {
        node = RobotRaconteur::RobotRaconteurNode::sp();        
    }

    RobotRaconteur::TimeSpec now = node->NowTimeSpec();
    com::robotraconteur::datetime::TimeSpec3 ret;
    ret.s.microseconds = now.seconds*1000000 + now.nanoseconds/1000;    
    return ret;
}

/**
 * @brief Fill a DeviceTime structure with the current time
 * 
 * @param node The node to use. If null, the default node is used
 * @param device_info The device info to use. If null, the default clock is used
 * @param seqno The current sequence number of the device
 * @return com::robotraconteur::device::clock::DeviceTime 
 */
static com::robotraconteur::device::clock::DeviceTime FillDeviceTime(RobotRaconteur::RobotRaconteurNodePtr node, com::robotraconteur::device::DeviceInfoPtr device_info, uint64_t seqno)
{
    com::robotraconteur::device::clock::DeviceTime ret;
    ret.device_seqno = seqno;
    ret.device_ts = TimeSpec2Now(node, device_info);
    ret.device_utc = UtcNow(node, device_info);
    return ret;
}

}
}
}