#include "graph.h"
int main()
{
	ALGraph G;
	CreateUDG(G);
	//6 10 1 2 3 4 5 6 1 2 1 4 2 3 3 1 3 6 4 3 4 6 5 4 6 1 6 5
	BfsJudge(G, 0, 2);
	return 0;
}