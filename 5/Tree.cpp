#include "Tree.h"

bool insertBSTree(BSTree& T, TElemType e)
{
	if (!T)
	{
		BSTree S;
		S = new BSTNode;
		S->data = e;
		S->lchild = NULL;
		S->rchild = NULL;
		T = S;
	}
	else if(e<(T->data))
	{
		insertBSTree(T->lchild, e);
	}
	else if((T->data)<e)
	{
		insertBSTree(T->rchild, e);
	}
	return false;
}

void Inorder(BSTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		cout << T->data<<endl;
		Inorder(T->rchild);
	}
}
