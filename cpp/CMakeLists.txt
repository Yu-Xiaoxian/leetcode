cmake_minimum_required(VERSION 3.1.0)
project(leetcode-cpp)
set(CMAKE_CXX_STANDARD 17)

file(GLOB ALL_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp)

foreach(FILE ${ALL_SRCS})
    string(REPLACE ".cpp" "" prog ${FILE})
    add_executable(${prog} ${FILE})
endforeach()
