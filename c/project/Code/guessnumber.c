#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main (int argc,char *argv[])
{
	srand((unsigned)time(NULL));
	int count = 0,number,max=100,min=0,guess;
	number=rand()%99+1;

	do{
		printf("����һ����Ҫ�²������(��Χ%d,%d֮��)\n",min,max);
		scanf("%d",&guess);
			if(number>guess&&min<guess)
			{
				min=guess; 
				printf("��µ�����С��\n"); 
			}
			else if(number<guess&&max>guess)
			{
				max=guess;
				printf("��µ����ִ���\n");
			 } 
			else
			{
				printf("�������������Ч\n");	
			}
		count++;
	} 
	while(guess!=number&&10>count);
	if (guess==number)
	{
		printf("��ϲ��¶��ˣ���Ϊ%d\n����²���%d��",number,count);	
	}
	else printf("�Բ��������̫�����");
	return 0;
}
