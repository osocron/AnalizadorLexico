#include "Identificador.h"
#include "FileUtils.h"
#include "ctype.h"

#define ESTADO_IDE 4 //-
#define CODIGO_IDE 4 // |

int lexico_ide(long int *init, char *nombreArchivoEntrada, int *contador) {

    unsigned int codigo;
    unsigned int salida = 0, estado = 0;

    static unsigned int matriz_transicion_identificador[ESTADO_IDE][CODIGO_IDE] = {
            /*L, _, D, otro*/
            {1, 1, 3, 3},
            {2, 2, 2, 0},
            {2, 2, 2, 0},
            {0, 0, 0, 0}
    };

    static unsigned int matriz_salida_identificador[ESTADO_IDE][CODIGO_IDE] = {
            {0, 0, 0, 0},// Estado Inicial
            {0, 0, 0, 1},// L,_
            {0, 0, 0, 2},// L,_,D
            {3, 3, 3, 3}// Salida rapida
    };

    while (salida == 0) {
        codigo = filtro_ide(init, nombreArchivoEntrada, contador);
        salida = matriz_salida_identificador[estado][codigo];
        estado = matriz_transicion_identificador[estado][codigo];
    }

    return salida;

}

unsigned int filtro_ide(long int *init, char *nombreArchivoEntrada, int *cont) {

    char buff[1];
    *cont += 1;
    *init = getNChars(buff, 1, *init, nombreArchivoEntrada);
    if (isalpha(buff[0]))
        return 0;
    else if (buff[0] == '_')
        return 1;
    else if (isdigit(buff[0]))
        return 2;
    else
        return 3;
}
