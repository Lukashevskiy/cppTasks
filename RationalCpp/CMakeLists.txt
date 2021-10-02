cmake_minimum_required(VERSION 3.20)
project(RationalCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RationalCpp
        main.cpp
        rational.cpp
        rational.h)
