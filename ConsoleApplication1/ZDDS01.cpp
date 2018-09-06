#include "ZDDS01.h"
#include "pch.h"

/**********
����N������������{ A1, A2, ��, AN}��
����f(i,j)=max{0,} �����ֵ��

***********/

/**
�򵥴ֱ���Ч�ʵ�
ʱ�临�ӣ�O(n^3)
**/
int MaxSubseqSum1(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

/**
ʱ�临��:O(n^2)
**/
int MaxSubseqSum2(int A[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += A[j];
		}
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
	}
	return MaxSum;
}

int Max3(int A, int B, int C)
{ /* ����3�������е����ֵ */
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{ /* ���η���List[left]��List[right]��������к� */
	int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
	int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) { /* �ݹ����ֹ����������ֻ��1������ */
		if (List[left] > 0)  return List[left];
		else return 0;
	}

	/* ������"��"�Ĺ��� */
	center = (left + right) / 2; /* �ҵ��зֵ� */
	/* �ݹ�����������е����� */
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	/* �������ֽ��ߵ�������к� */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* ����������ɨ�� */
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* ���ɨ����� */

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* ����������ɨ�� */
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* �ұ�ɨ����� */

	/* ���淵��"��"�Ľ�� */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

/**
�ֶ���֮���ݹ�˼��
ʱ�临�ӣ�O(nlogn)
**/
int MaxSubseqSum3(int List[], int N)
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
	return DivideAndConquer(List, 0, N - 1);
}

/**
���ߴ���:�����ߡ�����˼��ָÿ����һ�����ݾͽ��м�ʱ�������κ�һ���ط���ֹ���룬�㷨������ȷ������ǰ�Ľ⡣
ʱ�临�ӣ�O(n)
**/
int MaxSubseqSum4(int A[], int N) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}