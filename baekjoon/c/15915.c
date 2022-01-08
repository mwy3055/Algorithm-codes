#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 1002; i++)
		printf("-1\n");
}