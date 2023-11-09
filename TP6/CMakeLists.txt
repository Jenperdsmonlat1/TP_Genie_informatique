cmake_minimum_required(VERSION 3.26)

project(TP6 C)
set(CMAKE_C_STANDARD 99)

add_executable(secante secante.c)
target_link_libraries(secante m)