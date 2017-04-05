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
	printf("int数据类型最大数是：%lld\n",c);
	b++;
	while((c=c/10)!=0)
	{
		b++;
	}
	printf("int数据类型最大的位数是：%d\n",b);
	return 0;
}
