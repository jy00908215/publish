#include<stdio.h>
#include<stdlib.h>
int main()
{
	int NumberCount,TmpCount;
	scanf("%d\n",&NumberCount);
	int * Array =(int*)malloc(NumberCount*sizeof(int));
	for (TmpCount=0;NumberCount>TmpCount;TmpCount++)
	{
		scanf("%d",&Array[TmpCount]);
	}
	int Begin=0,ThisMax=0,ThisSum=0;
	for (Begin=0;NumberCount>Begin;Begin++)
	{
		ThisSum+=Array[Begin];
		if (ThisMax<ThisSum)
		{
			ThisMax=ThisSum;
		}
		else if (0>ThisSum)
		{
			ThisSum=0 ;
		}	
	}
	
	printf("%d",ThisMax);
	free(Array);
	return 0; 
}




