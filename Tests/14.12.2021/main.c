#include <stdbool.h>
#include "binaryTest.h"
#include "finiteStateMachineTest.h"

int main(void)
{
    if (isGetPositiveIntegerBehavesIncorrectly())
    {
        return 1;
    }
    if (isFunctionIsThisGroupNumberBehavesIncorrectly())
    {
        return 2;
    }
    return 0;
}
