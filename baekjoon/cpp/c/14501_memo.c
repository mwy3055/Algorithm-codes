#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct consult {
	int day, pay;
} consult;
__inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, ans = 0, dp[17] = { 0 };
	consult cons[17] = { 0 };
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &cons[i].day, &cons[i].pay);
		ans = max(ans, dp[i]);
		int mday = i + cons[i].day;
		if (mday <= n + 1)
		{
			dp[mday] = max(dp[mday], ans + cons[i].pay);
		}
	}

	ans = max(ans, dp[n + 1]);

	printf("%d", ans);
}