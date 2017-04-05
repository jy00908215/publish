#include <stdio.h> 

int main()
{
	int sum = 0;
	int n;
	int m;
	int count = 0;
	int x = 1;


	scanf("%d %d", &n, &m);
	while( count<=m)
	{
		int i;
		int isPrime=1;
		for ( i=2; i<x; i++)
		{
			if(x%i == 0)
			{
				isPrime = 0;
				break;
			 } 
		}
		if(isPrime ==1)
		{
			count++;
			if( count>n)
			{
				sum += x;
			 } 
		}
		x++;
	}
	printf("%d", sum);
	return 0;
}
