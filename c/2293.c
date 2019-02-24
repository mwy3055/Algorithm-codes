#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, k, coin[100], dp[10001] = { 1 }; 
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", coin + i);
		for (j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]]; //경우가 없으면 0을 더하겠지
		}
	}
	printf("%d", dp[k]);
}
//j=coin[i]일 때 dp[0]=1이므로 dp[j]에 한 가지 방법(i번째 동전 1개의 경우)이 추가된다.