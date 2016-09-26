//
// Created by osocron on 9/22/16.
//

#ifndef ANALIZADORLEXICO_FILEUTILS_H
#define ANALIZADORLEXICO_FILEUTILS_H
long int getNChars(char *buff, int size, long int init, char *nombreArchivo);
long int writeNCHars(char *buff, int size, long int init_out, char *nombreArchivo);
void seleccionarArchivo(char *ARCHIVO_ENTRADA);
#endif //ANALIZADORLEXICO_FILEUTILS_H
