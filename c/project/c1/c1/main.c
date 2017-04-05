#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"
int main()
{
	int size, i=0;
	printf("输入总共有几个数字\n");
	scanf_s("%d", &size);
	int *p = (int *)malloc(size * sizeof(int));
	printf("请输入%d个数字\n",size);
	for (i = 0; size > i; i++)
	{
		scanf_s("%d", &p[i]);
	}
	printf("当前数组为：\n");
	printarray(p, size);
	numbersort(p, size);
	printf("排序后的数组为：\n");
	printarray(p, size);
	system("pause");
	free(p);
	return 0;
}