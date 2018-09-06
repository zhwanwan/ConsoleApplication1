#include "pch.h"
#define ERROR NULL
#include <stdio.h>
#include <iostream>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/*查找*/
Position Find(List L, ElementType X) {
	Position p = L; /*p指向L的第1个结点*/
	while (p && p->Data != X)
		p = p->Next;
	if (p)
		return p;
	else
		return ERROR;
}

/*带头结点的插入*/
bool Insert(List L, ElementType X, Position P) {
	Position tmp, pre;
	for (pre = L; pre&&pre->Next != P; pre = pre->Next)
		if (pre == NULL) {
			std::cout << "插入位置参数错误\n";
			return false;
		}
		else { /*找到了P的前一个结点pre*/
			tmp = (Position)malloc(sizeof(struct LNode)); /*申请，填装结点*/
			tmp->Data = X;
			tmp->Next = P;
			pre->Next = tmp;
			return true;
		}
	return false;
}

/*带头结点的删除*/
bool Delete(List L, Position P) {
	Position pre;
	for (pre = L; pre&&pre->Next != P; pre = pre->Next)
		if (pre == NULL) {
			std::cout << "插入位置参数错误\n";
			return false;
		}
		else { /*找到了P的前一个结点pre*/
			pre->Next = P->Next; /*将位置P的结点删除*/
			free(P);
			return true;
		}
	return false;
}
