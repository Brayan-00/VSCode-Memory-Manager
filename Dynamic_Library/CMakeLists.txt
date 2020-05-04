cmake_minimum_required(VERSION 3.16)
project(Dynamic_Library)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_LIBRARY_PATH ./VSPtr.cpp)

add_library(Ptr SHARED VSPtr.cpp VSPtr.h)

add_executable(main main.cpp)

