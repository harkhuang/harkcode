project(abstractfactory)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_SOURCE_DIR} )
aux_source_directory(.   src)

add_executable(abstractfactory ${src})
