cmake_minimum_required(VERSION 3.23)
project(analyzer_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(analyzer_cpp
        analyzer.cpp)
