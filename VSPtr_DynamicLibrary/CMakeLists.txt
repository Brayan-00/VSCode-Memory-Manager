cmake_minimum_required(VERSION 3.16)
project(VSPtr_DynamicLibrary)

set(CMAKE_CXX_STANDARD 14)

add_library(VSPtr_DynamicLibrary SHARED library.cpp)