#include <stdio.h>
#include "getComments.h"
#include "getCommentsTest.h"

int main()
{
	if (isGetCommentsBehaveIncorrect())
	{
		return 1;
	}
	return 0;
}