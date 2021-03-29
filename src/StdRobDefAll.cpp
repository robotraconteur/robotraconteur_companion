#include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"

namespace RobotRaconteur
{
namespace Companion
{

    void RegisterStdRobDefServiceTypes(RR_SHARED_PTR<RobotRaconteurNode> node)
    {
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::action::com__robotraconteur__actionFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::actuator::com__robotraconteur__actuatorFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::bignum::com__robotraconteur__bignumFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::color::com__robotraconteur__colorFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::datatype::com__robotraconteur__datatypeFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::datetime::clock::com__robotraconteur__datetime__clockFactory>());   
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::datetime::com__robotraconteur__datetimeFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::device::isoch::com__robotraconteur__device__isochFactory>());       
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::device::com__robotraconteur__deviceFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::device::clock::com__robotraconteur__device__clockFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::eventlog::com__robotraconteur__eventlogFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::fiducial::com__robotraconteur__fiducialFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::geometry::com__robotraconteur__geometryFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::geometry::shapes::com__robotraconteur__geometry__shapesFactory>()); 
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::geometryf::com__robotraconteur__geometryfFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::geometryi::com__robotraconteur__geometryiFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::gps::com__robotraconteur__gpsFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::hid::joystick::com__robotraconteur__hid__joystickFactory>());       
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::identifier::com__robotraconteur__identifierFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::image::com__robotraconteur__imageFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::imaging::camerainfo::com__robotraconteur__imaging__camerainfoFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::imaging::com__robotraconteur__imagingFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::imu::com__robotraconteur__imuFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::laserscan::com__robotraconteur__laserscanFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::laserscanner::com__robotraconteur__laserscannerFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::lighting::com__robotraconteur__lightingFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::octree::com__robotraconteur__octreeFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::param::com__robotraconteur__paramFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::pid::com__robotraconteur__pidFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::pointcloud::com__robotraconteur__pointcloudFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::pointcloud::sensor::com__robotraconteur__pointcloud__sensorFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::resource::com__robotraconteur__resourceFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::resource::device::com__robotraconteur__resource__deviceFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::robotics::joints::com__robotraconteur__robotics__jointsFactory>()); 
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::robotics::payload::com__robotraconteur__robotics__payloadFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::robotics::robot::com__robotraconteur__robotics__robotFactory>());   
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::robotics::tool::com__robotraconteur__robotics__toolFactory>());     
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::robotics::trajectory::com__robotraconteur__robotics__trajectoryFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::sensor::com__robotraconteur__sensorFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::sensordata::com__robotraconteur__sensordataFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::servo::com__robotraconteur__servoFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::signal::com__robotraconteur__signalFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::units::com__robotraconteur__unitsFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::uuid::com__robotraconteur__uuidFactory>());
        node->RegisterServiceType(RR_MAKE_SHARED<com::robotraconteur::objectrecognition::com__robotraconteur__objectrecognitionFactory>());
        
    }

    
    void RegisterStdRobDefServiceTypes()
    {
        RegisterStdRobDefServiceTypes(RobotRaconteur::RobotRaconteurNode::sp());
    }

}
}