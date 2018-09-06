#include "pch.h"
#include "Search.h"
#include <stdio.h>
#include <iostream>


int Sequential(List Tb1, ElementType K) {
	int i;
	Tb1->Elements[0] = K; /*½¨Á¢ÉÚ±ø(¸ÚÕ¾) int 0*/
	for (i = Tb1->Length; Tb1->Elements[i] != K; i--);
	return i;
}

int Binary(List Tb1, ElementType K) {
	int High, Low, Mid;
	int NotFound = -1;
	Low = 0;
	High = Tb1->Length - 1;
	while (Low < High) {
		Mid = (Low + High) / 2;
		if (Tb1->Elements[Mid] < K) {
			Low = Mid + 1;
		}
		else if (Tb1->Elements[Mid] > K) {
			High = Mid - 1;
		}
		else {
			return Mid;  /*Found*/
		}
	}
	return NotFound;
}

int Golden(List Tb1, ElementType K) {
	int High, Low, Mid;
	int NotFound = -1;
	Low = 0;
	High = Tb1->Length-1;
	while (Low < High) {
		Mid = Low +  (int) 0.618 * (High - Low);
		if (Tb1->Elements[Mid] < K) {
			Low = Mid + 1;
		}
		else if (Tb1->Elements[Mid] > K) {
			High = Mid - 1;
		}
		else {
			return Mid;
		}
	}
	return NotFound;
}





