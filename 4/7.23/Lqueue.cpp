#include "Lqueue.h"

void InitQueue(LQueue& Q) {  //��ʼ������ 
	Q->front = Q->rear = 0;
}

bool QueueisFull(LQueue& Q) { //�ж϶����Ƿ����� 
	if ((Q->rear + 1) % MAX_VERTEX_NUM== Q->front) {
		return true;  //���� 
	}
	else {
		return false;
	}
}

bool QueueisEmpty(LQueue& Q) {//�ж϶����Ƿ�Ϊ�� 
	if (Q->front == Q->rear) {
		return true;
	}
	return false;
}


void EnQueue(LQueue& Q, int i) { //����� 
	if (!QueueisFull(Q)) {
		Q->data[Q->rear] = i;
		Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;  //��βָ����� 
	}
}

int DeQueue(LQueue& Q) { //������ 
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
