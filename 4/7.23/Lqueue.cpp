#include "Lqueue.h"

void InitQueue(LQueue& Q) {  //初始化队列 
	Q->front = Q->rear = 0;
}

bool QueueisFull(LQueue& Q) { //判断队列是否满了 
	if ((Q->rear + 1) % MAX_VERTEX_NUM== Q->front) {
		return true;  //已满 
	}
	else {
		return false;
	}
}

bool QueueisEmpty(LQueue& Q) {//判断队列是否为空 
	if (Q->front == Q->rear) {
		return true;
	}
	return false;
}


void EnQueue(LQueue& Q, int i) { //入队列 
	if (!QueueisFull(Q)) {
		Q->data[Q->rear] = i;
		Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;  //队尾指针后移 
	}
}

int DeQueue(LQueue& Q) { //出队列 
	int k;
	if (!QueueisEmpty(Q)) {
		k = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
		return k;
	}
	return 0;
}

void DeQueue(LQueue& Q, int* k)
{
	if (!QueueisEmpty(Q)) {
		*k = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
	}
}
