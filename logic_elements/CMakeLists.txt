# cmake.options
cmake_minimum_required(VERSION 3.20)
project(logic_elements)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")

# extra paths
cmake_path(SET GRAPHLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/Graph_lib")
cmake_path(SET LOGICLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/logic_lib")
cmake_path(SET EXTRALIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/extra_lib")
include_directories(${LOGICLIB_DIR} ${GRAPHLIB_DIR} ${EXTRALIB_DIR})

# projects (schemes)
add_subdirectory("schemes/beautiful_decoder")
add_subdirectory("schemes/decoder_variety")
