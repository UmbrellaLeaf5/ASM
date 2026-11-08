cmake_minimum_required(VERSION 3.20)

add_subdirectory(logic_elements)

find_package(Python3 QUIET COMPONENTS Interpreter)

if(Python3_Interpreter_FOUND)
    add_custom_target(state_machines_executor_run
        COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/state_machines_executor/main.py"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/state_machines_executor"
        USES_TERMINAL
        VERBATIM
    )
else()
    add_custom_target(state_machines_executor_run
        COMMAND "${CMAKE_COMMAND}" -E echo "Python 3 is required to run state_machines_executor"
        COMMAND "${CMAKE_COMMAND}" -E false
        VERBATIM
    )
endif()
