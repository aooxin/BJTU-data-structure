#include "Hash.h"

void InsertHash(KeyType* HT, KeyType key)
{
	int mo = key % 11;
	bool iscomplete=false;
	if (HT[mo]==0)
	{
		HT[mo] = key;
	}
	else 
	{
		for (int i=1;i<11;i++)
		{
			mo = (key + i) % 11;
			if (HT[mo]==0)
			{
				HT[mo] = key;
				iscomplete = true;
				break;
			}
		}
	}
}

int SearchHash(KeyType* HT, KeyType key)
{
	int mo = key % 11;
	bool iscomplete = false;
	if (HT[mo]==key)
	{
		return mo+1;
	}
	else
	{
		for (int i=1;i<11;i++)
		{
			mo = (key + i) % 11;
			if (HT[mo] == key)
			{
				return mo+1;
				break;
			}
		}
	}
	return -1;
}
