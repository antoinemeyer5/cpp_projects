##### SETUP #####
cmake_minimum_required( VERSION 3.1...3.28 )

project( 04_parallel_bubble_sorting CXX )

set ( CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_STANDARD 17 )

##### MPI #####
find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})

include_directories(${MPI_INCLUDE_PATH})

##### SOURCES #####
set ( PROJECT_HEADERS src/sort_common.hpp src/sort_versionA.hpp src/sort_versionB.hpp src/utils.hpp )

add_library( common OBJECT )
target_sources( common PUBLIC ${PROJECT_HEADERS} )
target_include_directories( common PUBLIC src )

add_executable( exec_code src/main.cpp )
target_link_libraries( exec_code ${MPI_LIBRARIES} )

##### TESTS #####
INCLUDE(CTest)
ENABLE_TESTING()

ADD_SUBDIRECTORY(tests)
