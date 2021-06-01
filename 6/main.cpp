#include "Csort.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
	SqList list;
	list.length = 10;
	for (int i=1;i<=10;i++)
	{
		list.r[i].key = rand();
		cout << list.r[i].key << "   ";
		if (i==list.length)
		{
			cout << endl;
		}
	}
	//BiInsertionSort(list);
	//BubbleSort(list);
	//QSort(list, 1, list.length);
	//SelectSort(list);
	//MergeSort(list);
	HeapSort(list);
	for (int i = 1; i <= 10; i++)
	{
		cout<<list.r[i].key<<"   ";
		if (i==10)
		{
			cout << endl;
		}
	}
	return 0;
}