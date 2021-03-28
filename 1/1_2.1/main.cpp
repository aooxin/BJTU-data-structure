#include "list.h"
int main()
{
	LinkList L;
	CreateList(L);
	DisplayAll(L);
	int Kmin = 5, Kmax = 5;
	printf("删除%d和%d之间的\n", Kmin, Kmax);
	DeleteInMaxkAndMink(L, Kmin, Kmax);
	DisplayAll(L);
	return 0;
}
