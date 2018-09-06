#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define ERROR NULL

typedef int Position;
typedef int ElementType;
struct SNode {
	ElementType *Data; /*�洢Ԫ�ص�����*/
	Position Top;      /*ջ��ָ��*/
	int MaxSize;       /*��ջ�������*/
};

typedef struct SNode *Stack;

Stack CreateStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S) {
	return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, ElementType X) {
	if (IsFull(S)) {
		cout << "��ջ��" << endl;
		return false;
	}
	else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty(Stack S) {
	return (S->Top == -1);
}

ElementType Pop(Stack S) {
	if (IsEmpty(S)) {
		cout << "��ջ��" << endl;
		return ERROR;
	}
	else {
		return (S->Data[(S->Top)--]);
	}
}