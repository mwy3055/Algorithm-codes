#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	long long dp[16][16] = { 0 }, ans;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 || j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	if (k)
	{
		int a = (k - 1) / m + 1, b = (k - 1) % m + 1;
		ans = dp[a][b] * dp[n - a + 1][m - b + 1];
	}
	else
	{
		ans = dp[n][m];
	}
	
	printf("%lld", ans);
}