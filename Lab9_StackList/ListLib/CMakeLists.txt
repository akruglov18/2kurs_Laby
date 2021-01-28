project(ListLib)

add_library(ListLib List.cpp TListElem.cpp List.h TListElem.h)

target_include_directories(ListLib PUBLIC .)