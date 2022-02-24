#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define subsum(i,j,x,y) (dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1])

int main()
{
	int dp[301][301] = { 0 };
	short arr[301][301];
	int n, m, k;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%hd", &arr[i][j]);
			if (1 == i && 1 == j)
				dp[i][j] = arr[i][j];
			else
				dp[i][j] = dp[i][j - 1] + subsum(1, j, i - 1, j) + arr[i][j];
		}

	scanf("%d", &k);
	for (int a = 0; a < k; a++)
	{
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", subsum(i, j, x, y));
	}
}