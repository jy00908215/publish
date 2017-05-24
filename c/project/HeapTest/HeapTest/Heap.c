#include<stdio.h>
#include<stdlib.h>
#include"Heap.h"
#include<stdbool.h>
MaxHeap CreateHeap(int MaxSize) {
	MaxHeap H = malloc(sizeof(struct HeapStruct));
	H->Array = malloc((MaxSize + 1) * sizeof(int));
	H->Size = 0;
	H->Capacity = MaxSize;
	return H;
}

bool HeapIsFull(MaxHeap H) {
	return (H->Size == H->Capacity);
}

bool HeapIsEmpty(MaxHeap H) {
	return (H->Size == 0);
}

bool InsertHeap(MaxHeap H, int Value) {
	int i;
	if (HeapIsFull(H)) {
		printf("最大堆已满\n");
		return false;
	}
	i = ++H->Size;
	for (; H->Array[i / 2] < Value && 1>i; i /= 2)
		H->Array[i] = H->Array[1 / 2];
	H->Array[i] = Value;
	return true;
}

int DeleteMaxHeap(MaxHeap H) {
	int Parent, Child;
	int MaxItem, temp;
	if (HeapIsEmpty(H)) {
		printf("最大堆已为空");
		return ERROR;
	}
	MaxItem = H->Array[1];
	temp = H->Array[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Array[Child] < H->Array[Child + 1]))
			Child++;
		if (temp >= H->Array[Child])
			break;
		else
			H->Array[Parent] = H->Array[Child];
	}
	H->Array[Parent] = temp;
	return MaxItem;
}

void PercDownHeap(MaxHeap H, int p) {
	int Parent, Child;
	int X;
	X = H->Array[p];
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Array[Child] < H->Array[Child + 1]))
			Child++;
		if (X >= H->Array[Child])
			break;
		else
			H->Array[Parent] = H->Array[Child];
	}
	H->Array[Parent] = X;
}
void BuildHeap(MaxHeap H) {
	int i;
	for (i = H->Size / 2; i > 0; i--)
		PercDownHeap(H, i);
}
