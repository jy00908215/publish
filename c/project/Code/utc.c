#include <stdio.h>
int main()
{
	int bjt;
	int utc;
	int hour;
	int tensminute;
	int onesminute; 
	scanf("%d", &bjt);
	hour = bjt /100;
	hour -= 8;
	if (hour < 0)
	{
		hour += 24;
	}
	tensminute = bjt % 100 / 10;
	onesminute = bjt % 10;
	utc = hour * 100 + tensminute *10 + onesminute;
	printf("%d", utc);

	return 0;
}
