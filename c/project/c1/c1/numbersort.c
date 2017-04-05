#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"
static void merge(int a[], int low, int high);
static void _merge(int a[],  int leftlow, int lefthigh, int rightlow, int righthigh );
void numbersort(int a[], int count)
{
	assert(a != NULL && count > 0);
	merge(a, 0, count - 1);
	return ;
}
void merge(int a[], int low, int high)
{
	if (low >= high)
	{
	}
	else
	{
		int mid = (low + high) / 2;
		merge(a, low, mid);
		merge(a, mid + 1, high);
		_merge(a, low, mid, mid + 1, high);
	}
	return;
}

void _merge(int a[], int leftlow, int lefthigh, int rightlow, int righthigh)
{
	int size = (lefthigh - leftlow + 1) + (righthigh - rightlow + 1);
	int *tmp = (int *)malloc(size * sizeof(int));
	int tmpll = leftlow, tmprl = rightlow, tmpsize = 0,i=0;
	while (tmpll <= lefthigh&&tmprl <= righthigh) 
	{
		if (a[tmpll]>=a[tmprl])
		{
			tmp[tmpsize++] = a[tmpll++];
		}
		else
		{
			tmp[tmpsize++] = a[tmprl++];
		}
	}
	while (tmpll <= lefthigh)
	{
		tmp[tmpsize++] = a[tmpll++];
	}
	while (tmprl<=righthigh)
	{
		tmp[tmpsize++] = a[tmprl++];
	}
	while (i <= tmpsize-1)
	{
		a[leftlow++] = tmp[i++];
	}
	free(tmp);
	return;
}