cmake_minimum_required(VERSION 3.31)
project(Blython)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(src/)
add_subdirectory(external/)
add_subdirectory(include/)