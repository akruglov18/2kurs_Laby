project(Map)

add_library(Map Map.cpp Map.h)

target_include_directories(Map PUBLIC .)

target_link_libraries(Map Node)

