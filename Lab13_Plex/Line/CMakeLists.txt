project(Line)

add_library(Line Line.cpp Line.h)

target_include_directories(Line PUBLIC .)

target_link_libraries(Line Base Point)
