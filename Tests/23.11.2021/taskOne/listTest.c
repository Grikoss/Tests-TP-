#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTest.h"

bool isCreateListBehavesIncorrectly(List** list)
{
    *list = createList();
    return *list == NULL;
}

bool isCreatePositionBehavesIncorrectly(Position** position)
{
    *position = createPosition();
    return *position == NULL;
}

bool isMovePositionToHeadBehavesIncorrectly(List* list, Position* position)
{
    bool result = 1 != movePositionToHead(NULL, position);
    result = result || 1 != movePositionToHead(list, NULL);
    result = result || !isEnd(position) || 0 != movePositionToHead(list, position);
    return result;
}

bool isAddListElementBehavesIncorrectly(List* list, Position* position)
{
    bool result = addListElement(NULL, position, 0) != 1 || addListElement(list, NULL, 0) != 1;
    result = result || addListElement(list, position, 5) != 1;
    result = result || addListElementIntoHead(list, 1) != 0;
    result = result || addListElementIntoHead(list, 0) != 0;
    movePositionToHead(list, position);
    int value = 1;
    result = result || getValueFromListElement(position, &value) != 0 || value != 0;
    result = result || addListElement(list, position, 2) != 0;
    result = result || getValueFromListElement(position, &value) != 0 || value != 2;
    result = result || addListElementIntoHead(NULL, 10) != 1;
    return result;
}

bool isGetValueFromElementBehavesIncorrectly(List* list, Position* position)
{
    int value = 0;
    bool result = getValueFromListElement(position, &value) != 0 || value != 2;
    result = result || getValueFromListElement(NULL, &value) != 1;
    movePositionToHead(list, position);
    result = result || getValueFromListElement(position, &value) != 0 || value != 0;
    return result;
}

bool isMovePositionToNextOrPreviousBehavesIncorrectly(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = movePositionToNext(position) != 0;
    result = result || movePositionToNext(NULL) != 1;;
    return result;
}

bool isFunctionisEndBehavesIncorrectly(List* list, Position* position)
{
    bool result = isEnd(position);
    result = result || !isEnd(NULL);
    return result;
}

bool isFlipListBehavesIncorrectly(List** list, Position* position)
{
    bool result = flipList(NULL) != 1;
    result = result || flipList(list) != 0;
    movePositionToHead(*list, position);
    int value = 0;
    result = result || getValueFromListElement(position, &value) != 0 || value != 1;
    return result;
}

bool isRemoveListElementBehavesIncorrectly(List* list, Position* position)
{
    movePositionToHead(list, position);
    bool result = removeListElement(list, position) != 0;
    result = result || isEnd(position);
    result = removeListElement(list, position) != 0;
    result = result || isEnd(position);
    movePositionToNext(position);
    result = result || removeListElement(list, position) != 3;
    movePositionToHead(list, position);
    result = removeListElement(list, position) != 0;
    result = result || !isEnd(position);
    result = result || removeListElement(list, position) != 2;
    result = result || removeListElement(NULL, position) != 1 || removeListElement(list, NULL) != 1;
    return result;
}

bool isDeleteListBehavesIncorrectly(List* list)
{
    return deleteList(NULL) != 1 || deleteList(list) != 0;
}

bool isListBehavesIncorrectly()
{
    List* list = NULL;
    bool result = isCreateListBehavesIncorrectly(&list);
    Position* position = NULL;
    result = result || isCreatePositionBehavesIncorrectly(&position);
    result = result || isMovePositionToHeadBehavesIncorrectly(list, position);
    result = result || isAddListElementBehavesIncorrectly(list, position);
    result = result || isGetValueFromElementBehavesIncorrectly(list, position);
    result = result || isMovePositionToNextOrPreviousBehavesIncorrectly(list, position);
    result = result || isFunctionisEndBehavesIncorrectly(list, position);
    result = result || isFlipListBehavesIncorrectly(&list, position);
    result = result || isRemoveListElementBehavesIncorrectly(list, position);
    deletePosition(position);
    result = result || isDeleteListBehavesIncorrectly(list);
    return result;
}