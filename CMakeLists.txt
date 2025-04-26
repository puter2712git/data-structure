cmake_minimum_required(VERSION 3.10)
project(dss)

# C 표준 설정 (선택사항이지만 보통 명시해)
set(CMAKE_C_STANDARD 11)

# 소스 파일 목록
set(SOURCES
    src/main.c
    src/data-structure/stack.c
    src/data-structure/queue.c
    src/simulator/simulator.c
    src/simulator/subsim/stacksim.c
)

# executable file
add_executable(dss ${SOURCES})

# include directory
target_include_directories(dss PRIVATE src)
