#include <stdbool.h>
#include <stdlib.h>
#include "connectivity—omponent.h"

bool isThereNode(const int key, const int* array, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            return true;
        }
    }
    return false;
}

int** getConnectivityComponent(const int** matrix, const int height, const int width)
{
    int** newMatrix = (int**)calloc(height, sizeof(int*));
    for (int i = 0; i < height; ++i)
    {
        newMatrix[i] = calloc(height, sizeof(int));
    }
    for (int i = 0; i < width; ++i)
    {
        int firstNode = 0;
        int secondNode = 0;
        for (int j = 0; j < height; ++j)
        {
            if (matrix[j][i] == 1)
            {
                firstNode = secondNode;
                secondNode = j;
            }
        }
        newMatrix[firstNode, secondNode] = 1;
        newMatrix[secondNode, firstNode] = 1;
    }
    return newMatrix;
    /*int* passedNodes = calloc(height, sizeof(int));
    if (passedNodes == NULL)
    {
        return NULL;
    }
    int passedNodesIndex = 0;
    int** connectivityComponent = calloc(height, sizeof(int*));
    if (connectivityComponent == NULL)
    {
        free(passedNodes);
        return NULL;
    }
    for (int i = 0; i < height; ++i)
    {
        if (!isThereNode(i + 1, passedNodes, height))
        {
            int* component = calloc(height, sizeof(int));
            component[0] = i + 1;
            int componentIndex = 1;
            passedNodes[passedNodesIndex] = i + 1;
            ++passedNodesIndex;
                while (true)
                {

                }
        }
    }*/
}