if((CMAKE_VERSION VERSION_GREATER 3.12 OR CMAKE_VERSION VERSION_EQUAL 3.12))
    cmake_minimum_required(VERSION 3.12...3.31)
else()
    cmake_minimum_required(VERSION 3.5)
endif()
project(RobotRaconteurCompanion VERSION 0.4.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

find_package(RobotRaconteur 0.17.0 REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(OpenCV)

if(NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/robdef/group1")
    message(FATAL_ERROR "RobotRaconteurCompanion must use git clone --recursive, currently missing robdef files")
endif()

set(RR_SERVICE_NAMES_GROUP1
    com.robotraconteur.action
    com.robotraconteur.actuator
    com.robotraconteur.bignum
    com.robotraconteur.color
    com.robotraconteur.datatype
    com.robotraconteur.datetime.clock
    com.robotraconteur.datetime
    com.robotraconteur.device.clock
    com.robotraconteur.device.isoch
    com.robotraconteur.device
    com.robotraconteur.eventlog
    com.robotraconteur.fiducial
    com.robotraconteur.geometry
    com.robotraconteur.geometry.shapes
    com.robotraconteur.geometryf
    com.robotraconteur.geometryi
    com.robotraconteur.gps
    com.robotraconteur.hid.joystick
    com.robotraconteur.identifier
    com.robotraconteur.image
    com.robotraconteur.imaging.camerainfo
    com.robotraconteur.imaging
    com.robotraconteur.imu
    com.robotraconteur.laserscan
    com.robotraconteur.laserscanner
    com.robotraconteur.lighting
    com.robotraconteur.objectrecognition
    com.robotraconteur.octree
    com.robotraconteur.param
    com.robotraconteur.pid
    com.robotraconteur.pointcloud
    com.robotraconteur.pointcloud.sensor
    com.robotraconteur.resource
    com.robotraconteur.resource.device
    com.robotraconteur.robotics.joints
    com.robotraconteur.robotics.payload
    com.robotraconteur.robotics.robot
    com.robotraconteur.robotics.tool
    com.robotraconteur.robotics.trajectory
    com.robotraconteur.sensor
    com.robotraconteur.sensordata
    com.robotraconteur.servo
    com.robotraconteur.signal
    com.robotraconteur.units
    com.robotraconteur.uuid)

foreach(f1 IN LISTS RR_SERVICE_NAMES_GROUP1)
    list(APPEND RR_INSTALLED_ROBDEF "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/group1/${f1}.robdef")
    list(APPEND RR_ROBDEF_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/robdef/group1/${f1}.robdef")
endforeach()

set(RR_SERVICE_NAMES ${RR_SERVICE_NAMES_GROUP1})

set(RR_INSTALLED_ROBDEF_DIRS "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/group1")

robotraconteur_generate_thunk(
    RR_THUNK_SRCS
    RR_THUNK_HDRS
    ${RR_ROBDEF_SOURCE_FILES}
    OUTDIR
    ${CMAKE_CURRENT_BINARY_DIR}/robdef_gen
    CPP_EXTRA_INCLUDE
    "RobotRaconteurCompanion/StdRobDef/StdRobDef_Macros.h")

add_library(
    RobotRaconteurCompanion
    ${RR_THUNK_SRCS}
    ${RR_THUNK_HDRS}
    src/StdRobDefAll.cpp
    src/yaml_loader_enums.cpp
    src/LocalIdentifiersManager.cpp
    src/UuidUtil.cpp
    src/yaml_loader_impl.cpp
    src/EigenConverters.cpp
    src/AttributesUtil.cpp
    src/DateTimeUtil.cpp
    src/IdentifierUtil.cpp
    src/InfoFileLoader.cpp
    src/DeviceConnector.cpp)
set_target_properties(RobotRaconteurCompanion PROPERTIES PREFIX lib)

target_link_libraries(RobotRaconteurCompanion PUBLIC RobotRaconteurCore Eigen3::Eigen yaml-cpp)
target_include_directories(
    RobotRaconteurCompanion
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/robdef_gen/> $<INSTALL_INTERFACE:include>
           $<INSTALL_INTERFACE:include/RobotRaconteurCompanion/StdRobDef/group1>)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(RobotRaconteurCompanion PRIVATE "-fPIC")
endif()

if(MSVC)
    target_compile_options(RobotRaconteurCompanion PRIVATE "/wd4251" "/wd4275" "/bigobj")
endif()

if(BUILD_SHARED_LIBS AND WIN32)
    set(CMAKE_DEBUG_POSTFIX "d")
    target_compile_definitions(
        RobotRaconteurCompanion
        PRIVATE ROBOTRACONTEUR_COMPANION_STDROBDEF_EXPORTS ROBOTRACONTEUR_COMPANION_INFOPARSER_EXPORTS
                ROBOTRACONTEUR_COMPANION_UTIL_EXPORTS
        INTERFACE ROBOTRACONTEUR_COMPANION_STDROBDEF_IMPORTS ROBOTRACONTEUR_COMPANION_INFOPARSER_IMPORTS
                  ROBOTRACONTEUR_COMPANION_UTIL_IMPORTS)
endif()

if(WIN32)
    if(BUILD_SHARED_LIBS)
        target_link_libraries(RobotRaconteurCompanion PRIVATE Bcrypt.lib)
    else()
        target_link_libraries(RobotRaconteurCompanion PUBLIC Bcrypt.lib)
    endif()
endif()

export(TARGETS RobotRaconteurCompanion FILE ${CMAKE_BINARY_DIR}/RobotRaconteurCompanionTargets.cmake)

include(GNUInstallDirs)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "cmake/Config.cmake.in" "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
    PATH_VARS CMAKE_INSTALL_LIBDIR CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_BINDIR CMAKE_INSTALL_DATADIR)

write_basic_package_version_file("${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Version.cmake" COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
install(FILES ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

install(
    DIRECTORY robdef/
    DESTINATION ${CMAKE_INSTALL_DATADIR}/robotraconteur/robdef/standard_robdef/
    FILES_MATCHING
    PATTERN "*.robdef")

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h*")

install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/robdef_gen/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RobotRaconteurCompanion/StdRobDef/group1
    FILES_MATCHING
    PATTERN "*.h*")

install(
    TARGETS RobotRaconteurCompanion
    EXPORT RobotRaconteurCompanionTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(EXPORT RobotRaconteurCompanionTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()

find_package(Doxygen)
option(BUILD_DOCUMENTATION "Build documentation using Doxygen" ${DOXYGEN_FOUND})

# https://p5r.uk/blog/2014/cmake-doxygen.html
if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation")
    endif()

    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
    configure_file(${CMAKE_SOURCE_DIR}/docs/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    add_custom_target(
        RobotRaconteurCompanion_doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif()

file(STRINGS "${CMAKE_SOURCE_DIR}/package.xml" ROS_PKG_VERSION_1 REGEX "<version>[0-9]+\\.[0-9]+\\.[0-9]+</version>")
string(REGEX REPLACE "<version>([0-9]+\\.[0-9]+\\.[0-9]+)</version>" "\\1" ROS_PKG_VERSION ${ROS_PKG_VERSION_1})
string(STRIP ${ROS_PKG_VERSION} ROS_PKG_VERSION)
if(NOT ("${ROS_PKG_VERSION}" VERSION_EQUAL "${PROJECT_VERSION}"))
    message(FATAL_ERROR "Found ROS package version |${ROS_PKG_VERSION}| mismatch |${PROJECT_VERSION}|")
endif()

list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.git/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.vs/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.vscode/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.github/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.gitlab/")
# list(APPEND CPACK_SOURCE_IGNORE_FILES "/build/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "^${CMAKE_SOURCE_DIR}/build[\\\\-_/]")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.cache")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.gitignore")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.gitmodules")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.travis.yml")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.clang-format")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.clang-tidy")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.cmake-format.yaml")

set(CPACK_SOURCE_TBZ2 OFF CACHE BOOL "" FORCE)
set(CPACK_SOURCE_TXZ OFF CACHE BOOL "" FORCE)
set(CPACK_SOURCE_TZ OFF CACHE BOOL "" FORCE)
if(NOT WIN32)
    set(CPACK_SOURCE_TGZ ON CACHE BOOL "" FORCE)
endif()
set(CPACK_SOURCE_ZIP ON CACHE BOOL "" FORCE)

include(CPack)
