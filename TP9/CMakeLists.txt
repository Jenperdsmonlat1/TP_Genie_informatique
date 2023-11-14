cmake_minimum_required(VERSION 3.26)

project(TP9 C)
set(CMAKE_C_STANDARD 99)

add_executable(sondage sondage.c)
target_link_libraries(sondage m)
