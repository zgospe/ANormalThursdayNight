cmake_minimum_required(VERSION 3.6)
project(Rogue_Like)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Character.cpp Character.h Item.cpp Item.h)
add_executable(Rogue_Like ${SOURCE_FILES})