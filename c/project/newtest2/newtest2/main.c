#include<stdio.h>
#include<stdlib.h>
typedef struct _AVLNode * AVLTree;
struct _AVLNode
{
	int value;
	AVLTree left, right;
	int high;
};
int Max(int a, int b);
int GetHigh(AVLTree T);
AVLTree MakeAVLTree(int treeNodeNumber);
AVLTree NewAVLTree(int value);
AVLTree InsertAVLTree(AVLTree T, int value);
AVLTree SingleLeftRotation(AVLTree T);
AVLTree SingleRightRotation(AVLTree T);
AVLTree DoubleLeftRightRotation(AVLTree T);
AVLTree DoubleRightLeftRotation(AVLTree T);
void FreeAVLTree(AVLTree T);
void PrintAVLTreeRoot(AVLTree T);
int main() {
	int treeNodeNumber;
	AVLTree T;
	scanf_s("%d", &treeNodeNumber);
	T = MakeAVLTree(treeNodeNumber);
	PrintAVLTreeRoot(T);
	FreeAVLTree(T);
	system("pause");
	return 0;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
int GetHigh(AVLTree T) {
	if (T) return T->high;
	else return -1;

}
AVLTree MakeAVLTree(int treeNodeNumber) {
	AVLTree T;
	int i, value;
	scanf_s("%d", &value);
	T = NewAVLTree(value);
	for (i = 1; treeNodeNumber > i; i++) {
		scanf_s("%d", &value);
		T = InsertAVLTree(T, value);
	}
	return T;
}
AVLTree NewAVLTree(int value) {
	AVLTree T = (AVLTree)malloc(sizeof(struct _AVLNode));
	T->value = value;
	T->left = T->right = NULL;
	T->high = 0;
	return T;
}
AVLTree InsertAVLTree(AVLTree T, int value) {
	if (!T) T = NewAVLTree(value);
	else if (T->value > value) {
		T->left = InsertAVLTree(T->left, value);
		if (GetHigh(T->left) - GetHigh(T->right) == 2) {
			if (T->left->value > value)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	}
	else if (T->value < value) {
		T->right = InsertAVLTree(T->right, value);
		if (GetHigh(T->right) - GetHigh(T->left) == 2) {
			if (T->right->value < value)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	T->high = Max(GetHigh(T->left), GetHigh(T->right)) + 1;
	return T;
}
AVLTree SingleLeftRotation(AVLTree T) {
	AVLTree Tmp = T->left;
	T->left = Tmp->right;
	Tmp->right = T;
	T->high = Max(GetHigh(T->left), GetHigh(T->right)) + 1;
	Tmp->high = Max(GetHigh(Tmp->left), GetHigh(Tmp->right)) + 1;
	return Tmp;
}
AVLTree SingleRightRotation(AVLTree T) {
	AVLTree Tmp = T->right;
	T->right = Tmp->left;
	Tmp->left = T;
	T->high = Max(GetHigh(T->left), GetHigh(T->right)) + 1;
	Tmp->high = Max(GetHigh(Tmp->left), GetHigh(Tmp->right)) + 1;
	return Tmp;
}
AVLTree DoubleLeftRightRotation(AVLTree T) {
	T->left = SingleRightRotation(T->left);
	return SingleLeftRotation(T);
}
AVLTree DoubleRightLeftRotation(AVLTree T) {
	T->right = SingleLeftRotation(T->right);
	return SingleRightRotation(T);
}
void FreeAVLTree(AVLTree T) {
	if (T->left) FreeAVLTree(T->left);
	if (T->right) FreeAVLTree(T->right);
	free(T);
}
void PrintAVLTreeRoot(AVLTree T) {
	printf("%d", T->value);
}