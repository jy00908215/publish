#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxSize 10000
struct Node
{
	int Data[MaxSize];
	int MaxCount;
};
typedef struct Node *PtNode;

PtNode CreateNote();
void PrintNote(PtNode A);
void Bubble_Sort(PtNode A);
void Swap(PtNode A,int a,int b);
void Insertion_Sort(PtNode A);
void Shell_Sort(PtNode A);
void Selection_Sort(PtNode A);
int ScanForMin(PtNode A, int Begin, int End);
void Heap_Sort(PtNode A);
void PercDown(PtNode A, int Top, int Size);
void Merge_Sort(PtNode A);
void Merge_pass(PtNode A, PtNode B, int length,int MaxCount);
void Merge(PtNode A, PtNode B, int low, int mid, int high);


int main() {
	PtNode A =CreateNote();
	PrintNote(A);
	Merge_Sort(A);
	PrintNote(A);
	return 0;
}

PtNode CreateNote() {
	PtNode A = (PtNode)malloc(sizeof(struct Node));
	A->MaxCount = -1;
	int i;
	do {
		printf("请输入0到10000之间的数字\n");
		scanf("%d", &A->MaxCount);
	} while (A->MaxCount < 1 || A->MaxCount>10000);
	srand((int)time(0));
	for (i = 0; A->MaxCount > i; i++) {
		A->Data[i] = (int)(rand() % 10000);
	}
	return A;
}
void PrintNote(PtNode A) {
	int i;
	for (i = 0; A->MaxCount > i; i++) {
		printf("%d ", A->Data[i]);
	}
	printf("\n");
}
void Swap(PtNode A, int a, int b) {
	int Tmp = A->Data[a];
	A->Data[a] = A->Data[b];
	A->Data[b] = Tmp;
}

void Bubble_Sort(PtNode A) {
	int p, i, flag;
	for (p = A->MaxCount - 1; p >= 0; p--) {
		flag = 0;
		for (i = 0; p > i; i++) {
			if (A->Data[i] > A->Data[i + 1]) {
				Swap(A,i,i+1);
				flag = 1;
			}
		}
		if (0 == flag) break;
	}
}

void Insertion_Sort(PtNode A) {
	int p, i, Tmp;
	for (p = 1; A->MaxCount > p; p++) {
		Tmp = A->Data[p];
		for (i = p; 0 < i&&Tmp < A->Data[i - 1]; i--)
			A->Data[i] = A->Data[i - 1];
		A->Data[i] = Tmp;
	}
}

void Shell_Sort(PtNode A) {
	int Si, D, p, i;
	int Tmp;
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };
	for (Si = 0; A->MaxCount <= Sedgewick[Si]; Si++);
	for (D = Sedgewick[Si]; 0 < D; D = Sedgewick[++Si]) {
		for (p = D; A->MaxCount > p; p++) {
			Tmp = A->Data[p];
			for (i = p; D <= i&&A->Data[i - D] > Tmp; i -= D) {
				A->Data[i] = A->Data[i - D];
			}
			A->Data[i] = Tmp;
		}
	}
}

void Selection_Sort(PtNode A) {
	int i, MinPosition;
	for (i = 0; A->MaxCount > i; i++) {
		MinPosition = ScanForMin(A, i, A->MaxCount - 1);
		Swap(A, i, MinPosition);
	}
}

int ScanForMin(PtNode A, int Begin, int End) {
	int i, Min=65535,Key=-1;
	for (i = Begin; End >= i; i++) {
		if (A->Data[i] < Min) {
			Key = i;
			Min = A->Data[i];
		}
	}
	return Key;
}

void Heap_Sort(PtNode A) {
	int i;
	for (i = A->MaxCount / 2; 0 <= i; i--)
		PercDown(A, i, A->MaxCount);
	for (i = A->MaxCount - 1; 0 < i; i--) {
		Swap(A, 0, i);
		PercDown(A, 0, i);
	}
}
void PercDown(PtNode A, int Top, int Size) {
	int Parent, Child;
	int X;
	X = A->Data[Top];
	for (Parent = Top; Size > (Parent * 2+1); Parent = Child) {
		Child = Parent * 2+1;
		if ((Child != Size-1) && (A->Data[Child] < A->Data[Child + 1]))
			Child++;
		if (A->Data[Child] <= X)
			break;
		else
			A->Data[Parent] = A->Data[Child];
	}
	A->Data[Parent] = X;
}

void Merge_Sort(PtNode A) {
	int length=1;
	PtNode Tmp;
	Tmp= (PtNode)malloc(sizeof(struct Node));
	if (Tmp != NULL) {
		while (A->MaxCount > length) {
			Merge_pass(A, Tmp, length,A->MaxCount);
			length *= 2;
			Merge_pass(Tmp, A, length,A->MaxCount);
			length *= 2;
		}
		free(Tmp);
	}
	else printf("空间不足,无法排序\n");
}
void Merge_pass(PtNode A, PtNode B, int length, int MaxCount) {
	int i, j;
	for (i = 0;MaxCount - 2 * length >= i; i += 2 * length)
		Merge(A, B, i, i + length, i + 2 * length - 1);
	if (MaxCount > i + length)
		Merge(A, B, i, i + length, MaxCount - 1);
	else
		for (j = i; MaxCount > j; j++) B->Data[j] = A->Data[j];
}
void Merge(PtNode A, PtNode B, int low, int mid, int high) {
	int LeftLow = low;
	int leftHigh = mid -1;
	int RightLow = mid;
	int RightHigh = high;
	int Tmp = low;
	while (LeftLow <= leftHigh&&RightLow <= RightHigh) {
		if (A->Data[LeftLow] <= A->Data[RightLow])
			B->Data[Tmp++] = A->Data[LeftLow++];
		else
			B->Data[Tmp++] = A->Data[RightLow++];
	}
	while (leftHigh >= LeftLow)
		B->Data[Tmp++] = A->Data[LeftLow++];
	while (RightHigh >= RightLow)
		B->Data[Tmp++] = A->Data[RightLow++];
}