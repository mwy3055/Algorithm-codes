#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define minv(a,b) (((a)<(b))?(a):(b))
int dp[1000][3], val[1000][3]; //0이면 탐색 안 된 것, R G B-0 1 2, dp[i][j]는 i번째 집을 j색으로 칠했을 때 뒤 경우의 최솟값

int f(int i, int j) //DFS + 메모이제이션. dp의 아래로 내려가는 함수를 만들자
{
	if (dp[i][j])
		return dp[i][j];
	return dp[i][j] = minv(f(i + 1, (j + 1) % 3), f(i + 1, (j + 2) % 3)) + val[i][j];
}

int main()
{
	int n, min = 1 << 30;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
		{
			scanf("%d", *(val + i) + j);
			if (i == n - 1) //마지막 줄.
				dp[i][j] = val[i][j];
		}
	for (i = 0; i < 3; i++)
	{
/*		dp[0][i] = f(0, i);
		if (dp[0][i] < min)
			min = dp[0][i];*/
		if ((dp[0][i] = f(0, i)) < min)
			min = dp[0][i];
	}
	printf("%d", min);
}