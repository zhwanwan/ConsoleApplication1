#include "pch.h"
#include "Tree.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;


Stack CreateStack() {
	Stack S;
	/*����һ����ջ��ͷ��㣬����ָ��*/
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
		cout << "��ջ��" << endl;
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
		cout << "���п�" << endl;
		return ERROR;
	}
	else {
		FrontCell = Q->Front;
		FrontElem = FrontCell->PTree;
		if (Q->Front == Q->Rear) {    /*������ֻ��һ��Ԫ��*/
			Q->Front = Q->Rear = NULL; /*ɾ�����������Ϊ��*/
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
		cout << "���Һ��ӽ�㲻��ȷ" << endl;
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
����һ(����ջ)��
1.����һ��ջ�������ڵ���ջ
2.���ջ��Ϊ�գ�������һ��ջ��ջ��Ԫ�ؼ���cur������һ��ջ��Ԫ�س�ջ��Ȼ��curѹ��ڶ���ջ�����cur�����ӽ����Ӽ����һ��ջ��������Һ��ӽ��Һ��Ӽ����һ��ջ
3.���ϵ��ظ�����2��ֱ����һ��ջΪ�գ���ӡ�ڶ���ջ����������
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
������(һ��ջ)��
cur��ʾջ��Ԫ��,h��ʾ�������ջ��Ԫ�أ���ʼ��ʱhΪͷ��㡣�㷨�������£�
1.����һ��ջ ����ͷ���ѹջ����ʼ��h������
2.���ջ��Ϊ�գ�cur��Ϊջ��Ԫ�أ�
��- a.���cur�����Ӳ�ΪNULL����h������cur������Ҳ������cur���Һ�����ô�ͽ�������ջ����������h���ڵ�ǰ�ڵ�����ӣ���˵���������Ѿ���ӡ���ˣ�����ʹ���û�д�ӡ������Ӧ�ý����ӻ����Һ�����ջ��
��- b.��1�����������������£�����cur���Һ��Ӳ�����h���Ҳ�Ϊ�գ���˵����������û�д���������ʱ���Ӧ�ý�cur���Һ�����ջ��
��- c.���ǰ��������������������˵��cur�����������������Ѿ���ӡ����ˣ����ߵ�ǰ�ڵ�ΪҶ�ӽڵ㣬��ʱ��Ӧ�ý�ջ��Ԫ�س�ջ�ˣ�������h=cur
3.һֱ�ظ�����2ֱ��ջΪ�գ���������
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