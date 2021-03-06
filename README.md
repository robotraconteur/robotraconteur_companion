# Robot Raconteur Companion Library (C++)

The Robot Raconteur Companion library contains the following utilities:

* Stand Service Definition (robdef) types
* Yaml parsers for device info structures
* Eigen converters

*WARNING: THE STANDARD SERVICE TYPES ARE UNSTABLE AND SUBJECT TO CHANGE. DO NOT DEPLOY!*

## Standard Service Types Usage

The library contains compiled standard service type thunk code. To use the standard service types without custom types,
use the following in the CMake lists:

    find_package(RobotRaconteurCompanion REQUIRED)
    add_executable(my_program my_sources.cpp)
    target_link_libraries(my_program ${OTHER_LIBRARIES} RobotRaconteurCompanion RobotRaconteurCore )

In the program initialization, use:

    #include <RobotRaconteur.h>
    #include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"

    // ...

    RobotRaconteur::Companion::RegisterStdRobDefServiceTypes();
    RobotRaconteur::ClientNodeSetup node_setup(std::vector<ServiceFactoryPtr>()); // or use RobotRaconteur::ServiceNodeSetup

If custom service types are being used in the program, use the following:

    find_package(RobotRaconteurCompanion REQUIRED)
    ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS
        experimental.my_custom_types.robdef    
        MASTER_HEADER
        IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${RobotRaconteur_STANDARD_ROBDEF_DIRS}
        AUTO_IMPORT
    )
    add_executable(my_program my_sources.cpp)
    target_link_libraries(my_program ${OTHER_LIBRARIES} RobotRaconteurCompanion RobotRaconteurCore ${RR_THUNK_HDRS}	${RR_THUNK_SRCS})

In the program initialization, use:

    #include <RobotRaconteur.h>
    #include "RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h"
    #include "robotraconteur_generated.h"

    // ...

    RobotRaconteur::Companion::RegisterStdRobDefServiceTypes();
    RobotRaconteur::ClientNodeSetup node_setup(ROBOTRACONTEUR_SERVICE_TYPES); // or use RobotRaconteur::ServiceNodeSetup
