cmake_minimum_required(VERSION 3.12)
project(Plex_Lab)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(gtest)
add_subdirectory(StackLib)
add_subdirectory(Base)
add_subdirectory(Point)
add_subdirectory(Line)
add_subdirectory(Square)
add_subdirectory(Circle)
add_subdirectory(Plex)
add_subdirectory(Canvas)
add_subdirectory(LabTest)

