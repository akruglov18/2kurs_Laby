project(QueueTest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(QueueTest test_Queue.cpp test_main.cpp)

target_link_libraries(QueueTest gtest QueueLib)
