#include<stdio.h>
#include<stdlib.h>
void Rev(int a[], int begin, int end);
int main()
{
	int  FriAddress, fNumber, K, Number;
	scanf("%d %d %d", &FriAddress, &fNumber, &K);
	int Node[100001][2];
	int i;
	for (i = 0; fNumber > i; i++) {
		int Address, Data, Next;
		scanf("%d %d %d", &Address, &Data, &Next);
		Node[Address][0] = Data;
		Node[Address][1] = Next;
	}
	int AddList[100001];
	int m = FriAddress;
	int cnt = 0;
	do
	{
		AddList[cnt] = m;
		m = Node[m][1];
		cnt++;
	} while (m != -1);
	//for (cnt = 0; fNumber > cnt; cnt++) {
	//	AddList[cnt] = m;
	//	m = Node[m][1];
	//}
	Number = cnt;
	int tmp = 0;
	while (Number >= tmp + K)
	{
		int i = tmp;
		tmp += K;
		Rev(AddList, i, tmp - 1);
	}

	for (i = 0; Number > i; i++) {
		if (Number - 1 > i) {
			Node[AddList[i]][1] = AddList[i + 1];
			printf("%05d %d %05d\n", AddList[i], Node[AddList[i]][0], Node[AddList[i]][1]);
		}
		else {
			printf("%05d %d -1\n", AddList[i], Node[AddList[i]][0]);
		}



	}
	system("pause");
	return 0;
}
void Rev(int a[], int begin, int end) {
	int i;
	int tmp;
	for (; end >= begin; begin++, end--) {
		tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
	}
}