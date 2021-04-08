#include "Stack.h"

bool Initstack(sqstack& s)
{
	s.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!s.base) { printf("1 error"); return false; }
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return true;
}

bool push(sqstack& s, char x)
{
	if (s.top - s.base >= s.stacksize)
	{
		printf("extend");
		s.base = (char*)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(char));
		if (!s.base) { printf("2 error"); return false; }
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = x;
	//printf("PUSH%c", x);
	return true;
}

bool pop(sqstack& s, char& e)
{
	if (s.top == s.base)
	{
		printf("3 error");
		return false;
	}
	e = *--s.top;
	return true;
}

bool empty(sqstack s)
{
	if (s.top == s.base)
	{
		return true;
	}
	return false;
}

char GotTop(sqstack& s)
{
	char* x = s.top - 1;
	return *x;
}

bool Judge(datalist& L)
{
	sqstack s;
	Initstack(s);
	bool state = true,Isempty=empty(s);
	int i = 0;
	char e;
	while (i < L.length && state)
	{
		switch (L.data[i])
		{
		case '(': {push(s, L.data[i]); i++; break; }
		case ')':
		{if (!empty(s) && GotTop(s) == '(')
		{
			pop(s, e);
			i++;
			break;
		}
		else
		{
			state = false; 
			break;
		}
		}
		case '[': {push(s, L.data[i]); i++; break; }
		case ']': 
		{if (!empty(s) && GotTop(s) == '[')
		{
			pop(s, e);
			i++;
			break;
		}
				else
		{
			state = false;
			break;
		}
		}
		case '{': {push(s, L.data[i]); i++; break; }
		case '}':
		{if (!empty(s) && GotTop(s) == '{')
		{
			pop(s, e);
			i++;
			break;
		}
		else
		{
			state = false;
			break;
		}
		}
		default:state = false;
			break;
		}
	}
	if (empty(s)&&state)
	{
		return true;
	}
	return false;
}