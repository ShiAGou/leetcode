cmake_minimum_required(VERSION 3.9)
project(suffix_automaton)

set(CMAKE_CXX_STANDARD 11)

add_executable(suffix_automaton main.cpp SuffixAutomaton.cpp SuffixAutomaton.h KthSmallestSubstring.cpp)