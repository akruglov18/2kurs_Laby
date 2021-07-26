project(Tree)

add_library(Tree Tree.cpp Tree.h)

target_include_directories(Tree PUBLIC .)

target_link_libraries(Tree TreeNode)

