cmake_minimum_required(VERSION 3.1)

project(LRCSimulator)

set(CMAKE_CXX_STANDARD 17)

file(GLOB LRCITargets *.cpp)

add_subdirectory(SSTabSim)

add_library(LRCIncludes ${LRCITargets})

target_link_libraries(LRCIncludes SSTabIncludes)