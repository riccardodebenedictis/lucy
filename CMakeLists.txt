cmake_minimum_required(VERSION 3.0)

project (lucy)

include(CMakeToolsHelpers OPTIONAL)

add_subdirectory( smt-lib )

add_executable(lucy main.cpp)