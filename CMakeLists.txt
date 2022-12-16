cmake_minimum_required(VERSION 3.24)
project(igCap)

set(CMAKE_CXX_STANDARD 17)

add_executable(igCap main.cpp Instance.cpp Instance.h Configures.h Utils.cpp Utils.h)
