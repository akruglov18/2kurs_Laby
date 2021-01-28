project(ArrayListLib)

add_library(ArrayListLib ArrayList.cpp ArrayList.h)

target_include_directories(ArrayListLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})