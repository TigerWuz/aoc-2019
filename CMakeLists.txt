cmake_minimum_required(VERSION 3.0.0)
project(aoc2019 VERSION 0.1.0)

add_subdirectory(./lib)

add_executable(Day1Part1 ./01_day/01_day.cpp)
target_link_libraries(Day1Part1 aoc)

add_executable(Day1Part2 ./01_day/01_day.cpp)
target_link_libraries(Day1Part2 aoc)
target_compile_definitions(Day1Part2 PRIVATE PART_2)
