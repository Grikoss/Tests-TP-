#include <stdbool.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrixTest.h"

bool isCreateMatrixBehavesIncorrectly(void)
{
    bool result = createMatrix(NULL) != INVALID_INPUT;
    Matrix* matrix = NULL;
    result = result || createMatrix(&matrix) != SUCCESSFULLY;
    result = result || matrix == NULL;
    return result;
}

bool isMatrixBehavesIncorrecyly(void)
{
    bool result = isCreateMatrixBehavesIncorrectly();
    return result;
}