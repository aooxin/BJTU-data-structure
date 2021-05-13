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
}VNode,AdjList[MAX_VERTEX_NUM];
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
void DFS(ALGraph G, int v);
void BFS(ALGraph &G);
void BFS(ALGraph& G, int v);

//下面是邻接矩阵的实现
#define MaxInt 32767//表示极大值
#define MVNum 100//表示极大顶点
typedef char VerTexType;
typedef int ArcType;
typedef struct 
{
	VerTexType vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGragh;
//辅助数组
struct 
{
	VerTexType adjvex;
	ArcType lowcost;
}closedge[MVNum];
void CreateUDN(AMGragh& G);
int LocateVex(AMGragh G, VerTexType v);
//Prim 生成最小生成树
void MiniSpanTree_Prim(AMGragh G, VerTexType u);
int Min();
