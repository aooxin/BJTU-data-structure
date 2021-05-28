#include "graph.h"
int main()
{
	ALGraph G;
	CreateUDG(G);
	//5 6 1 2 3 4 5 1 2 2 3 2 5 3 5 3 4 1 4
	cout << exist_path_len(G, 0, 4, 2);
	return 0;
}