cmake_minimum_required(VERSION 3.6)
project(AnalizadorLexico)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c FileUtils.c FileUtils.h)
add_executable(AnalizadorLexico ${SOURCE_FILES})