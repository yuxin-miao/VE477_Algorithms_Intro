cmake_minimum_required(VERSION 3.16)
project(lab)

set(CMAKE_CXX_STANDARD 11)

add_executable(hash hashTest.c hash.c)
add_executable(lab main.c dictionary.c)
add_executable(Try try.cpp)