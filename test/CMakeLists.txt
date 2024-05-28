find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${RobotRaconteur_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/../robdef_gen)
add_executable(test_robdef_gen test_robdef_gen.cpp)
target_link_libraries(test_robdef_gen RobotRaconteurCompanion RobotRaconteurCore)
add_executable(test_infoparser test_infoparser.cpp)
target_link_libraries(test_infoparser RobotRaconteurCompanion RobotRaconteurCore yaml-cpp)
if(MSVC)
    target_compile_options(test_infoparser PRIVATE "/wd4251" "/wd4275" "/bigobj")
endif()
add_executable(test_robotinfo_parser test_robotinfo_parser.cpp)
target_link_libraries(test_robotinfo_parser RobotRaconteurCompanion RobotRaconteurCore yaml-cpp)

find_package(Eigen3 3.2 REQUIRED NO_MODULE)
add_executable(test_eigen_converters test_eigen_converters.cpp)
target_link_libraries(test_eigen_converters RobotRaconteurCompanion RobotRaconteurCore Eigen3::Eigen GTest::Main)

add_test(NAME test_robdef_gen COMMAND test_robdef_gen)
add_test(NAME test_eigen_converters COMMAND test_eigen_converters)

robotraconteur_generate_thunk(TASK_GEN_RR_SRC TASK_GEN_RR_HDR experimental.testing.companion.test_task_generator.robdef
                              AUTO_IMPORT IMPORT_DIRS ${CMAKE_SOURCE_DIR}/robdef/group1)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(test_task_generator test_task_generator.cpp ${TASK_GEN_RR_SRC} ${TASK_GEN_RR_HDR})
target_link_libraries(test_task_generator RobotRaconteurCompanion RobotRaconteurCore GTest::Main)
add_test(NAME test_task_generator COMMAND test_task_generator)

add_executable(test_device_connector test_device_connector.cpp)
target_link_libraries(test_device_connector RobotRaconteurCompanion RobotRaconteurCore GTest::Main)
add_test(NAME test_device_connector COMMAND test_device_connector WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_image_util test_image_util.cpp ${TASK_GEN_RR_SRC} ${TASK_GEN_RR_HDR})
target_link_libraries(test_image_util RobotRaconteurCompanion RobotRaconteurCore GTest::Main opencv_core opencv_imgproc)
add_test(NAME test_image_util COMMAND test_image_util)
