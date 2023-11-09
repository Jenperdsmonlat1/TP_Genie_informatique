cmake_minimum_required(VERSION 3.26)

project(TP8 C)
set(C_STANDARD_REQUIRED 99)

add_executable(addition addition.c)
target_link_libraries(addition m)
