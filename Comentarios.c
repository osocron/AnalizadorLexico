#include "Comentarios.h"
#include "FileUtils.h"

#define ESTADO_COM 7 //-
#define CODIGO_COM 3 // |

int lexico_com(long int *init, char *nombreArchivoEntrada, int *eof) {

    unsigned int codigo;
    unsigned int salida = 0, estado = 0;

    static unsigned int matriz_transicion_comentario[ESTADO_COM][CODIGO_COM] = {
            /*  /, *, otro */
            {1, 4, 6},
            {2, 3, 0},
            {0, 0, 0},
            {0, 0, 0},
            {5, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    static unsigned int matriz_salida_comentario[ESTADO_COM][CODIGO_COM] = {
            {0, 0, 0},// estado inicial
            {0, 0, 1},// salida de diagonal (no es comentario)
            {2, 2, 2},//  comentario //
            {3, 3, 3},//  comentario /*
            {0, 4, 4},// salida con * (no es comentario)
            {5, 5, 5},//  comentario */
            {6, 6, 6}// salida rapida
    };

    while (salida == 0) {
        codigo = filtro_com(init, nombreArchivoEntrada, eof);
        salida = matriz_salida_comentario[estado][codigo];
        estado = matriz_transicion_comentario[estado][codigo];
    }

    return salida;

}

unsigned int filtro_com(long int *init, char *nombreArchivoEntrada, int *eof) {

    char buff[1];
    *init = getNChars(buff, 1, *init, nombreArchivoEntrada, eof);
    if (buff[0] == '/')
        return 0;
    else if (buff[0] == '*')
        return 1;
    else
        return 2;
}
