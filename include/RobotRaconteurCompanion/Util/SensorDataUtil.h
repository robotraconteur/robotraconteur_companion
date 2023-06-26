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
com::robotraconteur::sensordata::SensorDataHeaderPtr FillSensorDataHeader(RobotRaconteur::RobotRaconteurNodePtr node, com::robotraconteur::device::DeviceInfoPtr device_info, uint64_t seqno)
{
    com::robotraconteur::sensordata::SensorDataHeaderPtr ret(new com::robotraconteur::sensordata::SensorDataHeader());
    ret->seqno = seqno;
    ret->ts = TimeSpec2Now(node,device_info);
    return ret;
}

}
}
}