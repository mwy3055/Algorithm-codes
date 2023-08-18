#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	int* num = (int*)calloc(n + 1, sizeof(int));
	ll** dp = (ll**)calloc(n + 1, sizeof(ll*));
	for (i = 0; i <= n; i++)
		*(dp + i) = (ll*)calloc(21, sizeof(ll));

	for (i = 1; i <= n; i++)
		scanf("%d", num + i);

	dp[1][num[1]] = 1;

	for (i = 2; i < n; i++)
	{
		for (j = 0; j <= 20; j++)
		{
			if (j - num[i] >= 0)
				dp[i][j] += dp[i - 1][j - num[i]];
			if (j + num[i] <= 20)
				dp[i][j] += dp[i - 1][j + num[i]];
		}
	}

	printf("%lld", dp[n - 1][num[n]]);

	free(num);
	for(i=0;i<=n;i++)
		free(*(dp + i));
}