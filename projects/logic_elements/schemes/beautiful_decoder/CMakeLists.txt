cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "beautiful_decoder")
project(${PROJECT_NAME} CXX)

file(GLOB_RECURSE HEADERS "*.h" "*.hpp"
  "${GRAPHLIB_DIR}/*.h" "${GRAPHLIB_DIR}/*.hpp"
  "${EXTRALIB_DIR}/*.h" "${EXTRALIB_DIR}/*.hpp"
  "${LOGICLIB_DIR}/*.h" "${LOGICLIB_DIR}/*.hpp"
)

file(GLOB_RECURSE SOURCES "*.c" "*.cpp"
  "${GRAPHLIB_DIR}/*.c" "${GRAPHLIB_DIR}/*.cpp"
  "${EXTRALIB_DIR}/*.c" "${EXTRALIB_DIR}/*.cpp"
  "${LOGICLIB_DIR}/*.c" "${LOGICLIB_DIR}/*.cpp"
)

set(FLTK_SKIP_FLUID True)
set(FLTK_SKIP_FORMS True)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})
link_directories(${FLTK_INCLUDE_DIR}/../lib)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})

install(TARGETS ${PROJECT_NAME})
