#include "graph.h"
int LocateVex(ALGraph G, int v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

bool CreateUDG(ALGraph& G)
{
	cout << "���붥�����ͱ���:";
	cin >> G.vexnum >> G.arcnum;//���붥�����ͱ���
	cout << "�������ж��������:" << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;//��ʼ����ͷ����ָ����ΪNULL
	}
	for (int k = 0; k < G.arcnum; ++k)
	{
		int v1, v2;
		cout << "�����" << k + 1 << "�����������������㣺" << endl;
		cin >> v1 >> v2;//����һ������������������
		int i = LocateVex(G, v1), j = LocateVex(G, v2);
		ArcNode* p1, * p2;
		p1 = new ArcNode;
		p2 = new ArcNode;

		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return true;
}

bool visited[MAX_VERTEX_NUM];

int exist_path_len(ALGraph G, int i, int j, int k)
{
	ArcNode* p;
	p = new ArcNode;
	if (i == j && k == 0)
		return 1;//һ��Ϊ��
	else if (k > 0)
	{
		visited[i] = 1;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			int temp = p->adjvex;
			if (!visited[temp] && exist_path_len(G,temp, j, k - 1))
				return 1;
		}
		visited[i] = 0;
	}
	return 0;
}