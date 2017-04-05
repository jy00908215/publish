#include<stdio.h>
#include<stdlib.h>
int main()
{
	int NumberCount,TmpCount,one=0,two=0,three=0;
	scanf("%d\n",&NumberCount);
	if(NumberCount>0)
	{
		int * Array =(int*)malloc(NumberCount*sizeof(int));
		for (TmpCount=0;NumberCount>TmpCount;TmpCount++)
		{
			scanf("%d",&Array[TmpCount]);
		}
		int Begin=0,ThisMax=-1,ThisSum=0,MaxBegin=0,MaxEnd=NumberCount-1,n=0;
		for (Begin=0;NumberCount>Begin;Begin++)
		{
			ThisSum+=Array[Begin];
			n++;
			if (ThisMax<ThisSum)
			{
				ThisMax=ThisSum;
				MaxEnd=Begin;
				MaxBegin=Begin-n+1;
			}
			else if (0>ThisSum)
			{
				ThisSum=0 ;
				n=0;
			}	
		}	
		if (ThisMax<0)
		{
			ThisMax=0;
		}
		one=ThisMax;	 
		two=Array[MaxBegin];
		three=Array[MaxEnd];
		free(Array);
	}
	printf("%d %d %d",one,two,three);

	return 0; 
}
