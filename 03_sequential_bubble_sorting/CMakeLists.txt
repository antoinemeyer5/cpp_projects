##### SETUP #####
cmake_minimum_required( VERSION 3.1...3.28 )

project( 03_sequential_bubble_sorting CXX )
set ( CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_STANDARD 17 )

##### SOURCES #####
set ( PROJECT_HEADERS src/sort.hpp src/utils.hpp )

add_library( common OBJECT )
target_sources( common PUBLIC ${PROJECT_HEADERS} )
target_include_directories( common PUBLIC src )

add_executable( exec_code src/main.cpp )

##### TESTS #####
set ( TEST_HEADERS test/catch.hpp )
set ( TEST_SOURCES test/catch.cpp )

add_library( test OBJECT )
target_sources ( test PRIVATE ${TEST_SOURCES} PUBLIC ${TEST_HEADERS} )

add_executable ( exec_test test/sort.cpp )
target_link_libraries ( exec_test PRIVATE common ) # need source in test
