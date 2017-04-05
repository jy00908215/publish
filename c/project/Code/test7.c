#include <stdio.h>
int main (void)
{
	int a ,b;
	int count=0;
	int c[200]={0};
	scanf("%d/%d",&a,&b);
	printf("0.");	
	while (a!=0&&count<200)
	{
		c[count]=(a*10)/b;
		a=((a*10)%b);
		printf("%d",c[count]);
		count++; 
	}
	printf("\n");
	
	return 0;
}
