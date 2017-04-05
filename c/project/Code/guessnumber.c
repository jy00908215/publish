#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main (int argc,char *argv[])
{
	srand((unsigned)time(NULL));
	int count = 0,number,max=100,min=0,guess;
	number=rand()%99+1;

	do{
		printf("输入一个你要猜测的数字(范围%d,%d之间)\n",min,max);
		scanf("%d",&guess);
			if(number>guess&&min<guess)
			{
				min=guess; 
				printf("你猜的数字小了\n"); 
			}
			else if(number<guess&&max>guess)
			{
				max=guess;
				printf("你猜的数字大了\n");
			 } 
			else
			{
				printf("您输入的数字无效\n");	
			}
		count++;
	} 
	while(guess!=number&&10>count);
	if (guess==number)
	{
		printf("恭喜你猜对了，答案为%d\n，你猜测了%d次",number,count);	
	}
	else printf("对不起你猜了太多次了");
	return 0;
}
