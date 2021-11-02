#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "getComments.h"
#include "getCommentsTest.h"

bool isGetCommentsBehaveIncorrect()
{
    FILE* file = NULL;
    fopen_s(&file, "test.txt", "w");
    if (file == NULL)
    {
        return true;
    }
    fprintf_s(file, "fdfdsfsdfds;54321\n");
    fprintf_s(file, "fdfdsfsdfdsdsfegergerge;\n");
    fprintf_s(file, "      ;12345\n");
    fprintf_s(file, "fdfdsfsdfdsdsfegergerge\n");
    fprintf_s(file, "; \n");
    fclose(file);
    fopen_s(&file, "test.txt", "r");
    if (file == NULL)
    {
        return true;
    }
    int size = 0;
    char** comments = getComments(file, &size);
    fclose(file);
    remove("test.txt");
    bool result = strcmp(";54321", comments[0]) != 0;
    result = result || strcmp(";12345", comments[1]) != 0;
    result = result || strcmp("; ", comments[2]) != 0;
    result = result || getComments(NULL, NULL) != NULL;
    deleteComments(comments, size);
    return result;
}