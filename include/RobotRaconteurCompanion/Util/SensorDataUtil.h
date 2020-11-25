#include "DateTimeUtil.h"

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

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