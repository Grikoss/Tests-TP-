#include <stdbool.h>
#include <stdio.h>
#include "binary.h"

#define SIZE_OF_INT 32

unsigned int binaryPacker(bool array[]) {
    unsigned value = 0;
    int powerOfTwo = 1;
    for (int i = 0; i < SIZE_OF_INT; ++i) {
        if (array[i]) {
            value += powerOfTwo;
        }
        powerOfTwo *= 2;
    }
    return value;
}

void getPositiveInteger(const char* input, char* buffer, const int size)
{
    bool array[SIZE_OF_INT] = { 0 };

    for (int i = 0; input[i] != '\0' && i < SIZE_OF_INT; ++i)
    {
        if (input[i] != '0')
        {
            array[i] = 1;
        }
    }
    sprintf_s(buffer, size, "%u", binaryPacker(array));
}