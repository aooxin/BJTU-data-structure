#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int TElemType;
typedef struct BSTNode//结点结构
{
	TElemType data;
	BSTNode* lchild, * rchild;
}BSTNode,*BSTree;
bool insertBSTree(BSTree& T, TElemType e);
void Inorder(BSTree T);