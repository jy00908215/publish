#include <stdio.h>
int main()
{
	
	int number;
	int single_count = 0;
	int	double_count = 0;
	int a;
	do
	{
		scanf("%d", &number );
		a = number;
		number %= 2;
		if(number ==1 )
		{
			++single_count;
		}
		else if(number == 0)
		{
			++double_count;
		}
	}
	while(a!=-1);
	printf("%d %d", single_count, double_count);
	return 0;
}
