#include <stdbool.h>
#include <stdlib.h>
#include "combSorting.h"
#include "combSortingTest.h"

// false is ok
bool compareArrayes(const int* arrayOne, const int* arrrayTwo, const int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (arrayOne[i] != arrrayTwo[i])
        {
            return true;
        }
    }
    return false;
}

bool combSortingTest()
{
    int arrayOne[] = { 10, 5, 4, 1, 3, 2, 9, 8, 6, 7 };
    combSort(arrayOne, 10);
    int controlArrayOne[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    bool result = compareArrayes(arrayOne, controlArrayOne, 10);
    int arrayTwo[] = { 500, 105, 8, 4, 1, 0, -3, -7, -10 };
    combSort(arrayTwo, 9);
    int controlArrayTwo[] = { -10, -7, -3, 0, 1, 4, 8, 105, 500 };
    result = result || compareArrayes(arrayTwo, controlArrayTwo, 9);
    result = result || (combSort(NULL, 10) != 1);
    int arrayThree[] = { 10, 5, 3, 2 };
    combSort(arrayThree, 0);
    int controlArrayThree[] = { 10, 5, 3, 2 };
    result = result || compareArrayes(arrayThree, controlArrayThree, 4);
    int arrayFour[] = { 10, 1 };
    combSort(arrayFour, 2);
    int controlArrayFour[] = { 1, 10 };
    return result || compareArrayes(arrayFour, controlArrayFour, 2);
}