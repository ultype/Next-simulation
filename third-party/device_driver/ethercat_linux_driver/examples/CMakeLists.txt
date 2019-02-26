cmake_minimum_required (VERSION 2.8)
project(cifx_examples)
set(PROJECT_VERSION, 1.2.0.0)

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

if ("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
	message(STATUS "Set to new value")
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out)
endif()

if(CIFX_HEADER OR CIFX_INC_LIB)
    set(LIBCIFX_INCLUDE_DIRS  ${CIFX_HEADER})
    set(LIBCIFX_LIBRARIES "-pthread -lrt -lcifx -L${CIFX_INC_LIB}")
else(CIFX_HEADER OR CIFX_INC_LIB)
    include(FindPkgConfig)
    pkg_check_modules(LIBCIFX REQUIRED cifx)
endif(CIFX_HEADER OR CIFX_INC_LIB)

include_directories(${LIBCIFX_INCLUDE_DIRS})

add_executable(cifxsample cifxsample/cifxlinuxsample.c)
target_include_directories(cifxsample BEFORE PUBLIC cifxsample/)
target_link_libraries (cifxsample ${LIBCIFX_LIBRARIES})
install(TARGETS cifxsample DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB CIFXTESTCONSOLE_SRC cifXTestConsole/*.c* cifXTestConsole/shared/*.c*)
add_executable(cifxtestconsole ${CIFXTESTCONSOLE_SRC})
target_include_directories(cifxtestconsole BEFORE PUBLIC cifXTestConsole cifXTestConsole/shared)
target_link_libraries (cifxtestconsole ${LIBCIFX_LIBRARIES})
install(TARGETS cifxtestconsole DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB CIFXTCPSERVER_SRC cifXTCPServer/*.c* cifXTCPServer/**/*.c*)
add_executable(cifxtcpserver ${CIFXTCPSERVER_SRC})
target_include_directories(cifxtcpserver BEFORE PUBLIC cifXTCPServer cifXTCPServer/Marshaller cifXTCPServer/Marshaller/APIHeader/)
target_link_libraries (cifxtcpserver ${LIBCIFX_LIBRARIES})
install(TARGETS cifxtcpserver DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB SPISAMPLE_SRC SPISample/*.c)
add_executable(cifxspisample ${SPISAMPLE_SRC})
target_include_directories(cifxspisample BEFORE PUBLIC SPISample/)
target_link_libraries (cifxspisample ${LIBCIFX_LIBRARIES})
install(TARGETS cifxspisample DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB LOADABLEMODULES_SRC LoadModules/*.c*)
add_executable(cifxloadablemodules ${LOADABLEMODULES_SRC})
message(STATUS ${CIFX_HEADER})
target_include_directories(cifxloadablemodules PUBLIC LoadModules)
target_link_libraries (cifxloadablemodules ${LIBCIFX_LIBRARIES})
install(TARGETS cifxloadablemodules DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB ISASAMPLE_SRC ISASample/*.c*)
add_executable(cifxisasample ${ISASAMPLE_SRC})
target_include_directories(cifxisasample BEFORE PUBLIC ISASample/)
target_link_libraries (cifxisasample ${LIBCIFX_LIBRARIES})
install(TARGETS cifxisasample DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

