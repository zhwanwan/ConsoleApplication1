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
/*定义链表结构*/
struct LinkNode {
	BTree PTree; /*树结点*/
	LNode Next; /*链表下一个结点*/
};

typedef LNode QPosition;
typedef LNode Stack;
/*定义队列结构*/
struct QNode {
	QPosition Front, Rear; /*队列头，尾指针*/
};
typedef struct QNode *Queue;

/*链式堆栈操作*/
Stack CreateStack();
bool IsStackEmpty(Stack S);
void PushStack(Stack S,BTree X);
BTree PopStack(Stack S);


/*链式队列操作*/
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

void PreOrder(BTree BT); /*先序非递归遍历*/
void InOrder(BTree BT); /*中序非递归遍历*/
void PostOrder1(BTree BT); /*后续非递归遍历1*/
void PostOrder2(BTree BT); /*后续非递归遍历2*/
