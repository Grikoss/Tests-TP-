#include <stdbool.h>
#include "binaryTest.h"

int main(void)
{
    if (isGetPositiveIntegerBehavesIncorrectly())
    {
        return 1;
    }
}
