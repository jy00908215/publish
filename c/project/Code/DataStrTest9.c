#include<stdio.h>
#include<stdlib.h>
typedef struct _TreeNode *Tree;
struct _TreeNode
{
	int value;
	Tree Left, Right;
	int flag;
};
Tree MakeTree(int treeNodeNumber);
Tree NewNode(int value);
Tree Insert(Tree T, int value);
int Judge(Tree T, int treeNodeNumber);
int Check(Tree T, int value);
void ResetT(Tree T);
void FreeTree(Tree T);
int main() {
	int treeNodeNumber, treeNumber, i;
	Tree T;
	scanf("%d", &treeNodeNumber);
	while (treeNodeNumber)
	{
		scanf("%d", &treeNumber);
		T = MakeTree(treeNodeNumber);
		for (i = 0; treeNumber > i; i++) {
			if (Judge(T, treeNodeNumber))printf("Yes\n");
			else printf("No\n");
			ResetT(T);
		}
		FreeTree(T);
		scanf("%d", &treeNodeNumber);
	}
	system("pause");
	return 0;
}
Tree MakeTree(int treeNodeNumber) {
	Tree T;
	int i, value;
	scanf("%d", &value);
	T = NewNode(value);
	for (i = 1; treeNodeNumber > i; i++) {
		scanf("%d", &value);
		T = Insert(T, value);
	}
	return T;
}
Tree NewNode(int value) {
	Tree T = (Tree)malloc(sizeof(struct _TreeNode));
	T->value = value;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}
Tree Insert(Tree T, int value) {
	if (!T) T = NewNode(value);
	else {
		if (T->value < value)
			T->Right = Insert(T->Right, value);
		else
			T->Left = Insert(T->Left, value);
	}
	return T;
}
int Judge(Tree T, int treeNodeNumber) {
	int value, i, flag = 0;
	scanf("%d", &value);
	if (T->value != value) flag = 1;
	else T->flag = 1;
	for (i = 1; treeNodeNumber > i; i++) {
		scanf("%d", &value);
		if (!Check(T, value)) flag = 1;
	}
	if (flag) return 0;
	else return 1;
}
int Check(Tree T, int value) {
	if (T->flag) {
		if (T->value > value) return Check(T->Left, value);
		else if (T->value < value)return Check(T->Right, value);
		else return 0;
	}
	else {
		if (T->value == value) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}
void ResetT(Tree T)
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}
