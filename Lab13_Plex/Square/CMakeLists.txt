project(Square)

add_library(Square Square.cpp Square.h)

target_include_directories(Square PUBLIC .)

target_link_libraries(Square Base Line)
