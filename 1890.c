#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

int arr[101][101];
long long ans[101][101]; //DFS + DP

long long dp(int x, int y, int n)
{
	if (ans[y][x] != 0)
		return ans[y][x];
	if (x == n && y == n)
		return 1;
	else if (arr[y][x] == 0)
		return 0;

	long long temp = 0;
	if (x + arr[y][x] <= n && y + arr[y][x] > n)
	{
		temp+=dp(x + arr[y][x], y, n);
	}
	else if (x + arr[y][x] > n && y + arr[y][x] <= n)
	{
		temp+=dp(x, y + arr[y][x], n);
	}
	else
	{
		temp+=dp(x + arr[y][x], y, n);
		temp+=dp(x, y + arr[y][x], n);
	}
	return ans[y][x] = temp;
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	printf("%lld", dp(1, 1, n));
}