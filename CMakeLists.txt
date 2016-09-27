cmake_minimum_required(VERSION 3.6)
project(AnalizadorLexico)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c FileUtils.c FileUtils.h Separadores.c Separadores.h Reservadas.c Reservadas.h Operadores.c Operadores.h Identificador.c Identificador.h Numeros.c Numeros.h Comentarios.c Comentarios.h)
add_executable(AnalizadorLexico ${SOURCE_FILES})