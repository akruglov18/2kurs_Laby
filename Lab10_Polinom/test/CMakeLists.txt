project(PolinomTest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(PolinomTest test_Polinom.cpp test_main.cpp)

target_link_libraries(PolinomTest gtest PolinomLib)
