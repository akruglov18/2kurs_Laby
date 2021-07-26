project(LabTest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(LabTest tests.cpp test_main.cpp)

target_link_libraries(LabTest gtest Plex Line Point Square Circle Canvas)