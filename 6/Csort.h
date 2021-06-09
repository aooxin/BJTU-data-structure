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
//�۰�����
void BiInsertionSort(SqList& L);

//ð��
void BubbleSort(SqList& L);//ð��
void Swap(RcdType& R1, RcdType& R2);

//����
void QSort(SqList& L, int s, int t);
int Partion(SqList& L, int low, int high);

//��ѡ������
void SelectSort(SqList& L);
int SelectMinkey(SqList&L,KeyType i);//ѡi..n ��С��

//�鲢����
void merge(RcdType* a, int i, int m, int n);
void Msort(RcdType* a, int s, int t);
void MergeSort(SqList& L);

//������
typedef SqList HeapType;
void HeapAdjust(RcdType(&R)[MaxSize], int s, int m);
void HeapSort(HeapType& H);