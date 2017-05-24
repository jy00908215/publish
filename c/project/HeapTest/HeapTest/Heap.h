#ifndef __Heap_H__
#define __Heap_H__
#include<stdbool.h>
#define ERROR -1
typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
	int *Array;
	int Size;
	int Capacity;
};
MaxHeap CreateHeap(int MaxSize);
bool InsertHeap(MaxHeap H, int Value);
bool HeapIsFull(MaxHeap H); 
bool HeapIsEmpty(MaxHeap H);
int DeleteMaxHeap(MaxHeap H);
void PercDownHeap(MaxHeap H, int p);
void BuildHeap(MaxHeap H);
#endif // !__Heap_H__