#pragma once
#include "graph.h"
typedef struct LoopQueue { //����ѭ�����нṹ�� 
	int data[MAX_VERTEX_NUM];
	int front;
	int rear;   //ע��ÿ�ζ�β���ָ�����һ��Ԫ�ص���һ��λ�� 
}Queue, * LQueue;
void InitQueue(LQueue& Q);
bool QueueisFull(LQueue& Q);
bool QueueisEmpty(LQueue& Q);
void EnQueue(LQueue& Q, int i);
int DeQueue(LQueue& Q);
void DeQueue(LQueue& Q, int* k);