#include<stdio.h>
#include<stdlib.h>
int main() {
	int StackSize, NumberCnt, StackCnt;
	scanf("%d %d %d", &StackSize, &NumberCnt, &StackCnt);
	int i;
	for (i = 0; StackCnt > i; i++) {
		int Stack[1001] = { 0 };
		int j,OutNumber;
		int Number = 1, StackTop = 0, TooLong = 0;
		for (j = 0; NumberCnt > j; j++) {
			scanf("%d", &OutNumber);
			{
				if (Number != OutNumber&&StackSize >= StackTop) {
					while (Stack[StackTop] != OutNumber&&StackSize >= StackTop) {
						Stack[++StackTop] = Number;
						Number++;
					}
					if (StackSize < StackTop)
						TooLong = 1;
					Stack[StackTop] = 0;
					StackTop--;
				}
				else Number++;

			}
		}
		if (StackTop == 0&&TooLong==0) printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}