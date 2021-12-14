#include <stdbool.h>
#include <string.h>
#include "binary.h"
#include "binaryTest.h"

#define SIZE 32

bool isGetPositiveIntegerBehavesIncorrectly(void)
{
    char buffer[SIZE] = { 0 };
    getPositiveInteger("0", buffer, SIZE);
    bool result = strcmp("0", buffer);
    getPositiveInteger("10", buffer, SIZE);
    result = result || strcmp("1", buffer);
    getPositiveInteger("101", buffer, SIZE);
    result = result || strcmp("5", buffer);
    return result;
}