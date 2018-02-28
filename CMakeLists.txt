cmake_minimum_required(VERSION 3.9)
project(subshift)

set(CMAKE_CXX_STANDARD 11)

add_executable(subshift
        src/main.cpp
        src/SrtShifter.cpp
        src/SrtShifter.h
        src/SrtTime.cpp
        src/SrtTime.h)
