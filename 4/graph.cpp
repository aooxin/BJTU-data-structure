#include "graph.h"
#include "Lqueue.h"
int LocateVex(ALGraph G, int v)
{
	for (int i=0;i<G.vexnum;i++)
	{
		if (G.vertices[i].data==v)
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
	for (int i=0;i<G.vexnum;++i)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;//��ʼ����ͷ����ָ����ΪNULL
	}
	for (int k=0;k<G.arcnum;++k)
	{
		int v1, v2;
		cout << "�����" << k+1 << "�����������������㣺" << endl;
		cin >> v1 >> v2;//����һ������������������
		int i = LocateVex(G, v1), j = LocateVex(G, v2);
		ArcNode* p1,*p2;
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
void DFS(ALGraph G, int v)
{
	cout << G.vertices[v].data << endl;
	visited[v] = true;
	ArcNode* p;
	p = new ArcNode;
	p = G.vertices[v].firstarc;
	while (p!=NULL)
	{
		int w;
		w = p->adjvex;
		if (!visited[w])DFS(G, w);//-_-
		p = p->nextarc;
	}
}

void BFS(ALGraph &G)
{
	Queue* Q = (LQueue)malloc(sizeof(Queue));
	for (int i = 0; i < G.vexnum; i++) {
		visited[i] = false;
	}
	InitQueue(Q);  //��ʼ������ 
	for (int i = 0; i < G.vexnum; i++) {
		visited[i] = true;
		cout << G.vertices[i].data<<endl;
		EnQueue(Q, i);

		while (!QueueisEmpty(Q)) {
			DeQueue(Q, &i);  //���ﲻ�ϵ��޸�i��ֵ���� 
			ArcNode* e = G.vertices[i].firstarc;  //i ������ڽ�����ĵ�һ�����
			while (e) {//e ����ʱ����e�������ڽӵ�������,Ҳ���Ǳ���i�������ڽӵ� 
				if (!visited[e->adjvex]) { // adjvex ��e����ʾ�Ľ���±� 
					visited[e->adjvex] = true;
					printf("\t%c", G.vertices[e->adjvex].data);
					EnQueue(Q, e->adjvex); //���ý����� 
				}
				e = e->nextarc; //����i����һ���ڽӵ� 
			}
		}
	}
}

void BFS(ALGraph& G, int v)
{
	int w;
	ArcNode* p;
	int visited[MAX_VERTEX_NUM] = { 0 };
	Queue* Q = (LQueue)malloc(sizeof(Queue));
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueisEmpty(Q))
	{
		w = DeQueue(Q);
		if (visited[w]==1)continue;
		visited[w] = 1;
		cout << G.vertices[w].data << endl;
		p = G.vertices[w].firstarc;
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				EnQueue(Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}

void CreateUDN(AMGragh& G)
{
	cout << "���붥�����ͱ���:";
	cin >> G.vexnum >> G.arcnum;//���붥�����ͱ���
	cout << "�������ж��������:" << endl;
	for (int i=0;i<G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	//��ʼ���ڽӾ���
	for (int i=0;i<G.vexnum;i++)
	{
		for (int j=0;j<G.vexnum;j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	//�����ڽӾ���
	for (int k=0;k<G.arcnum;k++)
	{
		char v1, v2;
		int w;
		cout << "�����" << k+1 << "�����������������㼰Ȩֵ��" << endl;
		cin >> v1 >> v2>> w;//����һ������������������
		int i = LocateVex(G, v1),j=LocateVex(G,v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
}

int LocateVex(AMGragh G, VerTexType v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i]== v)
		{
			return i;
		}
	}
	return -1;
}

void MiniSpanTree_Prim(AMGragh G, VerTexType u)
{
	int k = LocateVex(G, u);
	for (int j=0;j<G.vexnum;j++)
		if (j!=k)closedge[j] = { u,G.arcs[k][j] };
	closedge[k].lowcost = 0;
	for (int i=1;i<G.vexnum;++i)
	{ 
		k = Min();
		VerTexType u0 = closedge[k].adjvex;
		VerTexType v0 = G.vexs[k];
		cout <<"("<< u0 <<","<< v0 <<")"<< endl;
		closedge[k].lowcost = 0;//��k�����㲢��U��
		for (int j=0;j<G.vexnum;j++)
		{
			if (G.arcs[k][j]<closedge[j].lowcost)//�¶��㲢��U����ѡ����С��
			{
				closedge[j] = { G.vexs[k],G.arcs[k][j] };
			}
		}
	}

}

int Min()
{
	int min = MaxInt;
	int index = -1;
	for (int i = 0; i < MVNum; i++)
	{
		if (closedge[i].lowcost < min && closedge[i].lowcost != 0)
		{
			min = closedge[i].lowcost;
			index = i;
		}
	}
	return index;
}
