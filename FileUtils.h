//
// Created by osocron on 9/22/16.
//

#ifndef ANALIZADORLEXICO_FILEUTILS_H
#define ANALIZADORLEXICO_FILEUTILS_H
long int getNChars(char *buff, int size, long int init, char *nombreArchivo, int *eof);
long int writeNCHars(char *buff, int size, long int init_out, char *nombreArchivo);
void seleccionarArchivo(char *ARCHIVO_ENTRADA, char *ARCHIVO_SALIDA);
void crearArchivoSalida(char *ARCHIVO_SALIDA);
#endif //ANALIZADORLEXICO_FILEUTILS_H
