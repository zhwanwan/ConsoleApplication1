#include "pch.h"
#define MAXSIZE 10000
typedef int ElementType;
typedef struct LNode1 *List;
struct LNode1 {
	ElementType Elements[MAXSIZE];
	int Length;
};

int Sequential(List Tb1, ElementType K);

int Binary(List Tb1, ElementType K);

int Golden(List Tb1, ElementType K);

