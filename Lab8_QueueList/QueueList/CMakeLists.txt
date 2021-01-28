project(QueueLib)

add_library(QueueLib QueueList.cpp QueueList.h)

target_include_directories(QueueLib PUBLIC .)
target_link_libraries(QueueLib ListLib)