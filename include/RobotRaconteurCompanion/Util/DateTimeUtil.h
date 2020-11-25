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