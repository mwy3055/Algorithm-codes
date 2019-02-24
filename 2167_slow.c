#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	short arr[300][300];
	int n, m, k;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%hd", &arr[i][j]);
	scanf("%d", &k);
	while (k--)
	{
		int i, j, x, y, sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int a = i - 1; a < x; a++)
			for (int b = j - 1; b < y; b++)
				sum += arr[a][b];
		printf("%d\n", sum);
	}
}