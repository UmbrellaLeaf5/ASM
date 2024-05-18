cmake_minimum_required(VERSION 3.20)

project(ExamExersise LANGUAGES C CXX ASM)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17 -Og")

file(GLOB ASM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.s"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.asm")

file(GLOB C_CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_executable(exam_exersise ${C_CPP_SOURCES} ${ASM_SOURCES})