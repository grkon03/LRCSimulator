cmake_minimum_required(VERSION 3.1)

project(LRCSimulator)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(includes)

add_executable(LRCSimulator main.cpp)

target_link_libraries(LRCSimulator LRCIncludes)