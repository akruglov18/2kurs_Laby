project(HashListMap)

add_library(HashListMap HashListMap.cpp HashListMap.h)

target_include_directories(HashListMap PUBLIC .)

target_link_libraries(HashListMap Node)

