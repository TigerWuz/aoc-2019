cmake_minimum_required(VERSION 3.0.0)
project(aoc2019 VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(lib)

add_executable(Day1Part1 ./01_day/01_day.cpp)
target_link_libraries(Day1Part1 aoc)

add_executable(Day1Part2 ./01_day/01_day.cpp)
target_link_libraries(Day1Part2 aoc)
target_compile_definitions(Day1Part2 PRIVATE PART_2)

add_executable(Day2Part1 ./02_day/02_day.cpp)
target_link_libraries(Day2Part1 aoc)

add_executable(Day2Part2 ./02_day/02_day_part2.cpp)
target_link_libraries(Day2Part2 aoc)

add_executable(Day3Part1 ./03_day/03_day.cpp)
target_link_libraries(Day3Part1 aoc)

add_executable(Day3Part2 ./03_day/03_day_part2.cpp)
target_link_libraries(Day3Part2 aoc)