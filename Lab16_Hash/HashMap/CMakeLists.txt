project(HashMap)

add_library(HashMap HashMap.cpp HashMap.h)

target_include_directories(HashMap PUBLIC .)

target_link_libraries(HashMap Map Node)

