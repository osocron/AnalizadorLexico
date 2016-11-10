//
// Created by osocron on 9/28/16.
//

#include <ctype.h>
#include <memory.h>
#include "Otros.h"
#include "FileUtils.h"

int lexico_otros(long int *init, char *nombreArchivoEntrada, int *eof) {
    char buff[1];
    *init = getNChars(buff, 1, *init, nombreArchivoEntrada, eof);
    if (buff[0] == ' '){
        return 1;
    }
    else if (buff[0] == '\t'){
        return 2;
    }
    else if (buff[0] == '\n'){
        return 3;
    }
    else if (buff[0] == '\v'){
        return 4;
    }
    else if (buff[0] == '\f'){
        return 5;
    }
    else if (buff[0] == '\r'){
        return 6;
    }
    else {
        return 7;
    }
}