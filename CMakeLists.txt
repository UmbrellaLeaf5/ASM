# language: CMake

# ---------------------------------     Project setup      ---------------------------------
cmake_minimum_required(VERSION 3.20)

project(assembly LANGUAGES C CXX ASM)

# ---------------------------------    Add subdirectories   --------------------------------
add_subdirectory(study/2024/assembly_learning/assembly_text_task)
add_subdirectory(study/2024/assembly_learning/sem_exercises/6_strlen)
add_subdirectory(study/2024/assembly_learning/exam_exersise)

add_subdirectory(projects)
