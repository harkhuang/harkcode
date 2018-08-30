project(factory)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_SOURCE_DIR} )
aux_source_directory(src ${CMAKE_SOURCE_DIR} )

add_executable(factory main.cpp factory.cpp product.cpp ${src})
