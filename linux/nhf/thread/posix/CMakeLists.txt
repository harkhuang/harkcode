# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 设置变量,如DemoTest
set(PROJECT_NAME DemoTest) 
#项目名称
set(OBJ_NAME Demo)
#生成的目标文件名称
set(SUBDIR_SRCS ${PROJECT_SOURCE_DIR}/math)
#文件子目录
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
#链接库目录
set(LIB_FILE MathFunctions)
#链接库文件 
# 项目信息
project (${PROJECT_NAME}) 
include_directories ("${PROJECT_SOURCE_DIR}/math")
#add_subdirectory (math) 
#set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) 
set (EXTRA_LIBS ${EXTRA_LIBS} pthread) 
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS) 
#开启gdb调试,debug模式下关闭优化,并打印警告,加调试选项
set(CMAKE_BUILD_TYPE "Debug") 
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#添加C++11支持及其他选项
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated") 
MESSAGE(STATUS,"C++ flags have ",${CMAKE_CXX_FLAGS})
#指定添加的库文件
link_libraries(${EXTRA_LIBS})
# 指定生成目标
#add_executable(${OBJ_NAME} ${DIR_SRCS}) 
add_executable(${OBJ_NAME} prime1.c) 
#add_executable(${OBJ_NAME} prime2.c) 
#target_link_libraries (${OBJ_NAME}) 
# 指定安装路径
install (TARGETS ${OBJ_NAME} DESTINATION bin)
