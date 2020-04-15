cmake_minimum_required(VERSION 3.16)
project(static_library VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(Boost_NO_BOOST_CMAKE ON)

include_directories("${CMAKE_SOURCE_DIR}/include/")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/mathops")


add_executable(main main.cpp)
target_link_libraries(main PRIVATE mathops)
