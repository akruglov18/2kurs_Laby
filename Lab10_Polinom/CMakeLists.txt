cmake_minimum_required(VERSION 3.12)
project(Polinom)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(gtest)
add_subdirectory(PolinomLib)

add_subdirectory(test)
