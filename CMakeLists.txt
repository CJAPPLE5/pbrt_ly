cmake_minimum_required(VERSION 3.24)
project(pbrt)

set(CMAKE_CXX_STANDARD 17)

add_executable(pbrt main.cpp src/core/geometry.cpp src/core/geometry.h src/core/pbrt.h)
