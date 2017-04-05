#include <stdio.h> 
int main (void)
{
	int count[101]={0};
	int a,b;
	int flag=0;
	int max=0;
	while(flag!=2){
		scanf("%d %d",&a,&b);
		count[a] += b;
		if (a>max) {
			max=a;
		} 
		if (a==0){
			flag++;
		}
	}
	int signForInteger = 1;
	int signForZero = 1;
	for (a=max;a>=0;a--){
		if (count[a]!=0) {
			signForZero = 0;
			if(count[a]<0)
				signForInteger = 1;
			if(signForInteger ==1)
				signForInteger = 0;
			else
				printf("+");
			if(a!=0 && count[a]!=1)
				printf("%d",count[a]);
			if(a==0)
				printf("%d\n",count[a]);
			else if (a ==1)
				printf("x");
			else
				printf("x%d",a);
			}
		else{
			if(a==0){
				if(signForZero == 0)
					printf("+");
				printf("%d\n",count[a]) ;
			}
		}
	}
	
}
