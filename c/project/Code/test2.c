#include <stdio.h>

int main()
{
	int UTC;//世界时间 
	int BJT;//北京时间 
	int Hours,Minutes;//小时，分钟 
	int Tmp;//寄存数 
	
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
