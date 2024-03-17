/**
 * @file StdRobDefAll.h
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

#include "com__robotraconteur__action.h"
#include "com__robotraconteur__action_stubskel.h"
#include "com__robotraconteur__actuator.h"
#include "com__robotraconteur__actuator_stubskel.h"
#include "com__robotraconteur__bignum.h"
#include "com__robotraconteur__bignum_stubskel.h"
#include "com__robotraconteur__color.h"
#include "com__robotraconteur__color_stubskel.h"
#include "com__robotraconteur__datatype.h"
#include "com__robotraconteur__datatype_stubskel.h"
#include "com__robotraconteur__datetime.h"
#include "com__robotraconteur__datetime__clock.h"
#include "com__robotraconteur__datetime__clock_stubskel.h"
#include "com__robotraconteur__datetime_stubskel.h"
#include "com__robotraconteur__device.h"
#include "com__robotraconteur__device_stubskel.h"
#include "com__robotraconteur__device__clock.h"
#include "com__robotraconteur__device__clock_stubskel.h"
#include "com__robotraconteur__device__isoch.h"
#include "com__robotraconteur__device__isoch_stubskel.h"
#include "com__robotraconteur__eventlog.h"
#include "com__robotraconteur__eventlog_stubskel.h"
#include "com__robotraconteur__fiducial.h"
#include "com__robotraconteur__fiducial_stubskel.h"
#include "com__robotraconteur__geometry.h"
#include "com__robotraconteur__geometry__shapes.h"
#include "com__robotraconteur__geometry__shapes_stubskel.h"
#include "com__robotraconteur__geometry_stubskel.h"
#include "com__robotraconteur__geometryf.h"
#include "com__robotraconteur__geometryf_stubskel.h"
#include "com__robotraconteur__geometryi.h"
#include "com__robotraconteur__geometryi_stubskel.h"
#include "com__robotraconteur__gps.h"
#include "com__robotraconteur__gps_stubskel.h"
#include "com__robotraconteur__hid__joystick.h"
#include "com__robotraconteur__hid__joystick_stubskel.h"
#include "com__robotraconteur__identifier.h"
#include "com__robotraconteur__identifier_stubskel.h"
#include "com__robotraconteur__image.h"
#include "com__robotraconteur__image_stubskel.h"
#include "com__robotraconteur__imaging.h"
#include "com__robotraconteur__imaging__camerainfo.h"
#include "com__robotraconteur__imaging__camerainfo_stubskel.h"
#include "com__robotraconteur__imaging_stubskel.h"
#include "com__robotraconteur__imu.h"
#include "com__robotraconteur__imu_stubskel.h"
#include "com__robotraconteur__laserscan.h"
#include "com__robotraconteur__laserscan_stubskel.h"
#include "com__robotraconteur__laserscanner.h"
#include "com__robotraconteur__laserscanner_stubskel.h"
#include "com__robotraconteur__lighting.h"
#include "com__robotraconteur__objectrecognition.h"
#include "com__robotraconteur__objectrecognition_stubskel.h"
#include "com__robotraconteur__lighting_stubskel.h"
#include "com__robotraconteur__octree.h"
#include "com__robotraconteur__octree_stubskel.h"
#include "com__robotraconteur__param.h"
#include "com__robotraconteur__param_stubskel.h"
#include "com__robotraconteur__pid.h"
#include "com__robotraconteur__pid_stubskel.h"
#include "com__robotraconteur__pointcloud.h"
#include "com__robotraconteur__pointcloud__sensor.h"
#include "com__robotraconteur__pointcloud__sensor_stubskel.h"
#include "com__robotraconteur__pointcloud_stubskel.h"
#include "com__robotraconteur__resource.h"
#include "com__robotraconteur__resource_stubskel.h"
#include "com__robotraconteur__resource__device.h"
#include "com__robotraconteur__resource__device_stubskel.h"
#include "com__robotraconteur__robotics__joints.h"
#include "com__robotraconteur__robotics__joints_stubskel.h"
#include "com__robotraconteur__robotics__payload.h"
#include "com__robotraconteur__robotics__payload_stubskel.h"
#include "com__robotraconteur__robotics__robot.h"
#include "com__robotraconteur__robotics__robot_stubskel.h"
#include "com__robotraconteur__robotics__tool.h"
#include "com__robotraconteur__robotics__tool_stubskel.h"
#include "com__robotraconteur__robotics__trajectory.h"
#include "com__robotraconteur__robotics__trajectory_stubskel.h"
#include "com__robotraconteur__sensor.h"
#include "com__robotraconteur__sensor_stubskel.h"
#include "com__robotraconteur__sensordata.h"
#include "com__robotraconteur__sensordata_stubskel.h"
#include "com__robotraconteur__servo.h"
#include "com__robotraconteur__servo_stubskel.h"
#include "com__robotraconteur__signal.h"
#include "com__robotraconteur__signal_stubskel.h"
#include "com__robotraconteur__units.h"
#include "com__robotraconteur__units_stubskel.h"
#include "com__robotraconteur__uuid.h"
#include "com__robotraconteur__uuid_stubskel.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{

    /**
     * @brief Register standard robdef service types to the specified node
     * 
     * Service types must be registered to the node before they can be used in C++.
     * When generating files directly with the `ROBOTRACONTEUR_GEN_THUNK_SOURCE`, the 
     * master header will contain the types that were generated, but not imported types.
     * Since the standard types are typically imported using the `AUTO_IMPORT` option,
     * they will not be included in the master header. Use this function before node
     * setup to register the standard types.
     * 
     * @param node The node to register service types to
     */
    ROBOTRACONTEUR_COMPANION_STDROBDEF_API void RegisterStdRobDefServiceTypes(const RR_SHARED_PTR<RobotRaconteurNode>& node);

    /**
     * @brief Register standard robdef service types to the default singleton node
     * 
     * Service types must be registered to the node before they can be used in C++.
     * When generating files directly with the `ROBOTRACONTEUR_GEN_THUNK_SOURCE`, the 
     * master header will contain the types that were generated, but not imported types.
     * Since the standard types are typically imported using the `AUTO_IMPORT` option,
     * they will not be included in the master header. Use this function before node
     * setup to register the standard types.
     */
    ROBOTRACONTEUR_COMPANION_STDROBDEF_API void RegisterStdRobDefServiceTypes();

}
}