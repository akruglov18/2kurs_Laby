cmake_minimum_required(VERSION 3.12)
project(HashMap)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(gtest)
add_subdirectory(Node)
add_subdirectory(Map)
add_subdirectory(HashMap)
add_subdirectory(HashListMap)
add_subdirectory(LabTest)

