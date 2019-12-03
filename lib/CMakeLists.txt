cmake_minimum_required(VERSION 3.0.0)
project(aoc VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(inputParser)
add_subdirectory(intCode)

add_library(aoc INTERFACE)
target_link_libraries(aoc INTERFACE inputParser intCode)
target_include_directories(aoc INTERFACE inputParser/inc intCode/inc)
