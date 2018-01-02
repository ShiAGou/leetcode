cmake_minimum_required(VERSION 3.9)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph main.cpp Digraph.h Search.h Cut.h Undigraph.h ConnectedComponent.h Flow.h)