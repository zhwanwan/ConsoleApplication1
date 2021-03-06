// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include "pch.h"
#include "ZDDS01.h"
#include "ZDDS03.h"
#include "Search.h"
#include <iostream>
#include <time.h>
using namespace std;

void PrintTime();

static clock_t start, stop;
double duration;

void PrintTime() {

	duration = ((double)(stop - start))/CLK_TCK/MAXSIZE;
	printf("ticks = %f\n", (double)(stop - start));
	printf("duation = %6.2e\n", duration);
}

int main()
{
 /*
	cout << "Hello World!\n"; 

	int A[] = { -1,2,1,-4,9,7,-8,10 };
	int n = 8;
	//	std::cout <<("%d",MaxSubseqSum1(A,n));
	//	std::cout <<("%d",MaxSubseqSum2(A,n));
	cout <<  MaxSubseqSum4(A, n) << endl;
*/

/*	List L;
	L = (List)malloc(sizeof(struct LNode1));
	L->Length = MAXSIZE;
	int i;
	for (i = 0; i < L->Length; i++) {
		L->Elements[i] = i;
	}
	start = clock();
	for (i = 0; i < MAXSIZE; i++) {
		Binary(L, i);
	}
	stop = clock();
	cout << "#1" << endl;
	PrintTime();

	start = clock();
	for (i = 0; i < MAXSIZE; i++) {
		Golden(L, i);
	}
	stop = clock();
	cout << "#2" << endl;
	PrintTime();
*/
	BinTree BT = CreateBinTree(0);
	BTree p1 = addTreeNode(BT, 1, 0);
	BTree p2 = addTreeNode(BT, 2, 1);
	for (int i = 3; i <= 20; i++) {
		if (i % 2 == 0) {
			p1 = addTreeNode(p1, i, i % 2);
		}
		else {
			p2 = addTreeNode(p2, i, i % 2);
		}
	}
	cout << "先序：" << endl;
	PreOrderTraversal(BT);
	cout << endl << "中序：" << endl;
	InOrderTraversal(BT);
	cout << endl << "后序：" << endl;
	PostOrderTraversal(BT);
	cout << endl << "层次：" << endl;
	LevelOrderTraversal(BT);
	return 0;
}



