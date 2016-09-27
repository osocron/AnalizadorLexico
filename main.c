#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#include "FileUtils.h"
#include "Numeros.h"
#include "Identificador.h"
#include "Reservadas.h"
#include "Separadores.h"
#include "Operadores.h"

int automata_numeros(int *token, long int *init);
int automata_identificadores(int *token, long int *init);
int automata_reservadas(int *token, long int *init);
int automata_otros(int *token, long int *init, int *eof);
int automata_operadores(int *token, long int *init);
int automata_separadores(int *token, long int *init);

int SIG = 0;
long int INIT_OUT = 0;
int SIG_OUT = 0;
char ARCHIVO_ENTRADA[100] = "input.txt";
char ARCHIVO_SALIDA[] = "output.txt";

int main() {

    long int INIT = 0;
    int eof = 0;

    //Localizar el archivo de entrada
    printf("\t\t\t\t\t-Analizador Lexico-\n");
    //seleccionarArchivo(ARCHIVO_ENTRADA);

    //token es la variable que guarda el resultado de llamar la funcion lexico de cada
    //automata.
    int token;

    int siguiente_automata = 0;
    while (eof != -1) {
        //Dependieno el resultado de token se escribe en el archivo de salida
        //el token encontrado.
        if (siguiente_automata == 0) {
            token = lexico_num(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_numeros(&token, &INIT);
        }
        if (siguiente_automata == 2) {
            token = lexico_sep(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_separadores(&token, &INIT);
        }
        if (siguiente_automata == 4) {
            token = lexico_ope(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_operadores(&token, &INIT);
        }
    }

    return 0;

}

int automata_numeros(int *token, long int *init) {
    int siguiente_automata = 1;
    switch (*token) {
        case 1: {
            //Encontro un +|- pero no encontro un digito o punto despues
            //Ir a automata de identificadores
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata identifique +|-
            siguiente_automata = 2;
            break;
        }
        case 2: {
            INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 3: {
            INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un punto sin un numero depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el punto
            siguiente_automata = 2;
            break;
        }
        case 4: {
            INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 5: {
            INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e sin un numero depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique E|e
            siguiente_automata = 2;
            break;
        } // Error!
        case 6: {
            INIT_OUT = writeNCHars("DEC", 4, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
            //no se encontro un digito despues
            *init -= 2; //Disminuir INIT en dos para que el siguiente automata indentifique apartir de E|e
            siguiente_automata = 2;
            break;
        }
        case 7: {
            INIT_OUT = writeNCHars("CTF", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 8: {
            //Ir a siguiente automata porque se encontro un punto pero sin digito depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el punto
            siguiente_automata = 2;
            break;
        }
        case 9: {
            INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente porque se encontro E|e sin digito despues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique E|e
            siguiente_automata = 2;
            break;
        }
        case 10: {
            INIT_OUT = writeNCHars("DIG", 4, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
            //no se encontro un digito despues
            *init -= 2; //Disminuir INIT en dos para que el siguiente automata indentifique apartir de E|e
            siguiente_automata = 2;
            break;
        }
        case 11: {
            //Salida rapida
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el caracter desconocido
            siguiente_automata = 2;
            break;
        }
        default:
            break;
    }
    return siguiente_automata;
}

int automata_separadores(int *token, long int *init) {
    int siguiente_automata = 3;
    switch (*token) {
        case 1: {
            INIT_OUT = writeNCHars("ACOR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 2: {
            INIT_OUT = writeNCHars("CCOR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 3: {
            INIT_OUT = writeNCHars("APAR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 4: {
            INIT_OUT = writeNCHars("CPAR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 5: {
            INIT_OUT = writeNCHars("ALLA", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 6: {
            INIT_OUT = writeNCHars("CLLA", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 7: {
            INIT_OUT = writeNCHars("COMM", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 8: {
            INIT_OUT = writeNCHars("PCOM", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 9: {
            INIT_OUT = writeNCHars("DDOT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 10: {
            INIT_OUT = writeNCHars("DDDT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 11: {
            //Se encontro un punto, ir a automata de operadores
            *init -= 1;
            siguiente_automata = 4;
            break;
        }
        case 12: {
            //Se encontraron dos puntos, ir a automata de operadores
            *init -= 2;
            siguiente_automata = 4;
            break;
        }
        case 13: {
            INIT_OUT = writeNCHars("ELPS", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 14: {
            //Salida ir a siguiente automata
            siguiente_automata = 4;
            break;
        }
        default:break;
    }
    return siguiente_automata;
}

int automata_operadores(int *token, long int *init) {
    int siguiente_automata = 0;
    switch (*token) {
        case 1: {
            INIT_OUT = writeNCHars("DREF", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 2: {
            INIT_OUT = writeNCHars("DPTM", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 3: {
            INIT_OUT = writeNCHars("REST", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 4: {
            INIT_OUT = writeNCHars("SREF", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 5: {
            INIT_OUT = writeNCHars("DECR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 6: {
            INIT_OUT = writeNCHars("DDSG", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 7: {
            INIT_OUT = writeNCHars("APTM", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 8: {
            INIT_OUT = writeNCHars("SUM", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 9: {
            INIT_OUT = writeNCHars("INC", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 10: {
            INIT_OUT = writeNCHars("AASG", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 11: {
            INIT_OUT = writeNCHars("BAND", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 12: {
            INIT_OUT = writeNCHars("LAND", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 13: {
            INIT_OUT = writeNCHars("BAAS", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 14: {

        }
        case 15: {

        }
        case 16: {

        }
        case 17: {

        }
        case 18: {

        }
        case 19: {

        }
        case 20: {

        }
        case 21: {

        }
        case 22: {

        }
        case 23: {

        }
        case 24: {

        }
        case 25: {

        }
        case 26: {

        }
        case 27: {

        }
        case 28: {

        }
        case 29: {

        }
        case 30: {

        }
        case 31: {

        }
        case 32: {

        }
        case 33: {

        }
        case 34: {

        }
        case 35: {

        }
        case 36: {

        }
        case 37: {

        }
        case 38: {

        }
        case 39: {

        }
        case 40: {

        }
        case 41: {

        }
        default:break;
    }
    return siguiente_automata;
}

int automata_otros(int *token, long int *init, int *eof) {
    int siguiente_automata = 0;
    //Espacio, nueva linea, tab
    char buff[1];
    getNChars(buff, 1, *init, ARCHIVO_ENTRADA, eof);
    if (isspace(buff[0])){

    }
    else if (strcmp(buff, "\t") == 0){

    }
    else if (strcmp(buff, "\n") == 0){

    }
    else if (strcmp(buff, "\v") == 0){

    }
    else if (strcmp(buff, "\f") == 0){

    }
    else if (strcmp(buff, "\r") == 0){

    }
    else {
        //Ir a siguiente automata
    }
    return siguiente_automata;
}

int automata_identificadores(int *token, long int *init) {
    int siguiente_automata = 0;
    switch (*token) {
        case 1: {
            //L|_
            //Ir a automata de reservadas
            break;
        }
        case 2: {
            //L|_|D
            //Ir a automata de reservadas
            break;
        }
        case 3: {
            //Salida rapida ir a automata Operadores?
            break;
        }
        default:break;
    }
    return siguiente_automata;
}

int automata_reservadas(int *token, long int *init) {
    int siguiente_automata = 0;
    switch (*token) {
        case 0: {

        }
        case 1: {

        }
        case 2: {

        }
        case 3: {

        }
        case 4: {

        }
        case 5: {

        }
        case 6: {

        }
        case 7: {

        }
        case 8: {

        }
        case 9: {

        }
        case 10: {

        }
        case 11: {

        }
        case 12: {

        }
        case 13: {

        }
        case 14: {

        }
        case 15: {

        }
        case 16: {

        }
        case 17: {

        }
        case 18: {

        }
        case 19: {

        }
        case 20: {

        }
        case 21: {

        }
        case 22: {

        }
        case 23: {

        }
        case 24: {

        }
        case 25: {

        }
        case 26: {

        }
        case 27: {

        }
        case 28: {

        }
        case 29: {

        }
        case 30: {

        }
        case 31: {

        }
        case 32: {
            //No es palabra reservada
        }
        default:break;
    }
    return siguiente_automata;
}
 
