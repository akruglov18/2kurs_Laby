project(TreeNode)

add_library(TreeNode TreeNode.cpp TreeNode.h)

target_link_libraries(TreeNode Node)

target_include_directories(TreeNode PUBLIC .)

