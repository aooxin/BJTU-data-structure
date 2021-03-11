#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Staff
{
	char name[20];
	int ID;
	char job[20];
	Staff& operator=(const Staff& temp)
	{
		strcpy_s(this->name, temp.name);
		this->ID = temp.ID;
		strcpy_s(this->job, temp.job);
		this->next = temp.next;
		return *this;
	}
	Staff* next;
}Lnode,*Linklist;
//初始化
int InitList(Linklist& L);
//插入
int ListInsert(Linklist L, int i, Lnode e);
//遍历输出
void DisplayAll(const Linklist L);
//输出一个节点
void DisplayLnode(const Lnode* L);
//通过ID查找
int FindByID(const Linklist L,int id);
//通过ID删除
int DeleteByID(Linklist& L, int id);