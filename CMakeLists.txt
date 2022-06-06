cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake main.cpp SnakeBoard.cpp SnakeBoard.h)
