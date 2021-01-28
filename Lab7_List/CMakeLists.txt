cmake_minimum_required(VERSION 2.8)
project(List)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(gtest)
add_subdirectory(ListLib)

add_subdirectory(test)
