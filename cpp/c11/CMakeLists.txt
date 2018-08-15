project(c11-test)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# C++14: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
set(CMAKE_CXX_COMPILER "/opt/gcc-4.8.2/bin/g++")
set(CMAKE_C_COMPILER "/opt/gcc-4.8.2/bin/gcc")

set( CMAKE_BUILD_TYPE Debug )
include_directories(${CMAKE_SOURCE_DIR} )
aux_source_directory(src ${CMAKE_SOURCE_DIR} )


add_executable(testc11 shareptr.cpp ${src} )
target_link_libraries(testc11  pthread)