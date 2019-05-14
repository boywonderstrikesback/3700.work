cmake_minimum_required(VERSION 3.9)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES
        src/*.cc
        inc/*.h)
include_directories(inc)

add_executable(Lab2 ${SOURCES})
