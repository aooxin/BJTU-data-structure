#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct Lnode
{
	int data;
	Lnode* next;
}Lnode, * LinkList;
bool InitList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	return true;
}
bool ListInsert(LinkList& L, int i, int e);
bool CreateList(LinkList& L)
{
	try
	{
		L = (LinkList)malloc(sizeof(Lnode));
		L->next = NULL;
		for (int i = 0; i < 10; i++)
		{
			Lnode* p;
			p = (LinkList)malloc(sizeof(Lnode));
			p->data = rand()%100;
			p->next = L->next;
			L->next = p;
		}
		ListInsert(L, 11, 100);
		return true;
	}
	catch (...)
	{
		printf("CreateList error");
		return false;
	}
}
bool ListInsert(LinkList& L, int i, int e)
{
	LinkList p = L;
	Lnode* s;
	int j = 0;
	while (j < i - 1)
	{
		p = p->next;
		++j;
	}
	s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}
bool DisplayAll(LinkList L)
{
	Lnode* p = L->next;
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}
bool ListDelete(LinkList& L, int i)
{
	Lnode* p = L, * q;
	int j = 0;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	q = (Lnode*)malloc(sizeof(Lnode));
	if (!(p->next) || j > i - 1)return false;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
int SelectMin(LinkList& L)
{
	LinkList p = L;
	p = p->next;
	int min = p->data, x = 0,y=1;
	while (p->next)
	{
		if (min>(p->data))
		{
			min = p->data;
			y += x;
			x = 0;
		}
		x++;
		p = p->next;
	}
	ListDelete(L, y);
	return min;
}

void SelectSort(LinkList& L)
{
	LinkList p, q = L->next;
	InitList(p);
	while (L->next)
	{
		ListInsert(p, 1, SelectMin(L));
	}
	DisplayAll(p);
}