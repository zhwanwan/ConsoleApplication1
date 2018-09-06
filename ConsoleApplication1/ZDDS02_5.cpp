#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define ERROR NULL

typedef int ElementType;
typedef int Position;

struct QNode {
	ElementType *Data;    /*存储元素的数组*/
	Position Front, Rear; /*队列的头,尾指针*/
	int MaxSize;          /*队列最大容量*/
};

typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool IsQueueFull(Queue Q) {
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool AddQueue(Queue Q, ElementType X) {
	if (IsQueueFull(Q)) {
		cout << "队列满" << endl;
		return false;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool IsQueueEmpty(Queue Q) {
	return (Q->Rear == Q->Front);
}

ElementType DeleteQueue(Queue Q) {
	if (IsQueueEmpty(Q)) {
		cout << "队列空" << endl;
		return ERROR;
	}
	else {
		ElementType tmpCell = Q->Data[Q->Front];
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return tmpCell;
	}
}
