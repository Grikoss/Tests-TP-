#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

typedef struct Line
{
    int* columns;
} Line;

typedef struct Matrix
{
    int sizeOfLine;
    int sizeOfColumn;
    Line** lines;
} Matrix;

ErrorCode createMatrix(Matrix** matrix)
{
    if (matrix == NULL)
    {
        return INVALID_INPUT;
    }
    int* arrayOne = calloc(2, sizeof(int));
    int* arrayTwo = calloc(2, sizeof(int));
    Line* lineOne = calloc(1, sizeof(Line));
    Line* lineTwo = calloc(1, sizeof(Line));
    Line** lines = calloc(2, sizeof(Line*));
    Matrix* newMatrix = calloc(1, sizeof(Matrix));
    if (arrayOne == NULL || arrayTwo == NULL || lineOne == NULL || lineTwo == NULL || lines == NULL || newMatrix == NULL)
    {
        free(arrayOne);
        free(arrayTwo);
        free(lineOne);
        free(lineTwo);
        free(lines);
        free(newMatrix);
        return MEMORY_ALLOCATION_ERROR;
    }
    lineOne->columns = arrayOne;
    lineTwo->columns = arrayTwo;
    lines[0] = lineOne;
    lines[1] = lineTwo;
    newMatrix->lines = lines;
    newMatrix->sizeOfColumn = 2;
    newMatrix->sizeOfLine = 2;
    *matrix = newMatrix;
    return SUCCESSFULLY;
}

ErrorCode resizeMatrix(Matrix** oldMatrix, const int newSizeOfLine, const int newSizeOfColumn)
{
    if (oldMatrix == NULL || *oldMatrix == NULL || (*oldMatrix)->sizeOfLine >= newSizeOfLine || (*oldMatrix)->sizeOfColumn >= newSizeOfColumn)
    {
        return INVALID_INPUT;
    }
    if (newSizeOfLine > (*oldMatrix)->sizeOfLine)
    {
        for (int i = 0; i < (*oldMatrix)->sizeOfColumn; ++i)
        {
            int* temp = realloc((*oldMatrix)->lines[i]->columns, newSizeOfLine);
            if (temp != NULL)
            {
                free((*oldMatrix)->lines[i]->columns);
                (*oldMatrix)->lines[i]->columns = temp;
                for (int j = (*oldMatrix)->sizeOfLine; j < newSizeOfLine; ++j)
                {
                    (*oldMatrix)->lines[i]->columns[j] = 0;
                }
            }
            else
            {
                return MEMORY_ALLOCATION_ERROR;
            }
        }
    }
    if (newSizeOfColumn > (*oldMatrix)->sizeOfColumn)
    {

    }
}

ErrorCode addIntegerToMatrix(Matrix* matrix, const int value, const int line, const int column)
{

}