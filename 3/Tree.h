#pragma once
typedef struct CSNode
{
	int data;
	CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
//����
void createCsTree(CSTree&T);
//�����
int TreeDepth(CSTree T);
