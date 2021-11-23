#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "listTest.h"

void printList(List* list, Position* position)
{
    movePositionToHead(list, position);
    while (!isEnd(position))
    {
        int value = 0;
        getValueFromListElement(position, &value);
        printf_s("%d ", value);
        movePositionToNext(position);
    }
    printf_s("\n");
}

int main(void)
{
    if (isListBehavesIncorrectly())
    {
        return 1;
    }
    FILE* file = NULL;
    fopen_s(&file, "input.txt", "r");
    if (file == NULL)
    {
        return 2;
    }
    Position* position = createPosition();
    List* list = createList();
    addListElementIntoHead(list, 0);
    movePositionToHead(list, position);
    int value = 0;
    while (fscanf_s(file, "%d", &value) == 1)
    {
        addListElement(list, position, value);
    }
    movePositionToHead(list, position);
    removeListElement(list, position);
    printf_s("Old list:\n");
    printList(list, position);
    flipList(&list);
    printf_s("Fliped list:\n");
    printList(list, position);
    deleteList(list);
    deletePosition(position);
    return 0;
}