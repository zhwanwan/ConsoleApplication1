#include "pch.h"
#include "Tree.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;


Stack CreateStack() {
	Stack S;
	/*构建一个堆栈的头结点，返回指针*/
	S = (Stack)malloc(sizeof(struct LinkNode));
	S->PTree = NULL;
	S->Next = NULL;
	return S;
}

bool IsStackEmpty(Stack S) {
	return S->Next == NULL;
}

void PushStack(Stack S,BTree X) {
	QPosition tmpCell;
	tmpCell = (QPosition)malloc(sizeof(struct LinkNode));
	tmpCell->PTree = X;
	tmpCell->Next = S->Next;
	S->Next = tmpCell;
}

BTree PopStack(Stack S) {
	BTree BT;
	QPosition FirstCell;
	if (IsStackEmpty(S)) {
		cout << "堆栈空" << endl;
		return ERROR;
	}
	else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		BT = FirstCell->PTree;
		free(FirstCell);
		return BT;
	}
}

Queue CreateQue() {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = NULL;
	return Q;
}

bool IsQEmpty(Queue Q) {
	return (Q->Front == NULL);
}

bool AddQue(Queue Q, BTree X) {
	QPosition tmpCell;
	tmpCell = (QPosition)malloc(sizeof(struct LinkNode));
	tmpCell->PTree = X;
	if (IsQEmpty(Q)) {
		Q->Front = Q->Rear = tmpCell;
	}
	else {
		Q->Rear->Next = tmpCell;
		Q->Rear = tmpCell;
	}
	return true;
}

BTree DeleteQue(Queue Q) {
	QPosition FrontCell;
	BTree FrontElem;
	if (IsQEmpty(Q)) {
		cout << "队列空" << endl;
		return ERROR;
	}
	else {
		FrontCell = Q->Front;
		FrontElem = FrontCell->PTree;
		if (Q->Front == Q->Rear) {    /*若队列只有一个元素*/
			Q->Front = Q->Rear = NULL; /*删除后队列设置为空*/
		}
		else {
			Q->Front = Q->Front->Next;
		}
		free(FrontCell);
		return FrontElem;
	}
}

BTree CreateBinTree(ElementType Root) {
	BTree BT = (BTree)malloc(sizeof(struct TreeNode));
	BT->Data = Root;
	BT->LeftChildTree = BT->RightChildTree = NULL;
	return BT;
}

bool IsBinTreeEmpty(BTree BT) {
	return BT;
}

BTree addTreeNode(BTree P, ElementType X, int ChildPos) {
	BTree tmpNode;
	tmpNode = (BTree)malloc(sizeof(struct TreeNode));
	tmpNode->Data = X;
	tmpNode->LeftChildTree = NULL;
	tmpNode->RightChildTree = NULL;
	if (ChildPos == LEFTCHILD) {
		P->LeftChildTree = tmpNode;
		return tmpNode;
	}
	else if (ChildPos = RIGHTCHILD) {
		P->RightChildTree = tmpNode;
		return tmpNode;
	}
	else {
		cout << "左右孩子结点不明确" << endl;
		free(tmpNode);
		return NULL;
	}
}

void PreOrderTraversal(BTree BT) {
	if (BT) {
		cout << dec << setw(4) << BT->Data;
		PreOrderTraversal(BT->LeftChildTree);
		PreOrderTraversal(BT->RightChildTree);
	}
}

void InOrderTraversal(BTree BT) {
	if (BT) {
		InOrderTraversal(BT->LeftChildTree);
		cout << dec << setw(4) << BT->Data;
		InOrderTraversal(BT->RightChildTree);
	}
}

void PostOrderTraversal(BTree BT) {
	if (BT) {
		PostOrderTraversal(BT->LeftChildTree);
		PostOrderTraversal(BT->RightChildTree);
		cout << dec << setw(4) << BT->Data;
	}
}

void LevelOrderTraversal(BTree BT) {
	Queue Q;
	BTree T;
	if (!BT) return;
	Q = CreateQue();
	AddQue(Q, BT);
	while (!IsQEmpty(Q)) {
		T = DeleteQue(Q);
		cout << dec << setw(4) << T->Data;
		if (T->LeftChildTree) {
			AddQue(Q, T->LeftChildTree);
		}
		if (T->RightChildTree) {
			AddQue(Q, T->RightChildTree);
		}
	}
}

void PreOrder(BTree BT) {
	BTree T = BT;
	Stack S = CreateStack();
	while (T || !IsStackEmpty(S)) {
		while (T) {
			PushStack(S, T);
			cout << dec << setw(4) << T->Data;
			T = T->LeftChildTree;
		}
		if (!IsStackEmpty(S)) {
			T = PopStack(S);
			T = T->RightChildTree;
		}
	}
}

void InOrder(BTree BT) {
	BTree T = BT;
	Stack S = CreateStack();
	while (T || !IsStackEmpty(S)) {
		while (T) {
			PushStack(S, T);
			T = T->LeftChildTree;
		}
		if (!IsStackEmpty(S)) {
			T = PopStack(S);
			cout << dec << setw(4) << T->Data;
			T = T->RightChildTree;
		}
	}
}


/**
方法一(两个栈)：
1.申请一个栈，将根节点入栈
2.如果栈不为空，弹出第一个栈的栈顶元素记做cur，将第一个栈顶元素出栈，然后将cur压入第二个栈。如果cur有左孩子将左孩子加入第一个栈，如果有右孩子将右孩子加入第一个栈
3.不断的重复步骤2，直到第一个栈为空，打印第二个栈，结束程序！
**/
void PostOrder1(BTree BT) {
	BTree T;
	BTree cur;
	Stack S1 = CreateStack();
	Stack S2 = CreateStack();
	PushStack(S1, BT);
	while (!IsStackEmpty(S1)) {
		cur = PopStack(S1);
		PushStack(S2, cur);
		if (cur->LeftChildTree)
			PushStack(S1, cur->LeftChildTree);
		if (cur->RightChildTree)
			PushStack(S1, cur->RightChildTree);
	}
	while (!IsStackEmpty(S2)) {
		T = PopStack(S2);
		cout << dec << setw(4) << T->Data;
	}


}

/*TOUN*/
/**
方法二(一个栈)：
cur表示栈顶元素,h表示的是最近栈的元素，初始化时h为头结点。算法流程如下：
1.申请一个栈 ，将头结点压栈，初始化h变量，
2.如果栈不为空，cur赋为栈顶元素！
—- a.如果cur的左孩子不为NULL并且h不等于cur的左孩子也不等于cur的右孩子那么就将左孩子入栈。（如果最近h等于当前节点的左孩子，就说明左子树已经打印完了，否则就代表还没有打印过，就应该将左孩子或者右孩子入栈）
—- b.在1条件不成立的条件下，并且cur的右孩子不等于h并且不为空，就说明右子树还没有处理过，这个时候就应该将cur的右孩子入栈！
—- c.如果前俩个条件都不成立，就说明cur的左子树和右子树已经打印完毕了，或者当前节点为叶子节点，此时就应该将栈顶元素出栈了，并且令h=cur
3.一直重复步骤2直到栈为空，结束程序
**/
void PostOrder2(BTree BT) {
	BTree cur;
	BTree T = BT;
	Stack S = CreateStack();
	PushStack(S, T);
	while (!IsStackEmpty(S)) {
		cur = PopStack(S);
		if (cur->LeftChildTree && cur->LeftChildTree != T && cur->RightChildTree != T) {
			PushStack(S,cur->LeftChildTree);
		}
		else if (cur->RightChildTree && cur->RightChildTree != T) {
			PushStack(S, cur->RightChildTree);
		}
		else {
			PopStack(S);
			T = cur;
			cout << dec << setw(4) << cur->Data;
		}
	}

}