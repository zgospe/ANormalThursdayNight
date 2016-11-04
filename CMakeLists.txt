cmake_minimum_required(VERSION 3.6)
project(ANormalThursdayNight)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ANormalThursdayNight/Character.cpp
    ANormalThursdayNight/Character.h
    ANormalThursdayNight/Item.cpp
    ANormalThursdayNight/Item.h
    ANormalThursdayNight/main.cpp
    ANormalThursdayNight/Modifier.cpp
    ANormalThursdayNight/Modifier.h
    ANormalThursdayNight/ModifierList.h)

add_executable(ANormalThursdayNight ${SOURCE_FILES})