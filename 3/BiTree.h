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
//��������ĵݹ��㷨
void Inorder(BiTree T);
//��������ĵݹ��㷨
void Preorder(BiTree T);
//��������ĵݹ��㷨
void Postorder(BiTree T);
BiTNode* GoFarLeft(BiTree T, stack<BiTree>& S);
//��������ķǵݹ��㷨
void Inorder_I(BiTree T);
//��α���������
void translevel(BiTree b);
//������������(����)
int Depth(BiTree T);

