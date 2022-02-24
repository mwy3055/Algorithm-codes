#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int val(int, int,int*);
int dp[100][10001];	//방문 안 한 곳은 -1, 방문했지만 값이 0인 곳은 0 -> 둘 다 한번에 처리하자.
int overzero(int i, int j)
{
	return dp[i][j] > 0 ? 1 : 0;
}
int main()
{
	int n, k, coin[100], min = 1 << 30;
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", coin + i);

	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= k; j++)
		{
			dp[i][j] = val(i, j, coin);
		}

/*		for (j = 1; j <= k; j++)
			printf("%2d ", dp[i][j]);
		printf("\n");*/

		if (overzero(i,k) && dp[i][k] < min)
			min = dp[i][k];
	}

	if (min == 1 << 30)
		printf("-1");
	else
		printf("%d", min);
}

int val(int i, int j, int* coin)
{
	int temp = 1 << 30;
	if (i > 0)
	{
		if (j >= coin[i] && overzero(i,j-coin[i]) && dp[i][j-coin[i]]+1<temp)
			temp = dp[i][j - coin[i]] + 1;

		if (overzero(i - 1, j) && dp[i - 1][j] < temp)
			temp = dp[i - 1][j];
	}
	if (j%coin[i] == 0 && j / coin[i] < temp) //i번째 동전만으로 가능한 경우.. || i==0
		temp = j / coin[i];
	return temp == 1 << 30 ? 0 : temp;
}