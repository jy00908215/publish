#include<stdint.h>
int Setup()
{
	initConsole();
	printf("�����ȣ�");
	int width;
	scanf("%d", &width);

	initWindow("test", 100, 100, 200, 200);
	beginPaint();
	line(20, 20, 100, 100);
	endPaint();

	return 0;
}