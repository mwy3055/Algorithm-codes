#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int dp[41] = { 0 }; //피보나치 수열
	char vip[41] = { 0 };
	int n, m, result = 1;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		vip[temp] = 1;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int len = 0;
	for (i = 1; i <= n; i++)
	{
		if (!vip[i])
			len++;
		else
		{
			result *= dp[len];
			len = 0;
		}
	}
	if (len)
		result *= dp[len];
	printf("%d", result);
}