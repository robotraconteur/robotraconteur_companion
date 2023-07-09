# Robot Raconteur Companion Library (C++)

<p align="center"><img src="docs/figures/logo-header.svg"></p>

The Robot Raconteur companion library contains utilities for working with Robot Raconteur services and devices.
This companion library is intended to be used with the Robot Raconteur Core library
(https://github.com/robotraconteur/robotraconteur). The companion library is written in C++ and is compatible with
C++11 and later.

Robot Raconteur Core focuses on the core capabilities of Robot Raconteur, such as transport, discovery, and
communication. The companion contains a number of miscellaneous utilities that are useful for working with other libraries
such as Eigen, and for working with standard Robot Raconteur service types 
(https://github.com/robotraconteur/robotraconteur_standard_robdef).

The companion library is not required to use Robot Raconteur, but is recommended for most users.

The companion is intended to evolve faster than the core library, and accept contributions from the community.

The companion library is licensed under the Apache 2.0 license.

The Robot Raconteur Companion library contains the following utilities:

* Standard Service Definition (robdef) types
* YAML parsers for device info structures
* Eigen converters
* Date/time converters
* Identifier utilities
* UUID utilities
* Service attribute utilities
* Sensor Data Structure Utilities

## Documentation

Documentation can be found at https://robotraconteur.github.io/robotraconteur_companion/

## Standard Service Types Usage

The library contains compiled standard service type thunk code. To use the standard service types without custom types,
use the following in the CMake lists:

```cmake
find_package(RobotRaconteurCompanion REQUIRED)
add_executable(my_program my_sources.cpp)
target_link_libraries(my_program ${OTHER_LIBRARIES} RobotRaconteurCompanion RobotRaconteurCore )
```

In the program initialization, use:

```cpp
#include <RobotRaconteur.h>
#include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"

// ...

RobotRaconteur::Companion::RegisterStdRobDefServiceTypes();
RobotRaconteur::ClientNodeSetup node_setup(std::vector<ServiceFactoryPtr>()); // or use RobotRaconteur::ServiceNodeSetup
```

If custom service types are being used in the program, use the following:

```cmake
find_package(RobotRaconteurCompanion REQUIRED)
ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS
    experimental.my_custom_types.robdef    
    MASTER_HEADER
    IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${RobotRaconteur_STANDARD_ROBDEF_DIRS}
    AUTO_IMPORT
)
add_executable(my_program my_sources.cpp)
target_link_libraries(my_program ${OTHER_LIBRARIES} RobotRaconteurCompanion RobotRaconteurCore ${RR_THUNK_HDRS}	${RR_THUNK_SRCS})
```
In the program initialization, use:

```cpp
#include <RobotRaconteur.h>
#include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"
#include "robotraconteur_generated.h"

// ...

RobotRaconteur::Companion::RegisterStdRobDefServiceTypes();
RobotRaconteur::ClientNodeSetup node_setup(ROBOTRACONTEUR_SERVICE_TYPES); // or use RobotRaconteur::ServiceNodeSetup
```

## Device Info Structure YAML Parsers

Device Info structures are used to describe devices and their capabilities. The structures are provided
to clients at runtime, typically through a property of a device service. For example, the 
`com.robotraconteur.device.Device` standard type defines the `device_info` property. The 
`com.robotraconteur.robotics.robot.Robot` standard type defines both `device_info` and `robot_info` properties.
These structures can be used to describe a wide variety of devices, including robots, sensors, and other devices.
YAML files are used to store the contents of these structures to make it easier to create and edit them. The
Robot Raconteur companion library contains parsers for these YAML files. The following device info structure types
are supported:

* `com.robotraconteur.actuator.ActuatorInfo`
* `com.robotraconteur.clock.ClockDeviceInfo`
* `com.robotraconteur.isoch.IsochDeviceInfo`
* `com.robotraconteur.device.DeviceInfo`
* `com.robotraconteur.eventlog.EventLogInfo`
* `com.robotraconteur.fiducial.FiducialInfo`
* `com.robotraconteur.fiducial.FiducialSensorInfo`
* `com.robotraconteur.hid.joystick.JoystickInfo`
* `com.robotraconteur.image.ImageInfo`
* `com.robotraconteur.image.FreeformImageInfo`
* `com.robotraconteur.imaging.camerainfo.PlumbBobDistortionInfo`
* `com.robotraconteur.imaging.camerainfo.CameraInfo`
* `com.robotraconteur.imaging.camerainfo.MultiCameraInfo`
* `com.robotraconteur.laserscan.LaserScanInfo`
* `com.robotraconteur.laserscan.LaserScanInfof`
* `com.robotraconteur.laserscan.LaserScanSensorInfo`
* `com.robotraconteur.lighting.LightInfo`
* `com.robotraconteur.objectrecognition.ObjectRecognitionSensorInfo`
* `com.robotraconteur.octree.OcTreeInfo`
* `com.robotraconteur.param.ParameterInfo`
* `com.robotraconteur.pointcloud.sensor.PointCloudSensorInfo`
* `com.robotraconteur.resource.BucketInfo`
* `com.robotraconteur.resource.ResourceInfo`
* `com.robotraconteur.robotics.joint.JointInfo`
* `com.robotraconteur.robotics.payload.PayloadInfo`
* `com.robotraconteur.robotics.robot.RobotInfo`
* `com.robotraconteur.robotics.robot.RobotKinChainInfo`
* `com.robotraconteur.robotics.tool.ToolInfo`
* `com.robotraconteur.sensor.SensorInfo`
* `com.robotraconteur.sensordata.SensorDataSourceInfo`
* `com.robotraconteur.servo.ServoInfo`
* `com.robotraconteur.signal.SignalInfo`
* `com.robotraconteur.signal.SignalGroupInfo`

The parsers can be accessed using the `RobotRaconteur::Companion::Util::LoadInfoFileFromString()`, 
`RobotRaconteur::Companion::Util::LoadInfoFile()`, or `RobotRaconteur::Companion::Util::LoadInfoFromNode()` functions.
These functions are in the `RobotRaconteurCompanion/Util/LoadInfoFile.h` header. The header file 
`RobotRaconteurCompanion/Util/InfoParser/yaml/yaml_parser_all.h` should be included to include all of the parser 
implementations. 

A typical program will include:

```cpp
#include <RobotRaconteur.h>
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>
#include <RobotRaconteurCompanion/Util/InfoFileLoader.h>
```

And somewhere in the program, load the info. This example is for the joystick info structure, but the same
pattern can be used for any of the info structures.

```cpp
std::vector<RobotRaconteur::Companion::Util::LocalIdentifierLockPtr> identifier_locks; // Keep this vector around for the lifetime of the program
auto joy_info = RobotRaconteur::Companion::Util::LoadInfoFile<com::robotraconteur::hid::joystick::JoystickInfoPtr>(info_filename, identifier_locks, "device");
```

## Eigen Converters

The Eigen library is a popular C++ library for linear algebra. The Robot Raconteur companion library
provides converters for Eigen types to and from Robot Raconteur types. See the doxygen documentation for
`RobotRaconteurCompanion/Converters/EigenConverters.h` for more information on the available converters.

## Date/Time Converters

The Robot Raconteur companion library provides converters for date/time types to and from Robot Raconteur types.

The comanian library supports several time representations:

* `com.robotraconteur.datetime.DateTimeUTC` - Used to represent a date and time in UTC, based on the system real time clock
* `com.robotraconteur.datetime.TimeSpec2` - Used to represent a timestamp based on the system performance clock, which is not 
    not guaranteed to be synchronized between systems or the real-time clock, and is expected to be stable.
* `com.robotraconteur.datetime.TimeSpec3` - A compact representation of a timestamp

The companion library provides functions to populate and convert these types.

See the doxygen documentation for `RobotRaconteurCompanion/Util/DateTimeUtil.h` for more information on the available converters.

## Identifier Utilities

Robot Raconteur identifiers use a combination of a UUID and a string name. This allows for the UUID to be used
in a production environment, while a simple string can be used when a human-readable name is needed.

The type `com.robotraconteur.identifier.Identifier` is used by standard types for identifiers. The companion library
provides functions to populate and convert these types.

See the doxygen documentation for `RobotRaconteurCompanion/Util/IdentifierUtil.h` for more information on the available functions.

## UUID Utilities

The type `com.robotraconteur.uuid.UUID` is used to represent a UUID by the Robot Raconteur standard types.
The companion library provides functions to populate and convert these types.

See the doxygen documentation for `RobotRaconteurCompanion/Util/UuidUtil.h` for more information on the available functions.

## Service Attributes Utilities

Service Attributes are used to provide additional information about a service. This information is usually
available during discovery, and can be used to select the appropriate service. The Robot Raconteur standard
types are expected to populate the following attributes:

* "device" - The identifier of the device converted to a string
* "parent_device" - (optional) The identifier of the parent device converted to a string, if there is a parent device
* "manufacturer" - The identifier of the manufacturer converted to a string
* "serial_number" - The serial number of the device
* "user_description" - A user description of the device

An example of using the service attributes utilities from the companion library is shown below for a joystick service:

Include files:


```cpp
#include <RobotRaconteur.h>
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/InfoParser/yaml/yaml_parser_all.h>
#include <RobotRaconteurCompanion/Util/InfoFileLoader.h>
```

And somewhere in the program:

```cpp
// Load info and create attributes
auto joy_info = RobotRaconteur::Companion::Util::LoadInfoFile<com::robotraconteur::hid::joystick::JoystickInfoPtr>(info_filename, identifier_locks, "device");
auto attributes = RobotRaconteur::Companion::Util::GetDefaultServiceAttributesFromDeviceInfo(joy_info->device_info);

// Register service and set attributes
auto service_context = RR::RobotRaconteurNode::s()->RegisterService("joystick", "com.robotraconteur.hid.joystick", joy_impl);
service_context->SetAttributes(attributes);
```

See the doxygen documentation for `RobotRaconteurCompanion/Util/AttributesUtil.h` for more information on the available functions.

## Sensor Data Utilities

"Sensor Data" is a concept used to provide loggable data from a sensor. The data is typically transmitted using
a `pipe` member, and has a `com.robotraconteur.sensordata.SensorDataHeader` field as the first
field in the data structure. The Robot Raconteur companion
library provides functions to populate this structure.

An example using the sensor data utilities from the companion library is shown below for a joystick service:

```cpp
com::robotraconteur::hid::joystick::JoystickStateSensorDataPtr joy_sensor_data(new com::robotraconteur::hid::joystick::JoystickStateSensorData());
joy_sensor_data->data_header = RobotRaconteur::Companion::Util::FillSensorDataHeader(RR::RobotRaconteurNode::sp(), joy_info->device_info, seqno);
joy_sensor_data->joystick_state = joy_state;
joy_sensor_data->gamepad_state = pad_state;
```

See the doxygen documentation for `RobotRaconteurCompanion/Util/SensorDataUtil.h` for more information on the available functions.

## Compiling

The companion library can be built using the standard CMake build process.

`vcpkg` can also be used to build the companion library for use with your application. 
See https://github.com/microsoft/vcpkg for installation instructions.

To build Robot Raconteur, clone the `vcpkg-robotraconteur` overlay repo in the vcpkg directory:

```
git clone https://github.com/robotraconteur/vcpkg-robotraconteur.git
```

and build the library:

```
vcpkg --overlay-ports=vcpkg-robotraconteur\ports install robotraconteur-companion
```

To build x64, use:

```
vcpkg --overlay-ports=vcpkg-robotraconteur\ports install robotraconteur-companion:x64-windows
```

## License

Apache 2.0
