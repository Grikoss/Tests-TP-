#include <stdlib.h>
#include "combSorting.h"

void swapFunction(int* numberOne, int* numberTwo)
{
    *numberOne = *numberOne + *numberTwo;
    *numberTwo = *numberOne - *numberTwo;
    *numberOne -= *numberTwo;
}

int combSorting(int* array, const int length)
{
    if (array == NULL)
    {
        return 1;
    }
    int step = length / 1.247;
    while (step >= 1)
    {
        for (int i = 0; i + step < length; ++i)
        {
            if (array[i] > array[i + step])
            {
                swapFunction(&array[i], &array[i + step]);
            }
        }
        step /= 1.247;
    }
    return 0;
}