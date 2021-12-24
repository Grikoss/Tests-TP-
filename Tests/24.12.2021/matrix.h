#pragma once

typedef struct Matrix Matrix;

typedef enum ErrorCode
{
    SUCCESSFULLY,
    INVALID_INPUT,
    MEMORY_ALLOCATION_ERROR
} ErrorCode;

// Creates matrix
// Requires matrix address
// Returns error code
ErrorCode createMatrix(Matrix** matrix);

// Addes integer to Matrix on line and column
// Rewrites old value
// If line or column is overlimited, does nothing
// Returns error code
ErrorCode addIntegerToMatrix(Matrix* matrix, const int value, const int line, const int column);

// Deltes matrix
// Requires matrix address
// Returns error code
ErrorCode deleteMatrix(Matrix** matrix);

// Gives number of matrix elements
// Returns error code
ErrorCode getNumberOfMatrixElements(Matrix* matrix, int* value);

// Puts in integer array elements of matrix in the order of traversal in the form of a converging spiral
// Returns execution code
ErrorCode spiralOutput(Matrix* matrix, int* buffer, const int size);