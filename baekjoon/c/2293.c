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
			dp[j] += dp[j - coin[i]]; //��찡 ������ 0�� ���ϰ���
		}
	}
	printf("%d", dp[k]);
}
//j=coin[i]�� �� dp[0]=1�̹Ƿ� dp[j]�� �� ���� ���(i��° ���� 1���� ���)�� �߰��ȴ�.