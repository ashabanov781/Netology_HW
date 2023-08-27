cmake_minimum_required(VERSION 3.22.0)

project(CMake_lib)

add_executable(my_lib_hwork_3 Hwork_03.cpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(my_lib_work_unical SHARED  CMake_d_lib.h CMake_d_lib.cpp)

target_link_libraries(my_lib_hwork_3 my_lib_work_unical)