#include <stdio.h>
#include<stdlib.h>
#include "FileUtils.h"

//Abre el archivo y guarda en buff la cantidad de caracteres
//especificada en size apartir de la posicion init del archivo.
// Regresa init si hubo error o init + size si fue exitosa la operacion.
long int getNChars(char *buff, int size, long int init, char *nombreArchivo) {
    FILE *archivo;
    if ((archivo = fopen(nombreArchivo, "r")) == NULL) {
        printf("Error al abrir el archivo");
        return init;
    }
    fseek(archivo, init, SEEK_SET);
    for (int i = 0; i < size; ++i) {
        if (feof(archivo))
            return init + i;
        else
            buff[i] = (char) fgetc(archivo);
    }
    fclose(archivo);
    return init + size;
}
