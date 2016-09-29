#include <stdio.h>
#include<stdlib.h>
#include <memory.h>
#include "FileUtils.h"

//Abre el archivo y guarda en buff la cantidad de caracteres
//especificada en size apartir de la posicion INIT del archivo.
// Regresa INIT si hubo error o INIT + size si fue exitosa la operacion.
long int getNChars(char *buff, int size, long int init, char *nombreArchivo, int *eof) {
    FILE *archivo;
    if ((archivo = fopen(nombreArchivo, "r")) == NULL) {
        printf("Error al abrir el archivo");
        return init;
    }
    fseek(archivo, init, SEEK_SET);
    for (int i=0; i < size; ++i) {
        if ((buff[i] = (char) fgetc(archivo)) == EOF) {
            fclose(archivo);
            *eof = -1;
            return init + size;
        }
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

void seleccionarArchivo(char *ARCHIVO_ENTRADA){
    FILE *archivo;
    printf("Dame el nombre del archivo (con extension): ");
    do{
        fflush(stdin);
        scanf("%s", ARCHIVO_ENTRADA);
        archivo=fopen(ARCHIVO_ENTRADA, "r");
        if(archivo==NULL)
            printf("\t*El archivo \"%s\" no existe o no se encuentra en la carpeta.\n\nIngrese un nombre valido (con extension): ",ARCHIVO_ENTRADA);
        else
            fclose(archivo);
    }while(archivo==NULL);
}
//metodo para la creación de archivo de salida con extensión ".lex"
void crearArchivoSalida(char *ARCHIVO_ENTRADA,char *ARCHIVO_SALIDA){
    FILE *archivo;
    size_t longitud= strlen(ARCHIVO_ENTRADA), contador=longitud-1;
    while(contador>=0){
        //realiza recorrido del nombre del archipo para encontar el "."
        if(ARCHIVO_ENTRADA[contador]=='.'){
            //si encontro el punto realiza el cambio de la extension de nombre.origen hacia destino.lex
            strncpy(ARCHIVO_SALIDA, ARCHIVO_ENTRADA, contador);//consigue nombre sin extensión (archivos .c)
            strcat( ARCHIVO_SALIDA, ".lex" );
            archivo=fopen(ARCHIVO_SALIDA, "w");
            fclose(archivo);
            break;
        }
        else{//si en la posición no se encontro el punto, se dirigira el apuntado hacia atras.
            contador--;
        }
    }
}