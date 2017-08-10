cmake_minimum_required (VERSION 2.8)

project(ThreadTest)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -std=c++11 -Wl,-no-as-needed")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -pthread -Wl,-no-as-needed -std=c++11")

aux_source_directory(. DIR_SRCS)

add_executable(TreadTest ${DIR_SRCS})
