project(ListTest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(ListTest test_List.cpp test_main.cpp)

target_link_libraries(ListTest gtest ListLib)
