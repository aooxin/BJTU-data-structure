#include "list.h"
#include "Stack.h"
int main()
{
	datalist L;
	Init_List(L);
	Create_List(L);
	Display_All(L);
	if (Judge(L)==true)
	{
		printf("ƥ��ɹ�");
	}
	else
	{
		printf("ƥ��ʧ��");
	}
	return 0;
}