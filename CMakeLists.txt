cmake_minimum_required(VERSION 3.10)
project(ChessEngine VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL3 REQUIRED CONFIG)

add_executable(chess-engine)

target_sources(chess-engine PRIVATE
    src/main.cpp
    src/board.cpp
    src/renderer.cpp
    src/sdl_manager.cpp
    src/game.cpp
)

target_include_directories(chess-engine PRIVATE include)
target_link_libraries(chess-engine PRIVATE SDL3::SDL3)
