cmake_minimum_required(VERSION 3.6)
project(lexer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lexer_main.cpp)
add_executable(lexer ${SOURCE_FILES})