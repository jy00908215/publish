#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"
int main()
{
	int size, i=0;
	printf("�����ܹ��м�������\n");
	scanf_s("%d", &size);
	int *p = (int *)malloc(size * sizeof(int));
	printf("������%d������\n",size);
	for (i = 0; size > i; i++)
	{
		scanf_s("%d", &p[i]);
	}
	printf("��ǰ����Ϊ��\n");
	printarray(p, size);
	numbersort(p, size);
	printf("����������Ϊ��\n");
	printarray(p, size);
	system("pause");
	free(p);
	return 0;
}