#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getComments.h"

#define SIZE_BUFFER 1000

char** getComments(FILE* file, int* outSize)
{
    if (file == NULL || outSize == NULL)
    {
        return NULL;
    }
    int size = 1;
    char** comments = calloc(size, sizeof(char*));
    if (comments == NULL)
    {
        return NULL;
    }
    int index = 0;
    while (!feof(file))
    {
        char buffer[SIZE_BUFFER] = { 0 };
        fscanf_s(file, "%*[^;]s");
        fscanf_s(file, "%[^\n]s%*c", buffer, SIZE_BUFFER);
        if (buffer[0] == ';' && strlen(buffer) > 1)
        {
            char* string = calloc(strlen(buffer) + 1, sizeof(char));
            if (string == NULL)
            {
                return NULL;
            }
            strcpy_s(string, strlen(buffer) + 1, buffer);
            while (index >= size)
            {
                size *= 2;
                char** moreComments = NULL;
                while (moreComments == NULL)
                {
                    moreComments = realloc(comments, size * sizeof(char**));
                }
                comments = moreComments;
            }
            comments[index] = string;
            ++index;
        }
    }
    *outSize = index;
    return comments;
}

void deleteComments(char** comments, const int size)
{
    if (comments == NULL)
    {
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        free(comments[i]);
    }
    free(comments);
}