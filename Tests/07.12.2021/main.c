#include <stdlib.h>
#include <stdio.h>
#include "connectivity—omponent.h"

int main(void)
{
    int** matrix = (int**)calloc(3, sizeof(int*));
    for (int i = 0; i < 3; ++i)
    {
        matrix[i] = calloc(2, sizeof(int));
    }
    matrix[0][0] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix[2][1] = 1;
    int** newMatrix = getConnectivityComponent(matrix, 3, 2);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", newMatrix[i][j]);
        }
    }
}