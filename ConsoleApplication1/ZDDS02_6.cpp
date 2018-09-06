/**
���е���ʽ�洢ʵ��

**/

#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define ERROR NULL

typedef int ElementType;
typedef struct Node *PtrToNode1;
struct Node {
	ElementType Data;
	PtrToNode1 Next1;
};

typedef PtrToNode1 Position1;

struct QNode {
	Position1 Front1, Rear1; /*����ͷ��βָ��*/
};

typedef struct QNode *Queue;

Queue CreateQue() {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front1 = Q->Rear1 = NULL;
	return Q;
}

bool IsQEmpty(Queue Q) {
	return (Q->Front1 == NULL);
}

bool AddQue(Queue Q,ElementType X) {
	Position1 tmpCell;
	tmpCell = (Position1)malloc(sizeof(struct Node));
	tmpCell->Data = X;
	Q->Rear1->Next1 = tmpCell;
	Q->Rear1 = tmpCell;
	return true;
}

ElementType DeleteQue(Queue Q) {
	Position1 FrontCell;
	ElementType FrontElem;
	if (IsQEmpty(Q)) {
		cout << "���п�" << endl;
		return ERROR;
	}
	else {
		FrontCell = Q->Front1;
		FrontElem = FrontCell->Data;
		if (Q->Front1 == Q->Rear1) {    /*������ֻ��һ��Ԫ��*/
			Q->Front1 = Q->Rear1 = NULL; /*ɾ�����������Ϊ��*/
		}
		else {
			Q->Front1 = Q->Front1->Next1;
		}
		free(FrontCell);
		return FrontElem;
	}
}

