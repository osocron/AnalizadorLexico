//
// Created by David on 9/24/16.
//

#include <memory.h>
#include "Reservadas.h"
#include "FileUtils.h"


int lexico_res(int tamPalabra,long int *iniPalabra, char *nombreArchivoEntrada) {

    char token[tamPalabra];
    *iniPalabra = getNChars(token, tamPalabra, *iniPalabra, nombreArchivoEntrada);
    if (strcmp(token, "auto") == 0){
        return 0;
    }
    else if (strcmp(token, "break") == 0){
        return 1;
    }
    else if (strcmp(token, "case") == 0){
        return 2;
    }
    else if (strcmp(token, "char") == 0){
        return 3;
    }
    else if (strcmp(token, "const") == 0){
        return 4;
    }
    else if (strcmp(token, "continue") == 0){
        return 5;
    }
    else if (strcmp(token, "default") == 0){
        return 6;
    }
    else if (strcmp(token, "do") == 0){
        return 7;
    }
    else if (strcmp(token, "double") == 0){
        return 8;
    }
    else if (strcmp(token, "else") == 0){
        return 9;
    }
    else if (strcmp(token, "enum") == 0){
        return 10;
    }
    else if (strcmp(token, "extern") == 0){
        return 11;
    }
    else if (strcmp(token, "float") == 0){
        return 12;
    }
    else if (strcmp(token, "for") == 0){
        return 13;
    }
    else if (strcmp(token, "goto") == 0){
        return 14;
    }
    else if (strcmp(token, "if") == 0){
        return 15;
    }
    else if (strcmp(token, "int") == 0){
        return 16;
    }
    else if (strcmp(token, "long") == 0){
        return 17;
    }
    else if (strcmp(token, "register") == 0){
        return 18;
    }
    else if (strcmp(token, "return") == 0){
        return 19;
    }
    else if (strcmp(token, "short") == 0){
        return 20;
    }
    else if (strcmp(token, "signed") == 0){
        return 21;
    }
    else if (strcmp(token, "sizeof") == 0){
        return 22;
    }
    else if (strcmp(token, "static") == 0){
        return 23;
    }
    else if (strcmp(token, "struct") == 0){
        return 24;
    }
    else if (strcmp(token, "switch") == 0){
        return 25;
    }
    else if (strcmp(token, "typedef") == 0){
        return 26;
    }
    else if (strcmp(token, "union") == 0){
        return 27;
    }
    else if (strcmp(token, "unsigned") == 0){
        return 28;
    }
    else if (strcmp(token, "void") == 0){
        return 29;
    }
    else if (strcmp(token, "volatile") == 0){
        return 30;
    }
    else if (strcmp(token, "while") == 0){
        return 31;
    }
    else{
        return 32;//no es palabra reservada
    }
}
