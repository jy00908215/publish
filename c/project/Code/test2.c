#include <stdio.h>

int main()
{
	int UTC;//����ʱ�� 
	int BJT;//����ʱ�� 
	int Hours,Minutes;//Сʱ������ 
	int Tmp;//�Ĵ��� 
	
	scanf("%d",&UTC);
	Tmp=UTC/100;
	Minutes=(UTC-Tmp*100);
	Hours= UTC/100-8;
	if(Hours<0){
		Hours=Hours+24
	} 
	BJT=Hours*100+Minutes;
	printf("%d",BJT);
}
