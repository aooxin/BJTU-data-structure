#pragma once
#define LIST_INIT_SIZE 30
#define LISTINCEMENT 10
#include <stdlib.h>
#include<stdio.h>
typedef struct datalist
{
	char* data;
	int length;
	int listsize;
}datalist;
bool Init_List(datalist& L);
bool Create_List(datalist& L);
bool Display_All(const datalist L);
bool Insert_List(datalist& L, int i, char e);


