cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(GomokuAI
        VERSION 1.0
        DESCRIPTION "Gomoku AI"
        LANGUAGES CXX)

include_directories(src)
add_executable(pbrain-gomoku-ai main.cpp)
add_subdirectory(src)
