/**
 * @file SensorDataUtil.h
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

#include "DateTimeUtil.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

/**
 * @brief Fill in a SensorDataHeader with the current time and sequence number
 *
 * @param node The node to use. If null, the default node is used
 * @param device_info The device info of the device generating the data.
 * @param seqno The sequence number to use
 * @return com::robotraconteur::sensordata::SensorDataHeaderPtr The populated SensorDataHeader
 */
com::robotraconteur::sensordata::SensorDataHeaderPtr FillSensorDataHeader(
    RobotRaconteur::RobotRaconteurNodePtr node, com::robotraconteur::device::DeviceInfoPtr device_info, uint64_t seqno)
{
    com::robotraconteur::sensordata::SensorDataHeaderPtr ret(new com::robotraconteur::sensordata::SensorDataHeader());
    ret->seqno = seqno;
    ret->ts = TimeSpec2Now(node, device_info);
    return ret;
}

} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
