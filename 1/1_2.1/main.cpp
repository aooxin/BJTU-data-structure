#include "list.h"
int main()
{
	LinkList L;
	CreateList(L);
	DisplayAll(L);
	int Kmin = 5, Kmax = 5;
	printf("ɾ��%d��%d֮���\n", Kmin, Kmax);
	DeleteInMaxkAndMink(L, Kmin, Kmax);
	DisplayAll(L);
	return 0;
}
