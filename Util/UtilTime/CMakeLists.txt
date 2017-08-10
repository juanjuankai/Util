cmake_minimum_required (VERSION 2.8)

project(timetest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. DIR_SRCS)

add_executable(timetest ${DIR_SRCS})