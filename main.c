#include <stdio.h>
#include "FileUtils.h"

int main() {
    char buffer[30];
    long int init = 20;
    init = getNChars(buffer, 30, init, "input.txt");
    for (int i = 0; i < 30; ++i) {
        printf("%c", buffer[i]);
    }
    return (int) init;
}