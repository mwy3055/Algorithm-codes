#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define m 1000000000
int main()
{
	int n, k, sum = 0, dp[201][201] = { 0 }, i, j;
/*	
	typedef unsigned long long ull;
	ull dp[201] = { 0 }; 중복조합 계산:(n+1)H(i-1)
	scanf("%d %d", &n, &k);
	dp[1] = 1;
	for (i = 1; i <= k-1; i++)
	{
		dp[i + 1] = (dp[i] * (n + i) / i); 오버플로우..
	}*/ 
	scanf("%d %d", &n, &k);
	for (j = 1; j <= k; j++)
		dp[0][j] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
		}
	}
	printf("%d", dp[n][k]);
}
//3중 for로 식을 쓰고, 전개해서 정리하면 2중 for로 충분하다.