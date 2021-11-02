#pragma once
#include <stdio.h>

// Accepts a file with 'r' mode
// Returns array of string or NULL if something go wrong
// Don't forget to delete the array of string
char** getComments(FILE* file, int* outSize);

// Delete array of string
// If char** is pointing on NULL does nothing
// If the size is incorrect you will have memory leaks
void deleteComments(char** comments, const int size);