#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define mod 1000000
#define p mod/10*15

typedef unsigned long long ull;

ull* dp;

int main()
{
	ull n;
	scanf("%lld", &n);
	/*int a = 0, b = 1, c;
	n %= p;
	while (n--)
	{
		c = (a + b) % mod;
		a = b;
		b = c;
	}
	printf("%d", a);*/
	dp = (ull*)calloc(p, sizeof(ull));
	dp[0] = 0;
	dp[1] = 1;
	for (ull i = 2; i < p; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	printf("%lld", dp[n%p]);
	free(dp);
}