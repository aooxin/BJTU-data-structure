#include "list.h"

int InitList(SqList& L)
{
	L.elem = (Staff*)malloc(LIST_INIT_SIZE * sizeof(Staff));
	if (!L.elem)return 0;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}

int InsertList(SqList& L, int i, Staff e)
{
	Staff* q = &(L.elem[i - 1]),*p;
	for (p = &(L.elem[L.length - 1]); p >= q;--p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	if (L.length==L.listsize)
	{
		return 1;
	}
	return 1;
}

int DisplayAll(const SqList L)
{
	printf("name\t\t|ID \t\t|job          |\n");
	printf("----------------|---------------|-------------|\n");
	for (int i=0;i<L.length;i++)
	{
		DisplayStaff(L.elem[i]);
	}
	return 1;
}

void DisplayStaff(const Staff temp)
{
	printf("name:%9s\t|",temp.name);
	printf("ID:%10d\t|", temp.ID);
	printf("job:%9s|\n", temp.job);
	printf("----------------|---------------|-------------|\n");
}

Staff DeleteStaff(SqList& L, int i, Staff& e)
{
	Staff* q = &(L.elem[i - 1]),*p;
	for (p=L.elem+L.length-1;q<=p;++q)
	{
		*(q - 1) = *q;
	}
	L.length--;
	DisplayAll(L);
	return *q;
}

int ExtendList(SqList& L)
{
	Staff* enwbase;
	enwbase = (Staff*)realloc(L.elem, (L.listsize + LISTINCEMENT) * sizeof(Staff));
	if (!enwbase)return 0;
	L.elem = enwbase;
	L.listsize += LISTINCEMENT;
	return 1;
}
