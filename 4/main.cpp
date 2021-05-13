#include "graph.h"
int main()
{
	//ALGraph G;
	//CreateUDG(G);
	//DFS(G, 0);
	//BFS(G,0);
	AMGragh G;
	//≤‚ ‘ ‰»Î
	//6 10 1 2 3 4 5 6 1 2 6 2 3 5 1 3 1 1 4 5 3 4 5 2 5 3 3 5 6 5 6 6 3 6 4 3 6 4 4 6 2
	CreateUDN(G);
	MiniSpanTree_Prim(G, '1');
	return 0;
}