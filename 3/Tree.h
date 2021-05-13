#pragma once
typedef struct CSNode
{
	int data;
	CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
//建树
void createCsTree(CSTree&T);
//求深度
int TreeDepth(CSTree T);
