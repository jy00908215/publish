#include <stdio.h>
int main(void)
{
	unsigned long int a=1,b=0;
	long long c=1;
	while (a>0)
	{
	a++;	
	c++;
	}
	c--;
	printf("int��������������ǣ�%lld\n",c);
	b++;
	while((c=c/10)!=0)
	{
		b++;
	}
	printf("int������������λ���ǣ�%d\n",b);
	return 0;
}
