cmake_minimum_required(VERSION 3.20)
project(A3_Q2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A3_Q2
        main.cpp
        Organization.h
        Person.cpp
        Person.h
        University.h)
