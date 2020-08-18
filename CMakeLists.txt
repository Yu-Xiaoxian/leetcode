cmake_minimum_required(VERSION 3.1.0)
project(code)

file(GLOB CPP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(file ${CPP_SRCS})
    string(REPLACE ".cpp" "" program_name ${file})
    add_executable(${program_name} ${file})
endforeach(file )

