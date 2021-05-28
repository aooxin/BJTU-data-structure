#include "Tree.h"
#include "Hash.h"
int main()
{
	int n,tmp;
	/*cin >> n;
	BSTree T=NULL;
	for (int i=0;i<n;i++)
	{
		cin >> tmp;
		insertBSTree(T, tmp);
	}
	Inorder(T);*/
	KeyType HashTable[Max] = { 0 };
	cin >> n;
	// 9 19 01 23 14 55 68 11 82 36
	for (int i=0;i<n;i++)
	{
		cin >> tmp;
		InsertHash(HashTable, tmp);
	}
	for (int i=0;i<Max;i++)
	{
		cout << HashTable[i]<<" ";
	}
	cout << endl;
	cout << SearchHash(HashTable, 23);
	return 0;
}