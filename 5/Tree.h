#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int TElemType;
typedef struct BSTNode//���ṹ
{
	TElemType data;
	BSTNode* lchild, * rchild;
}BSTNode,*BSTree;
bool insertBSTree(BSTree& T, TElemType e);
void Inorder(BSTree T);