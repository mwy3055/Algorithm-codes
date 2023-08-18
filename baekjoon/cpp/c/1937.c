#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int bamboo[500][500];
int dp[500][500];
int n;

__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}
__inline int isin(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return 1;
	else
		return 0;
}

int dfs(int y, int x)
{
	if (dp[y][x]) return dp[y][x];
	int temp = 0;
	int tox[4] = { 0, 0, -1, 1 };
	int toy[4] = { 1, -1, 0 , 0 };

	for (int i = 0; i < 4; i++)
	{
		int gox = x + tox[i], goy = y + toy[i];
		if (isin(goy, gox) && bamboo[y][x] < bamboo[goy][gox])
			temp = maxv(temp, dfs(goy, gox));
	}

	return dp[y][x] = temp + 1;
}

int main()
{
	int i, j;
	int max = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &bamboo[i][j]);

	// ... so what?
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			max = maxv(max, dfs(i, j));

	printf("%d", max);
}