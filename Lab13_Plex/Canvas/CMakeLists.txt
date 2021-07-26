project(Canvas)

add_library(Canvas Canvas.cpp Canvas.h)

target_include_directories(Canvas PUBLIC .)

target_link_libraries(Canvas Base)
