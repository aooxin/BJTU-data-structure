#include "Tree.h"
#include "BiTree.h"
void createCsTree(CSTree& T)
{
	int ch;
	scanf_s("%d", &ch);
	if (ch == -1)T = NULL;
	else
	{
		if (!(T = (CSNode*)malloc(sizeof(CSNode))))
			exit(0);
		T->data = ch;
		createCsTree(T->firstchild);
		createCsTree(T->nextsibling);
	}
}

int TreeDepth(CSTree T)
{
	int h1, h2;
	if (!T)return 0;
	else
	{
		h1 = TreeDepth(T->firstchild);
		h2 = TreeDepth(T->nextsibling);
		return (h1+1)>h2?h1+1:h2;
	}
}
