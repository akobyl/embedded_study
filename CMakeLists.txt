cmake_minimum_required(VERSION 3.28)

project(embedded_study LANGUAGES C CXX)
include(FetchContent)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(double_link_list_lib
  double_link_list.c
)

add_library(circular_buffer_lib
  circular_buffer.c
)

add_executable(test_collection
  test/test_double_link_list.cpp
  test/test_circular_buffer.cpp
)

target_link_libraries(test_collection
  GTest::gtest_main
  double_link_list_lib
  circular_buffer_lib
)

target_include_directories(test_collection PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)
gtest_discover_tests(test_collection)
