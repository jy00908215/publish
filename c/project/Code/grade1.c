#include <stdio.h>
int main()
{
	int score;
	int grade;
	printf("ÇëÄúÊäÈë³É¼¨£¨0-100£©:");
	scanf("%d", &score);
	grade = score / 10;
	if (grade >= 9)
	{
		printf("A\n");
	 } 
	else if (grade == 8)
	{
		printf("B\n");	
	}
	else if (grade == 7)
	{
		printf("C\n");
	}
	else if (grade == 6)
	{
		printf("D\n");
	}
	else
	{
		printf("F\n");
	}
	
	return 0;
}
