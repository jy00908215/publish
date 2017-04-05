#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[10000], b[10000];
	gets(a);
	gets(b);
	char const *p = b;
	char *q = b;
	int number=0;
	if (strstr(b, a))
	{
		while (strstr(q, a))
		{
			q = strstr(q, a);
			printf("%d ", q-p);
			q++;
		}
	}
	else
	{
		printf("-1");
	}
	printf("\n");
	system("pause");
}