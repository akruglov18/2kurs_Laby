project(SortMap)

add_library(SortMap SortMap.cpp SortMap.h Sorts.h)

target_include_directories(SortMap PUBLIC .)

target_link_libraries(SortMap Map)
