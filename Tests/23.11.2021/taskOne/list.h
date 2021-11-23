#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Position Position;

// Creates empty list
// Returns NULL if creation is failed
List* createList();

// Creates empty position
// Returns NULL if creation is failed
Position* createPosition();

// Gives value from element, doesn't remove it and move pointer
// Returns execution code:
// 0 - ok; 1 - position or position's pointer is NULL;
int getValueFromListElement(Position* position, int* outputValue);

// Adds element into list head
// Alaways moves position on added element
// Returns execution code:
// 0 - ok; 1 - list is NULL; 2 - failed to allocate memory;
int addListElementIntoHead(List* list, const int value);

// Adds element into list
// If list is empty use addListElementIntoHead
// Alaways moves position on added element
// Returns execution code:
// 0 - ok; 1 - list or position is NULL or position is pointing on NULL; 2 - failed to allocate memory;
int addListElement(List* list, Position* position, const int value);

// Removes element from list
// Moves position to next after removing
// Returns execution code:
// 0 - ok; 1 - list or position is NULL; 2 - list is empty; 3 - position is pointing on NULL when list isn't empty;
int removeListElement(List* list, Position* position);

// Deletes position, doesn't touch list
void deletePosition(Position* position);

// Delets list
// Returns execution code:
// 0 - ok; 1 - list is NULL;
int deleteList(List* list);

// Moves position to list head
// Returns execution code:
// 0 - ok; 1 - list or position is NULL;
int movePositionToHead(List* list, Position* position);

// Moves position to next position
// Returns execution code:
// 0 - ok; 1 - position is NULL or position is pointing on NULL;
int movePositionToNext(Position* position);

// Return true if position is pointing on NULL or position is NULL
bool isEnd(Position* position);

// Flips list
// Returns execution code:
// 0 - ok; 1 - list is NULL or empty; 2 - failed to allocate memory;
int flipList(List** list);