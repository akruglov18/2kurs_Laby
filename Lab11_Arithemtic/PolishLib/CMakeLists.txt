project(PolishLib)

add_library(PolishLib Polish.cpp Polish.h)

target_include_directories(PolishLib PUBLIC .)
target_link_libraries(PolishLib StackLib)