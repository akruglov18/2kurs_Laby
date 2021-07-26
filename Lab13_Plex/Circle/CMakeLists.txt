project(Circle)

add_library(Circle Circle.cpp Circle.h)

target_include_directories(Circle PUBLIC .)

target_link_libraries(Circle Base)
