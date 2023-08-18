#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

__inline int maxv(a, b)
{
	return a < b ? b : a;
}

int main()
{
	int n, i, max = -1;
	int tempmax;
	scanf("%d", &n);
	int* num = (int*)calloc(n + 1, sizeof(int));
	int* dp = (int*)calloc(n + 1, sizeof(int));

	for (i = 1; i <= n; i++)
	{
		scanf("%d", num + i);
		if (i == 1)
			dp[i] = num[i];
		else if (i == 2)
		{
			dp[i] = num[1] + num[2];
			tempmax = dp[1] < dp[2] ? 0 : dp[1];
		}
		else
		{
			tempmax = maxv(tempmax, maxv(dp[i - 2], dp[i - 3] + num[i - 1]));
			dp[i] = maxv(tempmax + num[i], dp[i - 1]);
		}
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d", max);
	
	free(num);
	free(dp);
}