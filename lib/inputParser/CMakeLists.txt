cmake_minimum_required(VERSION 3.0.0)
project(lib_inputparser VERSION 0.1.0 LANGUAGES CXX)

add_library(inputParser src/inputParser.cpp)
target_include_directories(inputParser PUBLIC inc)
install(TARGETS inputParser DESTINATION lib)
install(FILES inputParser.hpp DESTINATION include)