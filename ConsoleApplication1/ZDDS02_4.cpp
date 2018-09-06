#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define ERROR NULL

typedef int ElementType;

typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};

typedef PtrToSNode Stack;

Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsStackEmpty(Stack S) {
	return (S->Next == NULL);
}

bool PushStack(Stack S, ElementType X) {
	PtrToSNode TmpCell;
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

ElementType PopStack(Stack S) {
	PtrToSNode FirstCell;
	ElementType TopElem;
	if (IsStackEmpty(S)) {
		cout << "¶ÑÕ»¿Õ" << endl;
		return ERROR;
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}