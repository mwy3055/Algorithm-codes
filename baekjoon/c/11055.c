#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

__inline int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int n, arr[1000], dp[1000], rst = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		dp[i] = arr[i];
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		rst = max(rst, dp[i]);
	}
	printf("%d", rst);
}