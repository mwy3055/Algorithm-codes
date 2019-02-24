#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b >= c)
		printf("-1");
	else
		printf("%d", (int)((double)a / (c - b)) + 1); //식 쓰면 바로 나온다.
}