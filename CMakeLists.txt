cmake_minimum_required(VERSION 3.25)
project(c_emv C)

set(CMAKE_C_STANDARD 17)

add_executable(c_emv main.c util.c util.h protocol/data_element.h)
