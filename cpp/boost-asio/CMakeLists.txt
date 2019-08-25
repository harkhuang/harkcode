
cmake_minimum_required(VERSION 3.9)
project(testasio)




set(BOOST_ROOT /usr/local)

find_package(Boost COMPONENTS regex system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

    add_executable(testasio 0-server.cpp)
    target_link_libraries (testasio ${Boost_LIBRARIES})
endif()