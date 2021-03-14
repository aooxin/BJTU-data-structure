#include "list.h"
int main()
{
	LinkList L;
	InitList(L);
	for (int i=0;i<10;i++)
	{
		ListInsert(L, i, i);
	}
	DisplayAll(L);
	DeleteInMaxkAndMink(L, 2, 2);
	DisplayAll(L);
	return 0;
}
