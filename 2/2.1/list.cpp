#include "list.h"
bool Init_List(datalist& L)
{
	L.data = (char*)malloc(LIST_INIT_SIZE * sizeof(char));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return true;
}

bool Create_List(datalist& L)
{
	L.data[0] = '(';
	L.data[1] = '[';
	L.data[2] = '[';
	L.data[3] = ')';
	L.length = 4;
	return true;
}

bool Display_All(const datalist L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%c\t", L.data[i]);
	}
	printf("\n");
	return true;
}

bool Insert_List(datalist& L, int i, char e)
{
	char* q = &(L.data[i - 1]), * p;
	for (p = &(L.data[L.length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	if (L.length == L.listsize)
	{
		return true;
	}
	return true;
}