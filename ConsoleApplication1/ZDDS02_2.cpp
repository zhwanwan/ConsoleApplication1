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

/*����*/
Position Find(List L, ElementType X) {
	Position p = L; /*pָ��L�ĵ�1�����*/
	while (p && p->Data != X)
		p = p->Next;
	if (p)
		return p;
	else
		return ERROR;
}

/*��ͷ���Ĳ���*/
bool Insert(List L, ElementType X, Position P) {
	Position tmp, pre;
	for (pre = L; pre&&pre->Next != P; pre = pre->Next)
		if (pre == NULL) {
			std::cout << "����λ�ò�������\n";
			return false;
		}
		else { /*�ҵ���P��ǰһ�����pre*/
			tmp = (Position)malloc(sizeof(struct LNode)); /*���룬��װ���*/
			tmp->Data = X;
			tmp->Next = P;
			pre->Next = tmp;
			return true;
		}
	return false;
}

/*��ͷ����ɾ��*/
bool Delete(List L, Position P) {
	Position pre;
	for (pre = L; pre&&pre->Next != P; pre = pre->Next)
		if (pre == NULL) {
			std::cout << "����λ�ò�������\n";
			return false;
		}
		else { /*�ҵ���P��ǰһ�����pre*/
			pre->Next = P->Next; /*��λ��P�Ľ��ɾ��*/
			free(P);
			return true;
		}
	return false;
}
