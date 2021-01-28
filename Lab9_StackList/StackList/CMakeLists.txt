project(StackLib)

add_library(StackLib StackList.cpp StackList.h)

target_include_directories(StackLib PUBLIC .)
target_link_libraries(StackLib ListLib)