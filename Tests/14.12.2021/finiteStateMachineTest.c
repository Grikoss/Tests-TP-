#include <stdbool.h>
#include "finiteStateMachine.h"
#include "finiteStateMachineTest.h"

bool isFunctionIsThisGroupNumberBehavesIncorrectly(void)
{
    bool result = !isThisGroupNumber("21.B10-mm", 0);
    result = result || !isThisGroupNumber("121.B10-mm", 1);
    result = result || isThisGroupNumber("21.BB10-dd", 0);
    result = result || !isThisGroupNumber("12.B01-mm", 0);
    result = result || isThisGroupNumber("21.B10.mm", 0);
    result = result || isThisGroupNumber("", 10);
    return result;
}