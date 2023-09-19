cmake_minimum_required(VERSION 3.26)
project(geometrie C)

set(CMAKE_C_STANDARD 99)

add_executable(geometrie geometrie.c)
target_link_libraries(geometrie m)