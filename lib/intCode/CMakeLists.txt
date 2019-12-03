cmake_minimum_required(VERSION 3.0.0)
project(lib_intcode VERSION 0.1.0 LANGUAGES CXX)

add_library(intCode src/intCode.cpp)
target_include_directories(intCode PUBLIC inc)
install(TARGETS intCode DESTINATION lib)
install(FILES intCode.hpp DESTINATION include)