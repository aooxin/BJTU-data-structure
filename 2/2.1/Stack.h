#pragma once
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}sqstack;

bool Initstack(sqstack& s);
bool push(sqstack& s, char x);
bool pop(sqstack& s, char& e);
bool empty(sqstack s);
char GotTop(sqstack& s);
bool Judge(datalist& L);