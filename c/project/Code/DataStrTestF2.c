BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (BST->Data > X) {
			BST->Left = Insert(BST->Left, X);
		}
		else if (BST->Data < X) {
			BST->Right = Insert(BST->Right, X);
		}
	}
	return BST;
}
BinTree Delete(BinTree BST, ElementType X) {
	BinTree Tmp;
	if (!BST) printf("Not Found\n");
	else if (BST->Data > X) {
		BST->Left = Delete(BST->Left, X);
	}
	else if (BST->Data < X) {
		BST->Right = Delete(BST->Right, X);
	}
	else
	{
		if (BST->Left&&BST->Right) {
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Right, Tmp->Data);
		}
		else
		{
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}
Position Find(BinTree BST, ElementType X) {
	if (!BST) {
		return NULL;
	}
	if (BST->Data > X) {
		return Find(BST->Left, X);
	}
	else if (BST->Data < X) {
		return Find(BST->Right, X);
	}
	else
	{
		return BST;
	}
}
Position FindMin(BinTree BST) {
	if (!BST) return NULL;
	else if (!BST->Left) return BST;
	else return FindMin(BST->Left);
}
Position FindMax(BinTree BST) {
	if (!BST) return NULL;
	else if (!BST->Right) return BST;
	else return FindMax(BST->Right);
}

