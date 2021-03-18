#pragma once
#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
typedef struct Lnode
{
	int data;
	int freq = 0;
	Lnode* prior;
	Lnode* next;
}DuLnode, * DuLinkList;
bool InitList(DuLinkList& L)
{
	L = (DuLinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	L->prior = NULL;
	return true;
}
int ListLength(DuLinkList L)
{
	Lnode* p = L->next;
	int j = 0;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}
Lnode* GetElem_DuL(DuLinkList L, int i)
{
	if (i == 0)
	{
		return L;
	}
	DuLinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j < i)
	{
		printf("%d GetElem Error!\n", i);
		return NULL;
	}
	return p;
}
//在表尾加入一个
bool ListInsertAtTail(DuLinkList& L, int e)
{
	DuLinkList p = L;
	DuLnode* s;
	while ((p->next) != NULL)
	{
		p = p->next;
	}
	s = (DuLinkList)malloc(sizeof(DuLnode));
	s->data = e;
	p->next = s;
	s->freq = 0;
	s->prior = p;
	s->next = NULL;
	return true;
}
//在指定位置前加入一个
bool ListInsert(DuLinkList& L, int i, int e)
{
	DuLinkList p = L;
	DuLnode* s;
	s = (DuLinkList)malloc(sizeof(DuLnode));
	p = GetElem_DuL(L, i);
	s->data = e;
	s->freq = 0;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return true;
}
bool DisplayAll(DuLinkList L)
{
	Lnode* s = L;
	while (s->next != NULL)
	{
		s = s->next;
		printf("%d ", s->data);
	}
	printf("\n");
	return true;
}
bool ListDelete(DuLinkList& L, int i)
{
	Lnode* p = L, * q;
	int j = 0;
	p = GetElem_DuL(L, i);
	if (!(p->next) || j > i - 1)return false;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return true;
}
bool ReSort(DuLinkList L, int k, Lnode* s)
{
	Lnode* p;
	while (k>1)
	{
		--k;
		p = s->prior;
		if ((s->freq) > (p->freq))
		{
			p->next = s->next;
			s->prior = p->prior;
			s->next->prior = p;
			p->prior->next = s;
			s->next = p;
			p->prior = s;
			continue;
		}
		else if ((s->freq) <= (p->freq))
		{
			
			break;
		}
		else return false;
	}
	return true;
}
int Locate(DuLinkList L, int x)
{
	Lnode* s = L;
	int i = 0;
	while (s->next != NULL)
	{
		++i;
		s = s->next;
		if (s->data == x)
		{
			++(s->freq);
			ReSort(L, i, s);
			return i;
		}
	}
	return 0;
}
#endif