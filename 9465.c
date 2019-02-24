#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

__inline int max(int a, int b)
{
	return a < b ? b : a;
}

int sticker()
{
	int dp[2][100000] = { 0 };
	char val[2][100000] = { 0 };
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < 2; i++)
		for (j = 0; j < n; j++)
			scanf("%hhd", &val[i][j]);

	dp[0][0] = val[0][0];
	dp[1][0] = val[1][0];
	dp[0][1] = max(dp[0][0], dp[1][0] + val[0][1]);
	dp[1][1] = max(dp[1][0], dp[0][0] + val[1][1]);
	for (i = 2; i < n; i++)
	{
		dp[0][i] = max(max(dp[1][i - 2], dp[1][i - 1]), dp[0][i - 2]) + val[0][i];
		dp[1][i] = max(max(dp[0][i - 2], dp[0][i - 1]), dp[1][i - 2]) + val[1][i];
	}
	return max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		printf("%d\n", sticker());
	}
}