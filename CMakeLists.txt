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

add_executable(test_double_link_list
  test/test_double_link_list.cpp
  double_link_list.c
)

target_link_libraries(test_double_link_list
  GTest::gtest_main
)

target_include_directories(test_double_link_list PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)
gtest_discover_tests(test_double_link_list)
