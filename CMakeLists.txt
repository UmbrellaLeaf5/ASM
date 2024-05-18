# language: CMake

cmake_minimum_required(VERSION 3.20)

project(assembly LANGUAGES C CXX ASM)

add_subdirectory(assembly_learning/assembly_text_task)
add_subdirectory(assembly_learning/sem_exercises/6_strlen)
add_subdirectory(assembly_learning/exam_exersise)

add_subdirectory(logic_elements)