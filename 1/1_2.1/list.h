#pragma once
#ifndef LIST_H
#define LIST_H
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
bool ListInsert(LinkList& L, int i, int e)
{
	LinkList p = L;
	Lnode* s;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1)return 0;
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
	Lnode* p = L,*q;
	int j = 0;
	while (p->next!=NULL&&j<i-1)
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
bool DeleteInMaxkAndMink(LinkList& L, int Mink, int Maxk)
{
	Lnode* p = L->next;
	Lnode* prior_p = L;
	int j = 0;
	bool IsMinFound = false, IsMaxFound = false;
	while (p != NULL)
	{
		if (p->data >= Mink)
		{
			IsMinFound = true;
			break;
		}
		p = p->next;
		prior_p = prior_p->next;
	}
	if (IsMinFound == true)
	{
		p = prior_p;
		while (p != NULL)
		{
			if (Maxk <= p->data)
			{
				IsMaxFound = true;
				break;
			}
			j++;
			p = p->next;
		}
	}
	
	for (int i = 0; i < j; i++)
	{
		Lnode* temp = prior_p->next;
		prior_p->next = temp->next;
		free(temp);
	}
	return true;
}
#endif