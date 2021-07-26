project(TextNode)

add_library(TextNode TextNode.cpp TextNode.h)

target_include_directories(TextNode PUBLIC .)

target_link_libraries(TextNode StackLib)
