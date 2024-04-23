cmake_minimum_required(VERSION 3.16)

project(compute_grades VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(compute_grades src/main.cpp)
