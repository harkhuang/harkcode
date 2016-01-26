project(frame_work)
cmake_minimum_required(VERSION 2.8)
set(PROJECT_DIR  .)
set(PROJECT_DIR_PUBFUNC  ${PROJECT_DIR}/src)
aux_source_directory(PROJECT_DIR_PUBFUNC  ${CMAKE_SOURCE_DIR}/src/pub_func )
set(TEST  ${CMAKE_SOURCE_DIR}/src/test)

set(COMMPATH  ${CMAKE_SOURCE_DIR}/include)


#fit the cmake ..
set (PROJECT_BINARY_DIR=/mnt/github/trunk/framework/build)
set (PROJECT_SOURCE_DIR=/mnt/github/trunk/framework/src)

#add your include directory
set(MY_INCLUDE /mnt/github/trunk/framework/inlcude)
include_directories( . / 
${MY_INCLUDE} /
${MY_INCLUDE}/src/test /
${MY_INCLUDE}/include/comm /
${MY_INCLUDE}/include/comm/lcomm /
${MY_INCLUDE}/include/comm/platform /
${MY_INCLUDE}/include/comm/platform/linuxipc /
${MY_INCLUDE}/include/comm/platform/linuxwin32api /
${MY_INCLUDE}/include/comm/platform/os /
  )

# Enabled by default

OPTION(D_LINUX_ "Option description" ON) 



#然后做一个条件判断：
IF(D_LINUX_)
    ADD_DEFINITIONS(-D_LINUX_)
ENDIF(D_LINUX_)
MESSAGE(STATUS ${D_LINUX_})

#这里添加了  linux定义的宏 根据代码制定的 (半天时间)
#add_definitions(-D_LINUX_) 

set(CMAKE_BUILD_TYPE=DEBUG)
set (CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

#生成可执行文件保存路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -Wall -Wextra -Werror")
#target_include_directories(/mnt/github/framework/inlcude/)

include_directories($(CMAKE_SOURCE_DIR)/include)



#add_subdirectory(src)

 
add_executable(frame_work  ${TEST}/main.cpp   /
${CMAKE_SOURCE_DIR}/src/test/wsocket.cpp )

target_link_libraries(frame_work    ${LPTHREAD}  -lpthread)


#some message before cmake ..
MESSAGE(STATUS "The BINARY dir is ${PROJECT_BINARY_DIR}")
MESSAGE(STATUS "The PROJECT_DIR dir is ${PROJECT_DIR}")
MESSAGE(STATUS "The PUBFUNC dir is ${PUBFUNC}")
MESSAGE(STATUS "auto source dir PUBFUNC")
MESSAGE(STATUS "first test is TEST")
MESSAGE(STATUS "include pub inc")
MESSAGE(STATUS "build the executable is frame_work")
###################
#link_directories(${CMAKE_SOURCE_DIR}    )
#add_executable(oristar_sms_server  main.cpp  )
#target_link_libraries(oristar_sms_server ssl crypto  pthread dl stdc++ mvc2api)
#########   BS_NOMARL
#add_custom_command(TARGET ALL_BUILD)
###########