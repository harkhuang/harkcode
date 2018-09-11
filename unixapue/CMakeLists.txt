project(testinuap)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_BUILD_TYPE "Debug")

enable_testing()

add_executable(a.out    fig1.6.c)

add_test(a.out  1 1)