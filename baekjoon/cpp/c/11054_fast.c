#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int dp[2][1000];

__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int n, i, j, ar[1000], max = -1;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);

	for (i = 0; i < n; i++)
	{
		int tmax = 0;
		for (j = 0; j < i; j++)
		{
			if (ar[j] < ar[i])
				tmax = maxv(tmax, dp[0][j]);
		}
		dp[0][i] = tmax + 1;
	}

	for (i = n - 1; i >= 0; i--) //거꾸로 가자
	{
		int tmax = 0;
		for (j = n - 1; j > i; j--)
		{
			if (ar[j] < ar[i])
				tmax = maxv(tmax, dp[1][j]);
		}
		dp[1][i] = tmax + 1;
		max = maxv(max, dp[0][i] + dp[1][i] - 1);
	}

	printf("%d", max);
}