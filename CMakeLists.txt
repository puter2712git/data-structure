cmake_minimum_required(VERSION 3.10)
project(dss)

set(CMAKE_C_STANDARD 11)
set(SOURCES
    src/main.c
    src/data-structure/stack.c
    src/data-structure/queue.c
    src/simulator/simulator.c
    src/simulator/subsim/stacksim.c
)

add_executable(dss ${SOURCES})

target_include_directories(dss PRIVATE src)
