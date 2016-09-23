#include <stdio.h>
#include<stdlib.h>
#include "FileUtils.h"

//Abre el archivo y guarda en buff la cantidad de caracteres
//especificada en size apartir de la posicion INIT del archivo.
// Regresa INIT si hubo error o INIT + size si fue exitosa la operacion.
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

//Abre el archivo y escribe el contenido de buff. Regresa INIT_OUT mas size para tener
//un control de la posicion a la que se debe escribir la proxuma vez al archivo
long int writeNCHars(char *buff, int size, long int init_out, char *nombreArchivo) {
    FILE * archivo;
    if ((archivo = fopen(nombreArchivo, "r+")) == NULL) {
        printf("Error al abrir el archivo");
        return init_out;
    }
    fseek(archivo, init_out, SEEK_SET);
    fprintf(archivo, "%s", buff);
    fclose(archivo);
    return init_out + size - 1;
}
