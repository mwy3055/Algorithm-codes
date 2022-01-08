#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 0, n;
	scanf("%d", &n);
	int* clis = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		clis[x] = clis[x - 1] + 1;
		if (max < clis[x])
			max = clis[x];
	}
	printf("%d", n - max);
}