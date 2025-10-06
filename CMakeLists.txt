cmake_minimum_required(VERSION 3.10)  # You should use at least CMake 3.10
project(BOHOL_ C)

set(CMAKE_C_STANDARD 11)

# Add source files for the project
add_executable(BOHOL_
        main.c
        linked_list.c
        stack.c
        queue.c
)