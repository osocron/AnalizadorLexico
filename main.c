#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#include "FileUtils.h"
#include "Numeros.h"
#include "Identificador.h"
#include "Reservadas.h"
#include "Separadores.h"
#include "Operadores.h"
#include "Comentarios.h"
#include "Otros.h"

int automata_numeros(int *token, long int *init);
int automata_comentarios(int *token,  long int *init);
int automata_identificadores(int *token, long int *init, int *tamPalabra, int *eof);
int automata_reservadas(int *token, long int *init);
int automata_otros(int *token, long int *init);
int automata_operadores(int *token, long int *init);
int automata_separadores(int *token, long int *init);

long int INIT_OUT = 0;
char ARCHIVO_ENTRADA[] = "input.c";
char ARCHIVO_SALIDA[] = "output.lex";

int main() {

    long int INIT = 0;
    int TAM_PALABRA = 0;
    int eof = 0;

    //Localizar el archivo de entrada
    printf("\t\t\t\t\t-Analizador Lexico-\n");
    //seleccionarArchivo(ARCHIVO_ENTRADA);
    //crearArchivoSalida(ARCHIVO_ENTRADA, ARCHIVO_SALIDA);

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
            INIT -= 1;
        }
        if (siguiente_automata == 1) {
            token = lexico_sep(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_separadores(&token, &INIT);
            INIT -= 1;
        }
        if (siguiente_automata == 2) {
            token = lexico_com(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_comentarios(&token, &INIT);
            INIT -= 1;
        }
        if (siguiente_automata == 3) {
            token = lexico_ope(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_operadores(&token, &INIT);
            INIT -= 1;
        }
        if (siguiente_automata == 4) {
            token = lexico_otros(&INIT, ARCHIVO_ENTRADA, &eof);
            siguiente_automata = automata_otros(&token, &INIT);
        }
        if (siguiente_automata == 5) {
            token = lexico_ide(&INIT, ARCHIVO_ENTRADA, &TAM_PALABRA, &eof);
            automata_identificadores(&token, &INIT, &TAM_PALABRA, &eof);
            siguiente_automata = 0;
        }
        TAM_PALABRA = 0;
    }

    return 0;

}

int automata_numeros(int *token, long int *init) {
    switch (*token) {
        case 1: {
            //Encontro un +|- pero no encontro un digito o punto despues
            //Ir a automata de identificadores
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata identifique +|-
            break;
        }
        case 2: {
            INIT_OUT = writeNCHars("DIG ", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 3: {
            INIT_OUT = writeNCHars("DIG ", 5, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un punto sin un numero depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el punto
            break;
        }
        case 4: {
            INIT_OUT = writeNCHars("DEC ", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 5: {
            INIT_OUT = writeNCHars("DEC ", 5, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e sin un numero depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique E|e
            break;
        } // Error!
        case 6: {
            INIT_OUT = writeNCHars("DEC ", 5, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
            //no se encontro un digito despues
            *init -= 2; //Disminuir INIT en dos para que el siguiente automata indentifique apartir de E|e
            break;
        }
        case 7: {
            INIT_OUT = writeNCHars("CTF ", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 8: {
            //Ir a siguiente automata porque se encontro un punto pero sin digito depues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el punto
            break;
        }
        case 9: {
            INIT_OUT = writeNCHars("DIG ", 5, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente porque se encontro E|e sin digito despues
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique E|e
            break;
        }
        case 10: {
            INIT_OUT = writeNCHars("DIG ", 5, INIT_OUT, ARCHIVO_SALIDA);
            //Ir a siguiente automata porque se encontro un E|e depues un +|- pero
            //no se encontro un digito despues
            *init -= 2; //Disminuir INIT en dos para que el siguiente automata indentifique apartir de E|e
            break;
        }
        case 11: {
            //Salida rapida
            *init -= 1; //Disminuir INIT en uno para que el siguiente automata indentifique el caracter desconocido
            break;
        }
        default:
            break;
    }
    return 1;
}

int automata_separadores(int *token, long int *init) {
    switch (*token) {
        case 1: {
            INIT_OUT = writeNCHars("ACOR ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 2: {
            INIT_OUT = writeNCHars("CCOR ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 3: {
            INIT_OUT = writeNCHars("APAR ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 4: {
            INIT_OUT = writeNCHars("CPAR ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 5: {
            INIT_OUT = writeNCHars("ALLA ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 6: {
            INIT_OUT = writeNCHars("CLLA ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 7: {
            INIT_OUT = writeNCHars("COMM ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 8: {
            INIT_OUT = writeNCHars("PCOM ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 9: {
            INIT_OUT = writeNCHars("DDOT ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 10: {
            INIT_OUT = writeNCHars("DDDT ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 11: {
            //Se encontro un punto, ir a automata de operadores
            *init -= 1;
            break;
        }
        case 12: {
            //Se encontraron dos puntos, ir a automata de operadores
            *init -= 2;
            break;
        }
        case 13: {
            INIT_OUT = writeNCHars("ELPS ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 14: {
            //Salida ir a siguiente automata
            *init -= 1;
            break;
        }
        default:break;
    }
    return 2;
}

int automata_comentarios(int *token,  long int *init) {
    switch (*token) {
        case 1: { //Se encontro una diagonal falta la siguiente
            *init -= 1;
            break;
        }
        case 2: {
            INIT_OUT=writeNCHars("COM ", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 3: {
            INIT_OUT=writeNCHars("ACOM ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 4: { //Sale asterisco pero no es comentario
            *init -= 1;
            break;
        }
        case 5: {
            INIT_OUT=writeNCHars("CCOM ", 6, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 6: {
            *init -= 1;
            break;
        }
        default:break;
    }
    return 3;
}

int automata_operadores(int *token, long int *init) {
    switch (*token) {
        case 1: {
            INIT_OUT = writeNCHars("DREF", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 2: {
            INIT_OUT = writeNCHars("DPTM", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 3: {
            INIT_OUT = writeNCHars("REST", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 4: {
            INIT_OUT = writeNCHars("SREF", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 5: {
            INIT_OUT = writeNCHars("DECR", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 6: {
            INIT_OUT = writeNCHars("DDSG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 7: {
            INIT_OUT = writeNCHars("APTM", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 8: {
            INIT_OUT = writeNCHars("SUM", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 9: {
            INIT_OUT = writeNCHars("INC", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 10: {
            INIT_OUT = writeNCHars("AASG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 11: {
            INIT_OUT = writeNCHars("BAND", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 12: {
            INIT_OUT = writeNCHars("LAND", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 13: {
            INIT_OUT = writeNCHars("BAAS", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 14: {
            INIT_OUT = writeNCHars("MULT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 15: {
            INIT_OUT = writeNCHars("MASG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 16: {
            INIT_OUT = writeNCHars("BNOT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 17: {
            INIT_OUT = writeNCHars("LNOT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 18: {
            INIT_OUT = writeNCHars("NEQT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 19: {
            INIT_OUT = writeNCHars("DIV", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 20: {
            INIT_OUT = writeNCHars("DASG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 21: {
            INIT_OUT = writeNCHars("MOD", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 22: {
            INIT_OUT = writeNCHars("MDSG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 23: {
            INIT_OUT = writeNCHars("LTHN", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 24: {
            INIT_OUT = writeNCHars("BLSH", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 25: {
            INIT_OUT = writeNCHars("BLSA", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 26: {
            INIT_OUT = writeNCHars("LEQT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 27: {
            INIT_OUT = writeNCHars("GTHN", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 28: {
            INIT_OUT = writeNCHars("BRSH", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 29: {
            INIT_OUT = writeNCHars("BRSA", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 30: {
            INIT_OUT = writeNCHars("GEQT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 31: {
            INIT_OUT = writeNCHars("ASSG", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 32: {
            INIT_OUT = writeNCHars("EQUT", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 33: {
            INIT_OUT = writeNCHars("BXOR", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 34: {
            INIT_OUT = writeNCHars("BXAS", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 35: {
            INIT_OUT = writeNCHars("BOR", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 36: {
            INIT_OUT = writeNCHars("LOR", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 37: {
            INIT_OUT = writeNCHars("EXO", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 38: {
            INIT_OUT = writeNCHars("EXOP", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 39: {
            INIT_OUT = writeNCHars("HASH", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 40: {
            INIT_OUT = writeNCHars("DHSH", 5, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 41: {
            *init -= 1;
        }
        default:break;
    }
    return 4;
}

int automata_otros(int *token, long int *init) {
    //Espacio, nueva linea, tab
    switch (*token) {
        case 1: {
            INIT_OUT = writeNCHars(" ", 2, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 2: {
            INIT_OUT = writeNCHars("   ", 4, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 3: {
            INIT_OUT = writeNCHars("\n", 2, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 4: {
            INIT_OUT = writeNCHars("\v", 2, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 5: {
            INIT_OUT = writeNCHars("\f", 2, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 6: {
            INIT_OUT = writeNCHars("\r ", 2, INIT_OUT, ARCHIVO_SALIDA);
            return 0;
        }
        case 7: {
            *init -= 1;
            break;
        }
        default:break;
    }
    return 5;
}

int automata_identificadores(int *token, long int *init, int *tamPalabra, int *eof) {
    int esReservada;
    switch (*token) {
        case 1: {//L|_
            *token = lexico_res(*tamPalabra, init, ARCHIVO_ENTRADA, eof);
            esReservada= automata_reservadas(token, init);
            if (esReservada==0){
                INIT_OUT =writeNCHars("ID ", 4, INIT_OUT, ARCHIVO_SALIDA);
            }
            break;
        }
        case 2: {//L|_|D
            *token = lexico_res(*tamPalabra, init, ARCHIVO_ENTRADA, eof);
            esReservada= automata_reservadas( token, init);
            if (esReservada==0){
                INIT_OUT =writeNCHars("ID ", 4, INIT_OUT, ARCHIVO_SALIDA);
            }
            break;
        }
        case 3: {
            //Es error o final de archivo
            if (*eof != -1)
                INIT_OUT = writeNCHars("ERR ", 5, INIT_OUT, ARCHIVO_SALIDA);
            else {
                char buff[1];
                getNChars(buff, 1, *init - *tamPalabra, ARCHIVO_ENTRADA, eof);
                if (buff[0] == EOF)
                    INIT_OUT = writeNCHars("EOF ", 5, INIT_OUT, ARCHIVO_SALIDA);
                else
                    INIT_OUT = writeNCHars("ERR ", 5, INIT_OUT, ARCHIVO_SALIDA);
            }
            *init -= *tamPalabra - 1;
            break;
        }
        default: break;
    }
    return 6;
}

int automata_reservadas(int *token, long int *init) {
    int esReservada=1;
    switch (*token) {
        case 0: {
            INIT_OUT = writeNCHars("AUTO", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 1: {
            INIT_OUT = writeNCHars("BRK", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 2: {
            INIT_OUT = writeNCHars("CASE", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 3: {
            INIT_OUT = writeNCHars("CHAR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 4: {
            INIT_OUT = writeNCHars("CNST", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 5: {
            INIT_OUT = writeNCHars("CNTN", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 6: {
            INIT_OUT = writeNCHars("DFLT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 7: {
            INIT_OUT = writeNCHars("DO", 3, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 8: {
            INIT_OUT = writeNCHars("DBL", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 9: {
            INIT_OUT = writeNCHars("ELSE", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 10: {
            INIT_OUT = writeNCHars("ENUM", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 11: {
            INIT_OUT = writeNCHars("XTRN", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 12: {
            INIT_OUT = writeNCHars("FLOT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 13: {
            INIT_OUT = writeNCHars("FOR", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 14: {
            INIT_OUT = writeNCHars("GOTO", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 15: {
            INIT_OUT = writeNCHars("IF", 3, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 16: {
            INIT_OUT = writeNCHars("INT", 4, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 17: {
            INIT_OUT = writeNCHars("LONG", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 18: {
            INIT_OUT = writeNCHars("RGTR", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 19: {
            INIT_OUT = writeNCHars("RETN", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 20: {
            INIT_OUT = writeNCHars("SHRT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 21: {
            INIT_OUT = writeNCHars("SIGN", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 22: {
            INIT_OUT = writeNCHars("SIZE", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 23: {
            INIT_OUT = writeNCHars("STAT", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 24: {
            INIT_OUT = writeNCHars("STRC", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 25: {
            INIT_OUT = writeNCHars("SWTC", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 26: {
            INIT_OUT = writeNCHars("TPDF", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 27: {
            INIT_OUT = writeNCHars("UNIN", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 28: {
            INIT_OUT = writeNCHars("NSIG", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 29: {
            INIT_OUT = writeNCHars("VOID", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 30: {
            INIT_OUT = writeNCHars("VLTL", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 31: {
            INIT_OUT = writeNCHars("WHIL", 5, INIT_OUT, ARCHIVO_SALIDA);
            break;
        }
        case 32: {
            //No es palabra reservada
            esReservada=0;
        }
        default:break;
    }
    return esReservada;
}