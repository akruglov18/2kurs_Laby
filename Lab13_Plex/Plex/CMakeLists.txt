project(Plex)

add_library(Plex Plex.cpp Plex.h)

target_include_directories(Plex PUBLIC .)

target_link_libraries(Plex StackLib Base Point Line)
