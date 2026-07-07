cmake_minimum_required(VERSION 4.0)
project(RayTracer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_FILES src/*.h src/*.c)

add_executable(RayTracer ${SRC_FILES})

target_include_directories(RayTracer PUBLIC src)
