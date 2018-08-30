project(factory)
cmake_minimum_required(VERSION 2.6)

include_directories(./1-factory/  )
include_directories(./2-abstractfactory/ )

aux_source_directory( ./1-factory/  src_factory)
aux_source_directory( ./2-abstractfactory/  src_abstractfactory)

add_executable(factory ${src_factory})
add_executable(abstractfactory ${src_abstractfactory})