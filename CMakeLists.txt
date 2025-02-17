cmake_minimum_required(VERSION 3.31)

project(embedded_study)
include(FetchContent)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


FetchContent_MakeAvailable(googletest)

add_library(double_linked_list double_link_list.c)

enable_testing()
add_test(NAME double_linked_list_test COMMAND double_linked_list_test)

add_executable(
  double_linked_list_test
  test_double_link_list.cpp
)

target_link_libraries(
  double_linked_list_test
  double_linked_list
)

target_link_libraries(
  double_linked_list_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(double_linked_list_test)
