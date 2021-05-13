#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>
#ifndef BASE
#define BASE
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define maxSize 10
typedef int Status;
#endif

#define TElemType char
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;



void TreePrintEdge(CSTree T) {
	CSNode* p;
	for (p = T->firstchild; p; p = p->nextsibling) {
		printf("(%c,%c)\n", T->data, p->data); //输出T的孩子
		TreePrintEdge(p); //输出p的孩子
	}
}

CSNode* tmpone[maxSize];


CSTree CreateCSTreeByLevelDegree(char* levelstr, int* num) {
	int cnt, i, parent;
	CSNode* p;
	

	//先创建结点
	for (i = 0; i < strlen(levelstr); ++i) 
	{
		p = (CSNode*)malloc(sizeof(CSNode)); 
		if (!p) 
			exit(OVERFLOW);
		p->data = levelstr[i];
		p->firstchild = p->nextsibling = NULL;
		tmpone[i] = p;
	}
	//连接
	parent = 0; //孩子的父节点
	cnt = 0; //找了几个孩子
	i = 1; //遍历结点，为他们找父节点
	while (i < 10) {
		if (num[parent] == 0 || cnt == num[parent]) {
			cnt = 0; //计数器归0
			parent++; //位移一位
			continue;
		}
		//这个父亲有孩子（i是parent的孩子）
		cnt++;
		if (cnt == 1) { //i 是parent的第一个孩子
			tmpone[parent]->firstchild = tmpone[i];
		}
		else { //不是第一个孩子
			tmpone[i - 1]->nextsibling = tmpone[i]; //它是前面的兄弟
		}

		i++;
	}
	return tmpone[0];
}


int main() {
	CSTree CST;
	char levelstr[] = {'R','A','B','C','D','E','F','G','H','I'}; //层次遍历的序列
	int num[] = { 3 ,2, 0, 1, 0, 0, 3, 0, 0, 0 };//每个结点的度
	int i, cnt;
	
	CST = CreateCSTreeByLevelDegree(levelstr, num);

	TreePrintEdge(CST);
	return 0;
}
