#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, pr[1001], dp[1001] = { 0 };
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", pr + i);

	for (i = 1; i <= n; i++)
	{
		int max = pr[i];
		for (j = 1; j <= i - i / 2; j++)
		{
			if (dp[j] + dp[i - j] > max)
				max = dp[j] + dp[i - j];
		}
		dp[i] = max;
	}

	printf("%d", dp[n]);
}