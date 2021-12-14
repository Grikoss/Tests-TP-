#include <stdbool.h>
#include <string.h>
#include "finiteStateMachine.h"

char getNextChar(const char* string, int* index)
{
    if (*index < 0 || *index > strlen(string))
    {
        return '\0';
    }
    char buffer = string[*index];
    ++* index;
    return buffer;
}

bool isThisGroupNumber(const char* string,int startIndex)
{
    int state = 0;
    while (true)
    {
        char currentChar = getNextChar(string, &startIndex);
        switch (state)
        {
        case 0:
            if (currentChar <= '9' && currentChar >= '0')
            {
                state = 1;
            }
            else
            {
                state = -1;
            }
            break;
        case 1:
            if (currentChar <= '9' && currentChar >= '0')
            {
                state = 2;
            }
            else
            {
                state = -1;
            }
            break;
        case 2:
            if (currentChar == '.')
            {
                state = 3;
            }
            else
            {
                state = -1;
            }
            break;
        case 3:
            if (currentChar == 'B' || currentChar == 'M' || currentChar == 'S')
            {
                state = 4;
            }
            else
            {
                state = -1;
            }
            break;
        case 4:
            if (currentChar <= '9' && currentChar >= '0')
            {
                state = 5;
            }
            else
            {
                state = -1;
            }
            break;
        case 5:
            if (currentChar <= '9' && currentChar >= '0')
            {
                state = 6;
            }
            else
            {
                state = -1;
            }
            break;
        case 6:
            if (currentChar == '-')
            {
                state = 7;
            }
            else
            {
                state = -1;
            }
            break;
        case 7:
            if (currentChar == 'm')
            {
                state = 8;
            }
            else
            {
                state = -1;
            }
            break;
        case 8:
            if (currentChar == 'm')
            {
                return true;
            }
            else
            {
                state = -1;
            }
            break;
        case -1:
        default:
            return false;
        }
    }
}