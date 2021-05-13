#pragma once
#include "graph.h"
typedef struct LoopQueue { //定义循环队列结构体 
	int data[MAX_VERTEX_NUM];
	int front;
	int rear;   //注意每次队尾标记指向最后一个元素的下一个位置 
}Queue, * LQueue;
void InitQueue(LQueue& Q);
bool QueueisFull(LQueue& Q);
bool QueueisEmpty(LQueue& Q);
void EnQueue(LQueue& Q, int i);
int DeQueue(LQueue& Q);
void DeQueue(LQueue& Q, int* k);