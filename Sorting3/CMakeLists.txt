cmake_minimum_required(VERSION 3.9)
project(Sorting3)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES
        src/*.cc
        inc/*.h)
include_directories(inc)

add_executable(Sorting3 ${SOURCES})
