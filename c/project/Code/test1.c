#include<stdio.h> 

int main()
{
	int a;
	int hundreds,tens,ones,tmp;
	scanf("%d", &a);
	hundreds = a / 100;
	ones = a % 10;
	tens =(a - hundreds * 100 - ones)/10;
	tmp = ones;
	ones = hundreds;
	hundreds = tmp;
	printf("%d", hundreds * 100 + tens * 10 + ones);
}
