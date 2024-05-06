cmake_minimum_required(VERSION 3.16)

project(compute_grades VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b796f7d # release-1.13.0
)
FetchContent_MakeAvailable(googletest)

# tests
enable_testing()

add_executable(hello_test tests/simple.cpp)
target_link_libraries(hello_test gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)

# src
add_executable(compute_grades src/main.cpp)
