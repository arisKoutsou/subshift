cmake_minimum_required(VERSION 3.9)
project(subshift)

set(CMAKE_CXX_STANDARD 11)

add_executable(sshift SrtShifter.cpp SrtShifter.h main.cpp SrtTime.cpp SrtTime.h)