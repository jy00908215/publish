#include <stdio.h>  
#include <stdlib.h>

void SortNumber(int A[], int low, int high);
void MergeSort(int A[], int low, int mid, int high);


int main() {
	int A[100000];
	int i;
	int MaxSize;
	scanf("%d", &MaxSize);
	for (i = 0; MaxSize > i; i++) {
		scanf("%d", &A[i]);
	}
	SortNumber(A, 0, MaxSize - 1);
	for (i = 0; MaxSize > i; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}
void SortNumber(int A[], int low, int high) {
	int mid = 0;
	if (low < high) {
		mid = (low + high) / 2;
		SortNumber(A, low, mid);
		SortNumber(A, mid + 1, high);
		MergeSort(A, low, mid, high);
	}
	return;
}

void MergeSort(int A[], int low, int mid, int high) {
	int LeftLow = low;
	int leftHigh = mid;
	int RightLow = mid + 1;
	int RightHigh = high;
	int i, k;
	int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	for (k = 0; LeftLow <= leftHigh&&RightLow <= RightHigh; k++) {
		if (A[LeftLow] <= A[RightLow])
			tmp[k] = A[LeftLow++];
		else
			tmp[k] = A[RightLow++];
	}
	if (LeftLow <= leftHigh) {
		for (i = LeftLow; i <= leftHigh; i++) {
			tmp[k++] = A[i];
		}

	}
	if (RightLow <= RightHigh) {
		for (i = RightLow; i <= RightHigh; i++) {
			tmp[k++] = A[i];
		}
	}
	for (i = 0; i < high - low + 1; i++)
		A[low + i] = tmp[i];
	return;
}
