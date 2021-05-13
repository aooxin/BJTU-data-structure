#pragma once
#define MAX_VERTEX_NUM 20
#include <iostream>
#include <queue>
using namespace std;
//弧信息
typedef struct InfoType
{
	int Wv;//权值
};
//弧
typedef struct ArcNode
{
	int adjvex;//该弧指向的顶点的位置
	struct ArcNode* nextarc;//下一条弧的指针
	InfoType* info;//储存弧的信息
};
//顶点
typedef struct VNode
{
	int data;//顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的弧
}VNode, AdjList[MAX_VERTEX_NUM];
//图的结构定义
typedef struct
{
	AdjList vertices;//表头节点向量
	int vexnum, arcnum;//顶点数和弧数
	int kind;//图的种类标志
}ALGraph;
//确定v在G中的序号
int LocateVex(ALGraph G, int v);
bool CreateUDG(ALGraph& G);//邻接表
void BFS(ALGraph& G, int v);
void BfsJudge(ALGraph& G, int v, int s);