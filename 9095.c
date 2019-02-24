#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, dp[12] = { 1 };
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			if (i <= 2)
				dp[i] = i;
			else
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n]);
	}
}