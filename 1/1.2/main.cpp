#include "list.h"
int main()
{
	Linklist L;
	Lnode s1,s2;
	s1.ID = 10086;
	strcpy_s(s1.job, "teacher");
	strcpy_s(s1.name, "wangwu");
	s2.ID = 10000;
	strcpy_s(s2.name, "lisi");
	strcpy_s(s2.job, "designer");
	InitList(L);
	ListInsert(L, 1, s1);
	ListInsert(L, 1, s2);
	DisplayAll(L);
	DeleteByID(L, 10000);
	DisplayAll(L);
	return 0;
}