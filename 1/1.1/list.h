#pragma once
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#define LIST_INIT_SIZE 30
#define LISTINCEMENT 10
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
		return *this;
	}
};

typedef struct SqList
{
	Staff* elem;
	int length;
	int listsize;
};
//初始化
int InitList(SqList& L);
//插入
int InsertList(SqList& L, int i, Staff e);
//遍历展示
int DisplayAll(const SqList L);
//节点展示
void DisplayStaff(const Staff temp);
//删除
Staff DeleteStaff(SqList& L,int i,Staff& e);
//扩充链表
int ExtendList(SqList& L);