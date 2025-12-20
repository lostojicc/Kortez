cmake_minimum_required(VERSION 3.10)

project(Kortez)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
include(Dependencies.cmake)

# Projects
add_subdirectory(Kortez)
add_subdirectory(Sandbox)

# Root
target_compile_definitions(Kortez PUBLIC KORTEZ_ROOT_DIR="${CMAKE_SOURCE_DIR}")