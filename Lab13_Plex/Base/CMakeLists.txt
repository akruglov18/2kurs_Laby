project(Base)

add_library(Base Base.cpp Base.h)

target_include_directories(Base PUBLIC .)

#target_link_libraries(Base StackLib)
