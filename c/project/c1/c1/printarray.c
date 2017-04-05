#include <stdio.h>
#include "sort.h"
void printarray(int a[],int count)
{
	int i;
	for (i = 0; count > i; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}