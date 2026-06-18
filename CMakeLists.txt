cmake_minimum_required(VERSION 3.10)
project(ChessEngine VERSION 0.1)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(include)

# add source files to the project
set(SOURCES
    src/main.cpp
    src/board.cpp
)

# Tell CMake where to find source files and what to build
add_executable(chess-engine ${SOURCES})
