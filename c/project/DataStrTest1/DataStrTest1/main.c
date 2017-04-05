#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
	int number,i;
	scanf_s("%d\n", &number);//输入几几个数字
	int *a = (int*)malloc(number * sizeof(int));
	for (i = 0;  number>i; i++)
	{
		scanf_s("%d", &a[i]);//输入数组内容
	}

	return;
}