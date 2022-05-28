cmake_minimum_required(VERSION 3.10)

project(list_demo)

add_library(list list.c)
add_executable(list_demo test.c)
target_link_libraries(list_demo list)