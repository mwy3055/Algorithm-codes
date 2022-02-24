#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char arr[1001][1001];
short sq[1001][1001];

__inline short minv(short a, short b)
{
	return a < b ? a : b;
}
__inline short maxv(short a, short b)
{
	return a < b ? b : a;
}
#define isin(a,b) ((0<=a && a<n && 0<=b && b<m)?(1):(0))

int main()
{
	int n, m;
	short max = 0;
	int i, j;
	scanf("%d %d", &n, &m);
	getchar();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			arr[i][j] = getchar() - '0';
		}
		getchar();
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (arr[i][j])
			{
				sq[i][j] = minv(sq[i - 1][j], minv(sq[i - 1][j - 1], sq[i][j - 1])) + 1;
			}
			printf("%d ", sq[i][j]);
			max = maxv(max, sq[i][j]);
		}
		printf("\n");
	}
	printf("%d", max*max);
}