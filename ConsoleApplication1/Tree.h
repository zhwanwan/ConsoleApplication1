#include "pch.h"
#define LEFTCHILD 0
#define RIGHTCHILD 1
#define ERROR NULL

typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef BinTree BTree;
struct TreeNode {
	ElementType Data;
	BTree LeftChildTree;
	BTree RightChildTree;
};
typedef struct LinkNode *LNode;
/*��������ṹ*/
struct LinkNode {
	BTree PTree; /*�����*/
	LNode Next; /*������һ�����*/
};

typedef LNode QPosition;
typedef LNode Stack;
/*������нṹ*/
struct QNode {
	QPosition Front, Rear; /*����ͷ��βָ��*/
};
typedef struct QNode *Queue;

/*��ʽ��ջ����*/
Stack CreateStack();
bool IsStackEmpty(Stack S);
void PushStack(Stack S,BTree X);
BTree PopStack(Stack S);


/*��ʽ���в���*/
Queue CreateQue();
bool IsQEmpty(Queue Q);
bool AddQue(Queue Q, BTree X);
BTree DeleteQue(Queue Q);

BinTree CreateBinTree(ElementType Root);
bool IsBinTreeEmpty(BTree BT);
BTree addTreeNode(BTree P, ElementType X, int ChildPos);
void PreOrderTraversal(BTree BT);
void InOrderTraversal(BTree BT);
void PostOrderTraversal(BTree BT);
void LevelOrderTraversal(BTree BT);

void PreOrder(BTree BT); /*����ǵݹ����*/
void InOrder(BTree BT); /*����ǵݹ����*/
void PostOrder1(BTree BT); /*�����ǵݹ����1*/
void PostOrder2(BTree BT); /*�����ǵݹ����2*/
