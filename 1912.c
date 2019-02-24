#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxv(a,b) (((a)>(b))?(a):(b))

typedef struct dp {
	char check; //1이면 계산된 것
	int val; //부분합은 short의 한도보다 커질 수 있으므로..
} DP;

int arr[100000]; //인덱스=(수-1)
DP dp[100000];

int maxsub(int i)
{
	if (dp[i].check)
		return dp[i].val;
	//else
	dp[i].check = 1;
	return dp[i].val = maxv(0, maxsub(i - 1)) + arr[i];
}

int main()
{
	int n, max, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);

	max = dp[0].val = arr[0];
	dp[0].check = 1;

	for (i = 1; i < n; i++)
		max = maxv(maxsub(i), max);

	printf("%d", max);
}