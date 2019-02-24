#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

short** arr;
int** max;
int n;

__inline int maxv(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int i, int j)
{
	if (i == n - 1)
		return arr[i][j];
	else if (max[i][j])
		return max[i][j];

	return max[i][j] = maxv(dfs(i + 1, j), dfs(i + 1, j + 1)) + arr[i][j];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	arr = (short**)calloc(n, sizeof(short*));
	max = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
	{
		*(arr + i) = calloc(i + 1, sizeof(short));
		*(max + i) = calloc(i + 1, sizeof(int));
	}

	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			scanf("%hd", &arr[i][j]);

	printf("%d", dfs(0, 0));



	for (i = 0; i < n; i++)
	{
		free(*(arr + i));
		free(*(max + i));
	}
}