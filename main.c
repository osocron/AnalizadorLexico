#include <stdio.h>
#include "FileUtils.h"

#define ESTADO_SEP 14
#define CODIGO_SEP 11

int lexico_sep();

int main() {
    char buffer[30];
    long int init = 0;
    init = getNChars(buffer, 30, init, "input.txt");
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

int lexico_sep() {

    /*static unsigned int matriz_transicion_separadores[ESTADO_SEP][CODIGO_SEP] = {
            {201, 202, 203, 204, 205, 206, 207, 208, 209, 211,   0},
            {  0,	0,   0,   0,   0,   0,   0,   0,   0,   0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0, 210,   0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0, 212,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0, 213,   0},
            {  0,   0,   0,   0,   0,   0,   0,   0,   0,	0,   0}
    };

    static unsigned int matriz_salida_separadores[ESTADO_SEP][CODIGO_SEP] = {
            { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
            { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
            { 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2},
            { 3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3},
            { 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4},
            { 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5},
            { 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6},
            { 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7},
            { 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8},
            { 9,  9,  9,  9,  9,  9,  9,  9,  0,  9,  9},
            {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
            {11, 11, 11, 11, 11, 11, 11, 11, 11,  0, 11},
            {12, 12, 12, 12, 12, 12, 12, 12, 12,  0, 12},
            {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
    };*/

    return 0;

}