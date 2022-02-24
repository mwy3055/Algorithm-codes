#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define maxv(a,b) (((a)<(b))?(b):(a))

int main()
{
	int n, val[301] = { 0 }, i, dp[301] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
	}
	dp[1] = val[1];
	dp[2] = val[1] + val[2];
	for (i = 3; i <= n; i++)
	{
		dp[i] = maxv(dp[i - 2], dp[i - 3] + val[i - 1]) + val[i];
	}
	printf("%d", dp[n]);
}