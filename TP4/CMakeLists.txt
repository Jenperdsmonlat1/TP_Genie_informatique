cmake_minimum_required(VERSION 3.26)
project(fractions C)

set(CMAKE_C_STANDARD 99)

add_executable(fractions fractions.c)
target_link_libraries(fractions m)