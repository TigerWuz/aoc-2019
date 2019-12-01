cmake_minimum_required(VERSION 3.0.0)
project(aoc2019 VERSION 0.1.0)

add_library(aocLib ./lib/src/inputParser.cpp ./lib/inc/inputParser.hpp)
target_include_directories(aocLib PUBLIC ./lib/inc)

add_executable(00_preparation ./00_preparation/dummy.cpp)
target_link_libraries(00_preparation PUBLIC aocLib) 

add_executable(Day1Part1 ./01_day/01_day.cpp)
target_link_libraries(Day1Part1 PUBLIC aocLib)

add_executable(Day1Part2 ./01_day/01_day.cpp)
target_link_libraries(Day1Part2 PUBLIC aocLib)
target_compile_definitions(Day1Part2 PRIVATE PART_2)
