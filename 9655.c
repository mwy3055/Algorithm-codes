#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2) 
		printf("SK");
	else
		printf("CY");
	//상근이는 항상 홀수번째 돌을, 창영이는 항상 짝수번째 돌을 가져간다.
}