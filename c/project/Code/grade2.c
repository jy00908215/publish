#include <stdio.h>
int main()
{
	int score;
	printf("«Îƒ˙ ‰»Î≥…º®£®0-100£©:");
	scanf("%d", &score);
	switch (score /= 10)
	{
		case 10:
		case 9:
		{
			printf("A\n");
			break;
		}
		case 8:
		{
			printf("B\n");
			break;
		}	
		case 7:
		{
			printf("C\n");
			break;
		}
		case 6:
		{
			printf("D\n");
			break;
		}
		default:
		{s
			printf("F\n");
			break;
		}
	}
	return 0;
}
