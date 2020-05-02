cmake_minimum_required(VERSION 3.16)
project(Dynamic_Library)

set(CMAKE_CXX_STANDARD 14)

add_library(Dynamic_Library SHARED library.cpp library.h)

add_executable(main main.cpp)