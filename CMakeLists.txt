cmake_minimum_required(VERSION 3.0.0)
project(aoc2019 VERSION 0.1.0)

add_library(aocLib ./lib/src/inputParser.cpp ./lib/inc/inputParser.hpp)
target_include_directories(aocLib PUBLIC ./lib/inc)

add_executable(00_preparation ./00_preparation/dummy.cpp)
target_link_libraries(00_preparation PUBLIC aocLib) 
install(TARGETS 00_preparation DESTINATION bin)

add_executable(Day1Part1 ./01_day/01_day_01_part.cpp)
target_link_libraries(Day1Part1 PUBLIC aocLib) 
install(TARGETS Day1Part1 DESTINATION bin)
