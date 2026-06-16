cmake_minimum_required(VERSION 3.10)
project(ChessEngine VERSION 0.1)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake where to find source files and what to build
add_executable(chess-engine src/main.cpp)
