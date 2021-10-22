#include <stdio.h>
#include <stdlib.h>
#include "combSorting.h"
#include "combSortingTest.h"

int main()
{
	if (combSortingTest())
	{
		return 1;
	}
	printf("Enter length of array\n");
	int length = 0;
	scanf_s("%d", &length);
	while (length <= 0)
	{
		printf("Invalid length\n");
		while (scanf_s("%*c"));
		scanf_s("%d", &length);
	}
	int* array = calloc(length, sizeof(int));
	if (array == NULL)
	{
		return 2;
	}
	printf("Enter %d numbers:\n", length);
	for (int i = 0; i < length; ++i)
	{
		while (scanf_s("%d", &array[i]) != 1);
	}
	combSort(array, length);
	printf("Sort array: ");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}