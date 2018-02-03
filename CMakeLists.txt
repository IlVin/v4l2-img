cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# DEBUG|RELEASE|RELWITHDEBINFO|MINSIZEREL
# SET (CMAKE_BUILD_TYPE DEBUG)
set (CMAKE_BUILD_TYPE DEBUG)

# Application name
set (PROJECT VisIoT)

# Project name
project (${PROJECT})

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") # debug mode

######  TESTING ###########
#enable_testing()
#if(${COVERAGE})
#    set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#endif()
#foreach (TEST "test01")
#    add_executable ("${PROJECT}_${TEST}.exe" "${PROJECT_SOURCE_DIR}/${TEST}/main.cpp")
#endforeach ()
###### /TESTING ###########

######  BOOST  ############
#set (Boost_USE_STATIC_LIBS ON)
#set (Boost_USE_MULTITHREADED ON)
#
#find_package (Boost COMPONENTS unit_test_framework REQUIRED)
#include_directories (${Boost_INCLUDE_DIRS})
###### /BOOST  ############

######  INCLUDE DIRS ###########
set (INCLUDE_DIRS)
###### /INCLUDE DIRS ###########

######  LIBS ###########
set (LIBS "Image" "minIni" "Camera" "ImgProcess" "LinuxCamera" "jpeg_utils")
foreach (LIB ${LIBS})
    set (INCLUDE_DIRS ${INCLUDE_DIRS} "lib/${LIB}")
    add_library (${LIB} STATIC "lib/${LIB}/${LIB}.cpp")
endforeach(LIB)
###### /LIBS ###########

######  EXECUTABLE  ############
include_directories (${INCLUDE_DIRS})
target_link_libraries(${LIBS})
add_executable(${PROJECT} "${PROJECT_SOURCE_DIR}/src/main.cpp")
###### /EXECUTABLE  ############






