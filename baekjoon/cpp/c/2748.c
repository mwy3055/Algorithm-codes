#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

long long fbnc(long long);
long long* dp;

int main()
{
	long long n;
	scanf("%lld", &n);
	dp = (long long*)calloc(n + 1, sizeof(long long));
	printf("%lld\n", fbnc(n));
	free(dp);
}

long long fbnc(long long n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else if (dp[n] != 0)
		return dp[n];
	return dp[n] = fbnc(n - 1) + fbnc(n - 2);
}