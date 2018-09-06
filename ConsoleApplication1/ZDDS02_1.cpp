#include "pch.h"
#define MAXSIZE 100
#define ERROR -1
#include <stdio.h>
#include <iostream> 

typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
/*��ʼ��*/
List MakeEmpty() {
	List L;
	L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

/*����*/
Position Find(List L, ElementType X) {
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)
		return ERROR;
	else
		return i;
}

/*���룺��L��ָ��λ��Pǰ����һ����Ԫ��X*/
bool Insert(List L, ElementType X, Position P) {
	Position i;
	if (L->Last == MAXSIZE - 1) {
		//printf("����");
		std::cout << "����\n";
		return false;
	}
	if (P<0 || P>L->Last + 1) {
		std::cout << "λ�ò��Ϸ�\n";
		return false;
	}
	for (i = L->Last; i >= P;i--) {
		L->Data[i + 1] = L->Data[i]; /*��λ��P���Ժ��Ԫ��˳������ƶ�*/
		L->Data[P] = X; /*��Ԫ�ز���*/
		L->Last++;      /*Last��ָ�����Ԫ��*/
		return true;
	}
	return false;

}

/*ɾ��:��L��ɾ��ָ��λ��P��Ԫ��*/
bool Delete(List L, Position P) {
	Position i;
	if (P<0 || P>L->Last) {
		std::cout << ("λ��%d������Ԫ��\n",P);
		return false;
	}
	for (i = P + 1; i < L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /*��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ�*/
	L->Last--; /*Last��ָ�����Ԫ��*/
	return true;
}

