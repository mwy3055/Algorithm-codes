#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char map[1000][1000];
int profit[1000][1000]; //이 칸에서 끝까지 갈 때 얻는 최대의 이익

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%hhd", &map[i][j]);

	for (i = n - 1; i >= 0; i--)
	{
		for (j = m - 1; j >= 0; j--)
		{
			if (i == n - 1 && j == m - 1)
				profit[i][j] = map[i][j];
			else if (i == n - 1)
				profit[i][j] = map[i][j] + profit[i][j + 1];
			else
			{
				//what to do
			}
		}
	}
	printf("%d", profit[0][0]);
}