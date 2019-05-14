cmake_minimum_required(VERSION 2.8)
project(project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(project2
        exception.cc
        exceptions.h
        project2.cc
        project2.h
        simpleStack.h)