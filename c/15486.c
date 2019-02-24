#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;
typedef struct consult {
	ll day, pay;
} consult;
__inline ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	ll n, ans = 0, dp[1500002] = { 0 };
	consult cons[1500002] = { 0 };
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%lld %lld", &cons[i].day, &cons[i].pay);
	
	for (i = 1; i <= n + 1; i++)
	{
		ans = max(ans, dp[i]);
		int mday = i + cons[i].day;
		if (mday <= n + 1)
		{
			dp[mday] = max(dp[mday], ans + cons[i].pay);
		}
	}
	printf("%lld", ans);
}