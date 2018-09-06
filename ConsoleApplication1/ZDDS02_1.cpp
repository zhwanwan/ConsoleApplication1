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
/*初始化*/
List MakeEmpty() {
	List L;
	L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

/*查找*/
Position Find(List L, ElementType X) {
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)
		return ERROR;
	else
		return i;
}

/*插入：在L的指定位置P前插入一个新元素X*/
bool Insert(List L, ElementType X, Position P) {
	Position i;
	if (L->Last == MAXSIZE - 1) {
		//printf("表满");
		std::cout << "表满\n";
		return false;
	}
	if (P<0 || P>L->Last + 1) {
		std::cout << "位置不合法\n";
		return false;
	}
	for (i = L->Last; i >= P;i--) {
		L->Data[i + 1] = L->Data[i]; /*将位置P及以后的元素顺序向后移动*/
		L->Data[P] = X; /*新元素插入*/
		L->Last++;      /*Last仍指向最后元素*/
		return true;
	}
	return false;

}

/*删除:从L中删除指定位置P的元素*/
bool Delete(List L, Position P) {
	Position i;
	if (P<0 || P>L->Last) {
		std::cout << ("位置%d不存在元素\n",P);
		return false;
	}
	for (i = P + 1; i < L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /*将位置P+1及以后的元素顺序向前移动*/
	L->Last--; /*Last仍指向最后元素*/
	return true;
}

