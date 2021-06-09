#pragma once
#define MaxSize 1000
typedef int KeyType;
typedef struct 
{
	KeyType key;
}RcdType;

typedef struct 
{
	RcdType r[MaxSize];
	int length;
}SqList;
//’€∞Î≈≈–Ú
void BiInsertionSort(SqList& L);

//√∞≈›
void BubbleSort(SqList& L);//√∞≈›
void Swap(RcdType& R1, RcdType& R2);

//øÏ≈≈
void QSort(SqList& L, int s, int t);
int Partion(SqList& L, int low, int high);

//ºÚµ•—°‘Ò≈≈–Ú
void SelectSort(SqList& L);
int SelectMinkey(SqList&L,KeyType i);//—°i..n ◊Ó–°µƒ

//πÈ≤¢≈≈–Ú
void merge(RcdType* a, int i, int m, int n);
void Msort(RcdType* a, int s, int t);
void MergeSort(SqList& L);

//∂—≈≈–Ú
typedef SqList HeapType;
void HeapAdjust(RcdType(&R)[MaxSize], int s, int m);
void HeapSort(HeapType& H);