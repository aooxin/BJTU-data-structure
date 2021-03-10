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
//��ʼ��
int InitList(SqList& L);
//����
int InsertList(SqList& L, int i, Staff e);
//����չʾ
int DisplayAll(const SqList L);
//�ڵ�չʾ
void DisplayStaff(const Staff temp);
//ɾ��
Staff DeleteStaff(SqList& L,int i,Staff& e);
//��������
int ExtendList(SqList& L);