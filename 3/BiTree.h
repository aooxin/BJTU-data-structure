#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#define MAXLEN 100
using namespace std;
typedef struct BiTNode {
	int data;
	BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree& T);
//中序遍历的递归算法
void Inorder(BiTree T);
//先序遍历的递归算法
void Preorder(BiTree T);
//后序遍历的递归算法
void Postorder(BiTree T);
BiTNode* GoFarLeft(BiTree T, stack<BiTree>& S);
//中序遍历的非递归算法
void Inorder_I(BiTree T);
//层次遍历二叉树
void translevel(BiTree b);
//求二叉树的深度(后序)
int Depth(BiTree T);

