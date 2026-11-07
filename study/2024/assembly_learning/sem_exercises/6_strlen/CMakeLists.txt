# language: CMake

cmake_minimum_required(VERSION 3.20)

project(StrLenLesson LANGUAGES C CXX ASM)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17 -Og")

file(GLOB_RECURSE ASM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.s"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.asm")

file(GLOB_RECURSE C_CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_executable(str_len_lesson ${C_CPP_SOURCES} ${ASM_SOURCES})