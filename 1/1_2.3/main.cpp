#include "list.h"
int main()
{
	DuLinkList L;
	InitList(L);
	for (int i=1;i<10;i++)
	{
		ListInsertAtTail(L, i);
	}
	ListInsert(L, 5, 10);
	DisplayAll(L);
	Locate(L, 10);
	DisplayAll(L);
	Locate(L, 8);
	DisplayAll(L);
	Locate(L, 4);
	DisplayAll(L);
	Locate(L, 4);
	DisplayAll(L);
	return 0;
}