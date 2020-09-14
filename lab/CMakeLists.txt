cmake_minimum_required(VERSION 3.16)
project(lab C)

set(CMAKE_C_STANDARD 99)

add_executable(hash hashTest.c hash.c)
add_executable(lab main.c dictionary.c)