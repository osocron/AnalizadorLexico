//
// Created by osocron on 9/23/16.
//

#include "Separadores.h"
#include "FileUtils.h"

#define ESTADO_SEP 15
#define CODIGO_SEP 11

int lexico_sep(long int *init, char *nombreArchivoEntrada) {

    unsigned int codigo;
    unsigned int salida = 0, estado = 0;

    static unsigned int matriz_transicion_separadores[ESTADO_SEP][CODIGO_SEP] = {
          //'[' ']' '(' ')' '{' '}' ',' ';' ':' '.' 'otro'
            {1,  2,  3,  4,  5,  6,  7,  8,  9, 11, 14},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,	 0,  0},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
    };

    static unsigned int matriz_salida_separadores[ESTADO_SEP][CODIGO_SEP] = {
            { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, // Estado inicial
            { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1}, // [
            { 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2}, // ]
            { 3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3}, // (
            { 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4}, // )
            { 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5}, // {
            { 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6}, // }
            { 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7}, // ,
            { 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8}, // ;
            { 9,  9,  9,  9,  9,  9,  9,  9,  0,  9,  9}, // :
            {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, // ::
            {11, 11, 11, 11, 11, 11, 11, 11, 11,  0, 11}, // .
            {12, 12, 12, 12, 12, 12, 12, 12, 12,  0, 12}, // ..
            {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13}, // ...
            {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14} // Otro
    };

    while (salida == 0) {
        codigo = filtro_sep(init, nombreArchivoEntrada);
        salida = matriz_salida_separadores[estado][codigo];
        estado = matriz_transicion_separadores[estado][codigo];
    }

    return salida;
}

unsigned int filtro_sep(long int *init, char *nombreArchivoEntrada) {

    char buff[1];
    *init = getNChars(buff, 1, *init, nombreArchivoEntrada);
    if (buff[0] == '[')
        return 0;
    else if (buff[0] == ']')
        return 1;
    else if (buff[0] == '(')
        return 2;
    else if (buff[0] == ')')
        return 3;
    else if (buff[0] == '{')
        return 4;
    else if (buff[0] == '}')
        return 5;
    else if (buff[0] == ',')
        return 6;
    else if (buff[0] == ';')
        return 7;
    else if (buff[0] == ':')
        return 8;
    else if (buff[0] == '.')
        return 9;
    else
        return 10;

}