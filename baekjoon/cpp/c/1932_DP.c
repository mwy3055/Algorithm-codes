#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

__inline int maxv(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	int i,j;
	scanf("%d", &n);
	short** arr = (short**)calloc(n, sizeof(short*));
	for (i = 0; i < n; i++)
		*(arr + i) = (short*)calloc(i + 1, sizeof(short));
	int** max = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		*(max + i) = (int*)calloc(i + 1, sizeof(int));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			scanf("%hd", &arr[i][j]);
	}

	for (i = n - 1; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == n - 1)
				max[i][j] = arr[i][j];
			else
				max[i][j] = maxv(max[i + 1][j], max[i + 1][j + 1]) + arr[i][j];
		}
	}

/*	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%2d ", max[i][j]);
		printf("\n");
	}*/


	printf("%d", max[0][0]);


	for (i = 0; i < n; i++)
	{
		free(*(arr + i));
		free(*(max + i));
	}
}