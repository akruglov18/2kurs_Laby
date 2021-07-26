project(Point)

add_library(Point Point.cpp Point.h)

target_include_directories(Point PUBLIC .)

target_link_libraries(Point StackLib Base)
