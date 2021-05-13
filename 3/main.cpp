#include "BiTree.h"
#include "Tree.h"
int main()
{
	BiTree T;
	CreateBiTree(T);
	Inorder_I(T);
	//translevel(T);
	//printf("%d\n",Depth(T));
	/*CSTree ST;
	createCsTree(ST);
	cout<<TreeDepth(ST);*/
	return 0;
}