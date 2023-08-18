#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	int* p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", p + i);
	qsort(p, n, sizeof(int), compare);
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += *(p + j);
		}
	}
	printf("%d", sum);
	free(p);
}

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}