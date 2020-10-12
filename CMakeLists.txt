cmake_minimum_required(VERSION 3.3)
project(RobotRaconteurCompanion)

set (CMAKE_CXX_STANDARD 11)

find_package(RobotRaconteur 0.12.1 REQUIRED)

IF (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
ENDIF()

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
	com.robotraconteur.device.isoch
	com.robotraconteur.device
	com.robotraconteur.eventlog
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
	com.robotraconteur.octree
	com.robotraconteur.param
	com.robotraconteur.pid
	com.robotraconteur.pointcloud
	com.robotraconteur.pointcloud.sensor
	com.robotraconteur.resource
	com.robotraconteur.robotics.joints
	com.robotraconteur.robotics.payload
	com.robotraconteur.robotics.planning
	com.robotraconteur.robotics.robot
	com.robotraconteur.robotics.tool
	com.robotraconteur.robotics.trajectory
	com.robotraconteur.sensor
	com.robotraconteur.sensordata
	com.robotraconteur.servo
	com.robotraconteur.signal
	com.robotraconteur.units
	com.robotraconteur.uuid
)

foreach(f1 IN LISTS RR_SERVICE_NAMES_GROUP1)
	list(APPEND RR_INSTALLED_ROBDEF "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/group1/${f1}.robdef")
	list(APPEND RR_ROBDEF_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/robdef/group1/${f1}.robdef")
endforeach()

set(RR_SERVICE_NAMES ${RR_SERVICE_NAMES_GROUP1})

set(RR_INSTALLED_ROBDEF_DIRS "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/group1")

ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS
	${RR_ROBDEF_SOURCE_FILES}
	OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/robdef_gen
	CPP_EXTRA_INCLUDE "RobotRaconteurCompanion/StdRobDef/StdRobDef_Macros.h"
)

add_library(RobotRaconteurCompanion STATIC ${RR_THUNK_SRCS} ${RR_THUNK_HDRS} src/StdRobDefAll.cpp)
SET_TARGET_PROPERTIES(RobotRaconteurCompanion PROPERTIES PREFIX lib)

target_link_libraries(RobotRaconteurCompanion PUBLIC RobotRaconteurCore)
target_include_directories(RobotRaconteurCompanion PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
	$<INSTALL_INTERFACE:include>
	$<INSTALL_INTERFACE:include/RobotRaconteurCompanion/StdRobDef/group1>
)


include(GNUInstallDirs)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "cmake/Config.cmake.in"
  "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
  PATH_VARS
  CMAKE_INSTALL_LIBDIR
  CMAKE_INSTALL_INCLUDEDIR
  CMAKE_INSTALL_BINDIR
  CMAKE_INSTALL_DATADIR
)

write_basic_package_version_file("${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Version.cmake" 
    VERSION 0.1.0 COMPATIBILITY AnyNewerVersion)

install(FILES
        ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
install(FILES
        ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

install(DIRECTORY robdef/ DESTINATION ${CMAKE_INSTALL_DATADIR}/robotraconteur/robdef/standard_robdef/ FILES_MATCHING PATTERN "*.robdef")

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	FILES_MATCHING PATTERN "*.h*")
	
install(
	DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/robdef_gen/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RobotRaconteurCompanion/StdRobDef/group1
	FILES_MATCHING PATTERN "*.h*")

install(TARGETS RobotRaconteurCompanion EXPORT RobotRaconteurCompanionTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT RobotRaconteurCompanionTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

include(CTest)

if (BUILD_TESTING)
	include_directories(${RobotRaconteur_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/robdef_gen)
	add_executable(test_robdef_gen ${RR_THUNK_SRCS} ${RR_THUNK_HDRS} test/test_robdef_gen.cpp)
	target_link_libraries(test_robdef_gen RobotRaconteurCompanion RobotRaconteurCore)

	find_package (Eigen3 3.3 REQUIRED NO_MODULE)
	add_executable(test_eigen_converters ${RR_THUNK_SRCS} ${RR_THUNK_HDRS} test/test_eigen_converters.cpp)
	target_link_libraries(test_eigen_converters RobotRaconteurCompanion RobotRaconteurCore Eigen3::Eigen)

	add_test(NAME test_robdef_gen COMMAND test_robdef_gen)
	add_test(NAME test_eigen_converters COMMAND test_eigen_converters)
 endif()

