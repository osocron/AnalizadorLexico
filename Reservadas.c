//
// Created by David on 9/24/16.
//

#include <memory.h>
#include "Reservadas.h"
#include "FileUtils.h"


int lexico_res(int tamPalabra,long int *init, char *nombreArchivoEntrada, int *eof) {

    char buff[tamPalabra];
    *init -= tamPalabra; //Deberia quedar al inicio de la palabra
    *init = getNChars(buff, tamPalabra - 1, *init, nombreArchivoEntrada, eof);
    buff[tamPalabra - 1] = '\0';
    if (strcmp(buff, "auto") == 0){
        return 0;
    }
    else if (strcmp(buff, "break") == 0){
        return 1;
    }
    else if (strcmp(buff, "case") == 0){
        return 2;
    }
    else if (strcmp(buff, "char") == 0){
        return 3;
    }
    else if (strcmp(buff, "const") == 0){
        return 4;
    }
    else if (strcmp(buff, "continue") == 0){
        return 5;
    }
    else if (strcmp(buff, "default") == 0){
        return 6;
    }
    else if (strcmp(buff, "do") == 0){
        return 7;
    }
    else if (strcmp(buff, "double") == 0){
        return 8;
    }
    else if (strcmp(buff, "else") == 0){
        return 9;
    }
    else if (strcmp(buff, "enum") == 0){
        return 10;
    }
    else if (strcmp(buff, "extern") == 0){
        return 11;
    }
    else if (strcmp(buff, "float") == 0){
        return 12;
    }
    else if (strcmp(buff, "for") == 0){
        return 13;
    }
    else if (strcmp(buff, "goto") == 0){
        return 14;
    }
    else if (strcmp(buff, "if") == 0){
        return 15;
    }
    else if (strcmp(buff, "int") == 0){
        return 16;
    }
    else if (strcmp(buff, "long") == 0){
        return 17;
    }
    else if (strcmp(buff, "register") == 0){
        return 18;
    }
    else if (strcmp(buff, "return") == 0){
        return 19;
    }
    else if (strcmp(buff, "short") == 0){
        return 20;
    }
    else if (strcmp(buff, "signed") == 0){
        return 21;
    }
    else if (strcmp(buff, "sizeof") == 0){
        return 22;
    }
    else if (strcmp(buff, "static") == 0){
        return 23;
    }
    else if (strcmp(buff, "struct") == 0){
        return 24;
    }
    else if (strcmp(buff, "switch") == 0){
        return 25;
    }
    else if (strcmp(buff, "typedef") == 0){
        return 26;
    }
    else if (strcmp(buff, "union") == 0){
        return 27;
    }
    else if (strcmp(buff, "unsigned") == 0){
        return 28;
    }
    else if (strcmp(buff, "void") == 0){
        return 29;
    }
    else if (strcmp(buff, "volatile") == 0){
        return 30;
    }
    else if (strcmp(buff, "while") == 0){
        return 31;
    }
    else{
        return 32;//no es palabra reservada
    }
}
