#include "BiTree.h"

void CreateBiTree(BiTree& T)
{
	int ch;
	scanf_s("%d", &ch);
	if (ch == -1)T = NULL;
	else
	{
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
			exit(0);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void Inorder(BiTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		printf("%d ",T->data);
		Inorder(T->rchild);
	}
}

void Preorder(BiTree T)
{
	if (T)
	{
		printf("%d ", T->data);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
}

void Postorder(BiTree T)
{
	if (T)
	{
		Postorder(T->lchild);
		printf("%d ", T->data);
		Postorder(T->rchild);
	}
}

BiTNode* GoFarLeft(BiTree T, stack<BiTree>& S)
{
	if (!T)return NULL;
	while (T->lchild)
	{
		S.push(T);
		T = T->lchild;
	}
	return T;
}

void Inorder_I(BiTree T)
{
	stack<BiTree> S;
	BiTree t;
	t = GoFarLeft(T, S);
	while (t)
	{
		printf("%d ", t->data);
		if (t->rchild)
		{
			t = GoFarLeft(t->rchild, S);
		}
		else if (!S.empty())//栈不空时退栈
		{
			t = S.top();
			S.pop();
		}
		else
		{
			t = NULL;
		}
	}
}

void translevel(BiTree b)
{
	struct node
	{
		BiTree vec[MAXLEN];
		int f, r;
	}q;
	q.f = 0;
	q.r = 0;
	if (b != NULL)printf("%d ", b->data);
	q.vec[q.r] = b;
	q.r = q.r + 1;//队头ru队列
	while (q.f<q.r)
	{
		b = q.vec[q.f];
		q.f = q.f + 1;
		if (b->lchild!=NULL)//左孩入队
		{
			printf("%d ", b->lchild->data);
			q.vec[q.r] = b->lchild;
			q.r = q.r + 1;
		}
		if (b->rchild!=NULL)//右孩入队
		{
			printf("%d ", b->rchild->data);
			q.vec[q.r] = b->rchild;
			q.r = q.r + 1;
		}
	}
}

int Depth(BiTree T)
{
	int depthval,depthLeft,depthRight;
	if (!T)depthval = 0;
	else
	{
		depthLeft = Depth(T->lchild);
		depthRight = Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}


