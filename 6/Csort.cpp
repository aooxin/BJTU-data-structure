#include "Csort.h"

void BiInsertionSort(SqList& L)
{
	for (int i = 2; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - 1].key)
		{
			L.r[0] = L.r[i];
			int low = 1, high = i - 1;
			while (low <= high)
			{
				int m = (low + high) / 2;
				if (L.r[0].key < L.r[m].key)
				{
					high = m - 1;
				}
				else
				{
					low = m + 1;
				}
			}
			for (int j = i - 1; j >= high + 1; --j)
			{
				L.r[j + 1] = L.r[j];
			}
			L.r[high + 1] = L.r[0];//插入
		}
	}
}

void BubbleSort(SqList& L)
{
	int i = L.length;
	int flag = 1;
	while ((i>1)&&flag)
	{
		flag = 0;
		for (int j=1;j<i;j++)
		{
			if (L.r[j].key>L.r[j+1].key)
			{
				Swap(L.r[j], L.r[j + 1]);
				flag = 1;
			}
		}
		i--;
	}
}

void Swap(RcdType& R1, RcdType& R2)
{
	RcdType tmp;
	tmp.key = R1.key;
	R1.key = R2.key;
	R2.key = tmp.key;
}

void QSort(SqList& L, int s, int t)
{
	int pivotloc;
	if (s<t)
	{
		pivotloc = Partion(L, s, t);
		QSort(L, s, pivotloc - 1);
		QSort(L, pivotloc + 1, t);
	}
}

int Partion(SqList& L, int low, int high)
{
	L.r[0].key = L.r[low].key;
	int pivotkey = L.r[low].key;
	while (low<high)
	{
		while (low<high&&L.r[high].key>=pivotkey)
		{
			--high;
		}
		L.r[low] = L.r[high];//小的交换到低端
		while (low<high&&L.r[low].key<=pivotkey)
		{
			++low;
		}
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void SelectSort(SqList& L)
{
	int j;
	for (int i=1;i<L.length;++i)
	{
		j = SelectMinkey(L, i);
		if (i!=j)
		{
			Swap(L.r[i], L.r[j]);
		}
	}
}

int SelectMinkey(SqList& L, KeyType i)
{
	int min=L.r[i].key,j=i;
	for (++i;i<=L.length;i++)
	{
		if (min>L.r[i].key)
		{
			min = L.r[i].key;
			j = i;
		}
	}
	return j;
}

void Merge(SqList& SL, SqList& TL,int i,int m, int n)
{
	int k,j;
	//将有序的记录序列SL[i..m],SL[m+1..n]归为TR[i..n]
	for (j=m+1,k=i;i<=m&&j<=n;++k)
	{
		if (SL.r[i].key<=SL.r[j].key)
		{
			TL.r[k] = SL.r[i++];
		}
		else
		{
			TL.r[k] = SL.r[j++];
		}
	}
	int ktmp = k, ntmp = n, mtmp = m,itmp=i;
	if (i<=m)
	{
		for (;ktmp<=m;ktmp++,itmp++)
		{
			TL.r[ktmp] = SL.r[itmp];
		}
	}
	itmp = j;
	if (j<=n)
	{
		for (; ktmp <= m; ktmp++, itmp++)
		{
			TL.r[ktmp] = SL.r[itmp];
		}
	}
}
void Msort(SqList& SL, SqList& TL, int s, int t)
{
	//将SL[s..t]归并排序为TL[s..t]
	SqList Tl2;
	if (s == t)
	{
		TL.r[s] = SL.r[s];
	}
	else
	{
		int m = (s + t) / 2;
		Msort(SL, Tl2, s, m);
		Msort(SL, Tl2, m + 1, t);
		Merge(Tl2, TL, s, m, t);
	}
}

void MergeSort(SqList& L)
{
	Msort(L, L, 1, L.length);
}

void HeapAdjust(RcdType(&R)[MaxSize], int s, int m)
{
	RcdType rc = R[s];
	for (int j=2*s;j<=m;j*=2)
	{
		if (j < m && R[j].key < R[j + 1].key)++j;
		if (rc.key>=R[j].key)break;
		R[s] = R[j];
		s = j;
	}
	R[s] = rc;
}

void HeapSort(HeapType& H)
{
	for (int i = H.length; i > 0; i--)HeapAdjust(H.r, i, H.length);
	for (int i = H.length; i > 1; --i)
	{
		Swap(H.r[1], H.r[i]);
		HeapAdjust(H.r, 1, i - 1);
	}
}
