project(StackTest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(StackTest test_Stack.cpp test_main.cpp)

target_link_libraries(StackTest gtest StackLib)
