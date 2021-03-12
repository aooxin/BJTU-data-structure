#include "list.h"
int main()
{
	Linklist L;
	Lnode s1,s2,s3;
	s1.ID = 10086;
	strcpy_s(s1.job, "teacher");
	strcpy_s(s1.name, "wangwu");
	s2.ID = 10000;
	strcpy_s(s2.name, "lisi");
	strcpy_s(s2.job, "designer");
	s3.ID = 10101;
	strcpy_s(s3.job, "dancer");
	strcpy_s(s3.name, "zhangsan");
	InitList(L);
	ListInsert(L, 1, s1);
	ListInsert(L, 1, s2);
	ListInsert(L, 2, s3);
	DisplayAll(L);
	printf("%d\n", FindByID(L, 10101));
	DeleteByID(L, 10086);
	DisplayAll(L);
	return 0;
}