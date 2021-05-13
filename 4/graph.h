#pragma once
#define MAX_VERTEX_NUM 20
#include <iostream>
#include <queue>
using namespace std;
//����Ϣ
typedef struct InfoType
{
	int Wv;//Ȩֵ
};
//��
typedef struct ArcNode
{
	int adjvex;//�û�ָ��Ķ����λ��
	struct ArcNode* nextarc;//��һ������ָ��
	InfoType* info;//���满����Ϣ
};
//����
typedef struct VNode
{
	int data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ö���Ļ�
}VNode,AdjList[MAX_VERTEX_NUM];
//ͼ�Ľṹ����
typedef struct 
{
	AdjList vertices;//��ͷ�ڵ�����
	int vexnum, arcnum;//�������ͻ���
	int kind;//ͼ�������־
}ALGraph;
//ȷ��v��G�е����
int LocateVex(ALGraph G, int v);
bool CreateUDG(ALGraph& G);//�ڽӱ�
void DFS(ALGraph G, int v);
void BFS(ALGraph &G);
void BFS(ALGraph& G, int v);

//�������ڽӾ����ʵ��
#define MaxInt 32767//��ʾ����ֵ
#define MVNum 100//��ʾ���󶥵�
typedef char VerTexType;
typedef int ArcType;
typedef struct 
{
	VerTexType vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGragh;
//��������
struct 
{
	VerTexType adjvex;
	ArcType lowcost;
}closedge[MVNum];
void CreateUDN(AMGragh& G);
int LocateVex(AMGragh G, VerTexType v);
//Prim ������С������
void MiniSpanTree_Prim(AMGragh G, VerTexType u);
int Min();
