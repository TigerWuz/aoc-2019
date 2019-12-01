cmake_minimum_required(VERSION 3.0.0)
project(aoc VERSION 0.1.0)

add_library(aoc STATIC ./src/inputParser.cpp)
target_include_directories(aoc PUBLIC ./inc)
install(TARGETS aoc DESTINATION lib)
install(FILES inputParser.hpp DESTINATION include)