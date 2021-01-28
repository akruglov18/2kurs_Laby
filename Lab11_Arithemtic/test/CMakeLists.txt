project(TestsPolish)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(TestsPolish tests.cpp test_main.cpp)

target_link_libraries(TestsPolish gtest StackLib PolishLib)
