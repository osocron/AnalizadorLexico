#include <stdio.h>
#include "FileUtils.h"
//#include "Separadores.h"

#define ARCHIVO_ENTRADA "input.txt"

long int INIT;
long int SIG;
long int INIT_OUT;
long int SIG_OUT;

int main() {
    char buffer[30];
    INIT = 0;
    INIT = getNChars(buffer, 30, INIT, ARCHIVO_ENTRADA);//borrar este comentario
    for (int i = 0; i < 30; ++i) {
        printf("%c", buffer[i]);
    }
    char other_buff[12] = "Hola mundo ";
    long int init_out = 0;
    init_out = writeNCHars(other_buff, 12, init_out, "output.txt");
    init_out = writeNCHars(other_buff, 12, init_out, "output.txt");
    init_out = writeNCHars(other_buff, 12, init_out, "output.txt");
    return (int) init_out;
}
