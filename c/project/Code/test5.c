#include <stdio.h>

int NextPrime(int x);
int main ()
{
	int Input;
	int Prime;
	int Remainder;
	scanf("%d", &Input);
	printf("%d=",Input);
	for (Prime=2;Input!=1;)	
	{
		if ( Input%Prime==0)
		{
			Input = Input / Prime ;
			if (Input !=1)
			printf("%dx",Prime);
			else
			printf("%d",Prime);
		}
		else
		{
			Prime=NextPrime(Prime)	;
		} 		
	}
	return 0;
	
}
int NextPrime(int x)
{
	int count=1;
	int i;
	int exit=0;


	for(x=x+1;count==1;x++)
	{
		int isPrime=1;
		for (i=2; i<x; i++)
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
			break;
		}
	 } 
	
	return x;
}

