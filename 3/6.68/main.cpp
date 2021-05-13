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
		printf("(%c,%c)\n", T->data, p->data); //���T�ĺ���
		TreePrintEdge(p); //���p�ĺ���
	}
}

CSNode* tmpone[maxSize];


CSTree CreateCSTreeByLevelDegree(char* levelstr, int* num) {
	int cnt, i, parent;
	CSNode* p;
	

	//�ȴ������
	for (i = 0; i < strlen(levelstr); ++i) 
	{
		p = (CSNode*)malloc(sizeof(CSNode)); 
		if (!p) 
			exit(OVERFLOW);
		p->data = levelstr[i];
		p->firstchild = p->nextsibling = NULL;
		tmpone[i] = p;
	}
	//����
	parent = 0; //���ӵĸ��ڵ�
	cnt = 0; //���˼�������
	i = 1; //������㣬Ϊ�����Ҹ��ڵ�
	while (i < 10) {
		if (num[parent] == 0 || cnt == num[parent]) {
			cnt = 0; //��������0
			parent++; //λ��һλ
			continue;
		}
		//��������к��ӣ�i��parent�ĺ��ӣ�
		cnt++;
		if (cnt == 1) { //i ��parent�ĵ�һ������
			tmpone[parent]->firstchild = tmpone[i];
		}
		else { //���ǵ�һ������
			tmpone[i - 1]->nextsibling = tmpone[i]; //����ǰ����ֵ�
		}

		i++;
	}
	return tmpone[0];
}


int main() {
	CSTree CST;
	char levelstr[] = {'R','A','B','C','D','E','F','G','H','I'}; //��α���������
	int num[] = { 3 ,2, 0, 1, 0, 0, 3, 0, 0, 0 };//ÿ�����Ķ�
	int i, cnt;
	
	CST = CreateCSTreeByLevelDegree(levelstr, num);

	TreePrintEdge(CST);
	return 0;
}
