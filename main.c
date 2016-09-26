#include <stdio.h>

#include "FileUtils.h"
#include "Reservadas.h"
//#include "Separadores.h"

long int INIT;
long int SIG;
long int INIT_OUT;
long int SIG_OUT;

int main() {
    char ARCHIVO_ENTRADA[100];
    printf("\t\t\t\t\t-Analizador Lexico-\n");
    seleccionarArchivo(ARCHIVO_ENTRADA);

    int resultado = lexico_res(4,0, ARCHIVO_ENTRADA);
    printf("Resultado=%d",resultado);
}
