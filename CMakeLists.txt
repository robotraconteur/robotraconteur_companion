cmake_minimum_required(VERSION 3.3)
project(RobotRaconteur_standard_robdef_cpp)

if(NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/robdef/group1")
	message(FATAL_ERROR "RobotRaconteur_standard_robdef_cpp must use git clone --recursive, currently missing robdef files")
endif()

file(GLOB_RECURSE robdef_files FOLLOW_SYMLINKS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/robdef/" "${CMAKE_CURRENT_SOURCE_DIR}/robdef/*.robdef")

foreach(f1 IN LISTS robdef_files)
	set(f "${CMAKE_CURRENT_SOURCE_DIR}/robdef/${f1}")
	FILE (STRINGS "${f}" f_service_name1 REGEX "^[ \t]*service +([A-Za-z0-9\\.]+)" LIMIT_COUNT 1)		
	IF ("${f_service_name1}" STREQUAL "" )
		message(FATAL_ERROR "Could not determine service name for ${f}")
	ENDIF()
	STRING (REGEX REPLACE "^[ \t]*service +([A-Za-z0-9\\.]+)" "\\1" f_service_name ${f_service_name1})	
	IF ("${f_service_name}" STREQUAL "" )
		message(FATAL_ERROR "Could not determine service name for ${f}")
	ENDIF()	
	list(APPEND RR_SERVICE_NAMES ${f_service_name})
	list(APPEND RR_INSTALLED_ROBDEF "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/${f1}")
	get_filename_component(p ${f1} DIRECTORY)
	list(APPEND RR_INSTALLED_ROBDEF_DIRS "$\{RobotRaconteur_STANDARD_ROBDEF_ROOT_DIR\}/${p}")
endforeach()

list(REMOVE_DUPLICATES RR_INSTALLED_ROBDEF_DIRS)

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

include(CTest)

if (BUILD_TESTING)
	find_package(RobotRaconteur REQUIRED)
	file(GLOB_RECURSE robdef_files_abs FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/robdef/*.robdef")
	ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS
		${robdef_files_abs}
		MASTER_HEADER
	)
	include_directories(${RobotRaconteur_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
	add_executable(test_robdef_gen ${RR_THUNK_SRCS} ${RR_THUNK_HDRS} test/test_robdef_gen.cpp)
	target_link_libraries(test_robdef_gen RobotRaconteurCore ${Boost_LIBRARIES} ${RobotRaconteurCore_Extra_Libraries} )

	add_test(NAME test_robdef_gen COMMAND test_robdef_gen)
endif()

