cmake_minimum_required(VERSION 3.9)
project(suffix_array)

set(CMAKE_CXX_STANDARD 11)

add_executable(suffix_array main.cpp SuffixArray.cpp SuffixArray.h)