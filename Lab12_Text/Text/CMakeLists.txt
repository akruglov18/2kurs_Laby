project(Text)

add_library(Text Text.cpp Text.h)

target_include_directories(Text PUBLIC .)

target_link_libraries(Text TextNode)
