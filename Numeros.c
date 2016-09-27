#include <ctype.h>
#include "Numeros.h"
#include "FileUtils.h"

#define ESTADO_NUM 12 //-
#define CODIGO_NUM 7 // |

int lexico_num(long int *init, char *nombreArchivoEntrada, int *eof) {

    unsigned int codigo;
    unsigned int salida = 0, estado = 0;

    static unsigned int matriz_transicion_numero[ESTADO_NUM][CODIGO_NUM] = {
           // +,  -, D, .,  E,  e, otro
            { 1,  1, 2, 8, 11, 11, 11},
            { 0,  0, 2, 8,  0,  0,  0},
            { 0,  0, 2, 3,  9,  9,  0},
            { 0,  0, 4, 0,  0,  0,  0},
            { 0,  0, 4, 0,  5,  5,  0},
            { 6,  6, 7, 0,  0,  0,  0},
            { 0,  0, 7, 0,  0,  0,  0},
            { 0,  0, 7, 0,  0,  0,  0},
            { 0,  0, 4, 0,  0,  0,  0},
            {10, 10, 7, 0,  0,  0,  0},
            { 0,  0, 7, 0,  0,  0,  0},
            { 0,  0, 0, 0,  0,  0,  0}
    };

    static unsigned int matriz_salida_numero[ESTADO_NUM][CODIGO_NUM] = {
            {0,   0,  0,  0,  0,  0,  0},// estado inicial
            { 1,  1,  0,  0,  1,  1,  1},// Siguiente + | -
            { 2,  2,  0,  0,  0,  0,  2},// Salida con digito
            { 3,  3,  0,  3,  3,  3,  3},// Salida decimal
            { 4,  4,  0,  4,  0,  0,  4},// Salida decimal
            { 0,  0,  0,  5,  5,  5,  5},// Salida decimal y manda siguiente 'e' | 'E'
            { 6,  6,  0,  6,  6,  6,  6},// Salida decimal o digito siguiente + | - (**)
            { 7,  7,  0,  7,  7,  7,  7},// Salida cientifica
            { 8,  8,  0,  8,  8,  8,  8},// Siguiente punto
            { 0,  0,  0,  9,  9,  9,  9},// Salida digito siguiente E|e
            {10, 10,  0, 10, 10, 10, 10},// Salida digito siguiente +|- (**)
            {11, 11, 11, 11, 11, 11, 11} // Salida rapida
    };

    while (salida == 0) {
        codigo = filtro_num(init, nombreArchivoEntrada, eof);
        salida = matriz_salida_numero[estado][codigo];
        estado = matriz_transicion_numero[estado][codigo];
    }

    return salida;

}

unsigned int filtro_num(long int *init, char *nombreArchivoEntrada, int *eof) {

    char buff[1];
    *init = getNChars(buff, 1, *init, nombreArchivoEntrada, eof);
    if (buff[0] == '+')
        return 0;
    else if (buff[0] == '-')
        return 1;
    else if (isdigit(buff[0]))
        return 2;
    else if (buff[0] == '.')
        return 3;
    else if (buff[0] == 'E')
        return 4;
    else if (buff[0] == 'e')
        return 5;
    else
        return 6;

}
