cmake_minimum_required(VERSION 3.10)

project(test_stack)

add_library(ds_stack stack.c)
add_executable(test_stack test.c)
target_link_libraries(test_stack ds_stack)