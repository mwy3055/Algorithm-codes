#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fbnc(int);
int slowfbnc(int); //심심해서..
int* dp;

int main()
{
	time_t t1 = 0, t2 = 0;
	int n;
	scanf("%d", &n);
	dp = (int*)calloc(n+1, sizeof(int));
	t1 = clock();
	printf("%d\n", fbnc(n));
	t2 = clock();
	printf("time:%lldms\n", t2 - t1);
	t1 = clock();
	printf("%d\n", slowfbnc(n));
	t2 = clock();
	printf("slow time:%lldms\n", t2 - t1);

	free(dp);
}

int fbnc(int n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else if (dp[n] != 0)
		return dp[n];
	return dp[n] = fbnc(n - 1) + fbnc(n - 2);
}

int slowfbnc(int n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else
		return slowfbnc(n - 1) + slowfbnc(n - 2);
}