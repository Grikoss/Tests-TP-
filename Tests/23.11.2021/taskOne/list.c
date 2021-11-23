#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* currentPosition;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

int getValueFromListElement(Position* position, int* outputValue)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    *outputValue = position->currentPosition->value;
    return 0;
}

int addListElementIntoHead(List* list, const int value)
{
    if (list == NULL)
    {
        return 1;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = list->head;
    list->head = element;
    return 0;
}

int addListElement(List* list, Position* position, const int value)
{
    if (list == NULL || position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL)
    {
        return 2;
    }
    element->value = value;
    element->next = position->currentPosition->next;
    position->currentPosition->next = element;
    position->currentPosition = element;
    return 0;
}


int removeListElement(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    if (list->head == NULL)
    {
        return 2;
    }
    if (position->currentPosition == NULL)
    {
        return 3;
    }
    ListElement* oldElement = position->currentPosition;
    if (list->head == position->currentPosition)
    {
        list->head = list->head->next;
        free(oldElement);
        position->currentPosition = list->head;
    }
    else
    {
        ListElement* previousElement = list->head;
        while (previousElement->next != position->currentPosition)
        {
            previousElement = previousElement->next;
        }
        previousElement->next = position->currentPosition->next;
        free(position->currentPosition);
        position->currentPosition = previousElement->next;
    }
    return 0;
}

void deletePosition(Position* position)
{
    free(position);
}

int deleteList(List* list)
{
    if (list == NULL)
    {
        return 1;
    }
    while (list->head != NULL)
    {
        ListElement* oldHead = list->head;
        list->head = list->head->next;
        free(oldHead);
    }
    free(list);
    return 0;
}

int movePositionToHead(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return 1;
    }
    position->currentPosition = list->head;
    return 0;
}

int movePositionToNext(Position* position)
{
    if (position == NULL || position->currentPosition == NULL)
    {
        return 1;
    }
    position->currentPosition = position->currentPosition->next;
    return 0;
}

bool isEnd(Position* position)
{
    return position == NULL || position->currentPosition == NULL;
}

int flipList(List** list)
{
    if (list == NULL || (*list)->head == NULL)
    {
        return 1;
    }
    ListElement* currentElemnt = (*list)->head;
    List* newList = createList();
    if (newList == NULL)
    {
        return 2;
    }
    while (currentElemnt != NULL)
    {
        addListElementIntoHead(newList, currentElemnt->value);
        currentElemnt = currentElemnt->next;
    }
    deleteList(*list);
    *list = newList;
    return 0;
}