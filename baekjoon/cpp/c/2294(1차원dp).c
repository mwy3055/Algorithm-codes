#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int val(int, int);
int dp[10001]; //최적화: dp를 main에서 선언하고 초기화, val함수에 넘겨주기
int main()
{
	int n, k, coin[100];
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", coin + i);

	for (i = 0; i < n; i++) 
		for (j = 1; j <= k; j++)
			dp[j] = val(coin[i], j);
	//k를 먼저?
	/*
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i + coin[j] > k)
				break;
			if ((i == 0 || dp[i] != 0) && (dp[i + coin[j]] == 0 || dp[i + coin[j]] > dp[i]))
				dp[i + coin[j]] = dp[i] + 1;
		}
	}
	*/
	printf("%d", dp[k] ? dp[k] : -1);
}

int val(int coin, int j)
{
	int temp = 1 << 30;
	if (j > 0)
	{
		if (j >= coin && dp[j - coin] > 0 && dp[j - coin] + 1 < temp)
			temp = dp[j - coin] + 1;
		if (dp[j] > 0 && dp[j] < temp)
			temp = dp[j];
	}
	if (j%coin == 0 && j / coin < temp)
		temp = j / coin;
	return temp == 1 << 30 ? 0 : temp;
}