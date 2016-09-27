#include <stdio.h>

#include "FileUtils.h"
#include "Reservadas.h"
#include "Numeros.h"
#include "Identificador.h"
#include "Reservadas.h"
#include "Separadores.h"
#include "Operadores.h"


int main() {

    long int INIT = 0;
    //long int SIG = 0;
    long int INIT_OUT = 0;
    long int SIG_OUT = 0;
    char ARCHIVO_ENTRADA[100] = "input.txt";
    char ARCHIVO_SALIDA[] = "output.txt";

    //Localizar el archivo de entrada
    printf("\t\t\t\t\t-Analizador Lexico-\n");
    //seleccionarArchivo(ARCHIVO_ENTRADA);

    //token es la variable que guarda el resultado de llamar la funcion lexico de cada
    //automata.
    int token;
    token = lexico_num(&INIT, ARCHIVO_ENTRADA);

    while (INIT >= 0) {
        //Dependieno el resultado de token se escribe en el archivo de salida
        //el token encontrado.
        switch (token) {
            case 1: {
                //Encontro un +|- pero no encontro un digito o punto despues
                printf("%s", "No reconocido");
                break;
            } //ir al siguiente automata
            case 2: {
                INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
                SIG_OUT += 1;
                token = lexico_num(&INIT, ARCHIVO_ENTRADA);
                printf("%li", INIT);
                break;
            }
            case 3: {
                INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
                //Ir a siguiente automata porque se encontro un punto sin un numero depues
                break;
            }
            case 4: {
                INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
                SIG_OUT += 1;
                break;
            }
            case 5: {
                INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
                //Ir a siguiente automata porque se encontro un E|e sin un numero depues
                break;
            } // Error!
            case 6: {
                INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
                //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
                //no se encontro un digito despues
                break;
            }
            case 7: {
                INIT_OUT = writeNCHars("CTF", 4, INIT_OUT, ARCHIVO_SALIDA);
                SIG_OUT += 1;
                break;
            }
            case 8: {
                //Ir a siguiente automata porque se encontro un punto pero sin digito depues
                break;
            }
            case 9: {
                INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
                //Ir a siguiente porque se encontro E|e sin digito despues
                break;
            }
            case 10: {
                INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
                //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
                //no se encontro un digito despues
                break;
            }
            case 11: {
                //Salida rapida
                break;
            }
            default:
                break;
        }
    }

    return 0;

}
