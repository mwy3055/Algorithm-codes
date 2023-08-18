#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int tile[1001][1001];//인덱스=수

int max(int, int);

int main()
{
	int n, m, i, j, k;
	scanf("%d %d", &m, &n);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &tile[i][j]);
/*	printf("가로 %d 세로 %d\n", n, m);
	printf("%d\n", tile[m][n]);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", tile[i][j]);
		}
		printf("\n");
	}*/
	for (i = 1; i <= m - 1; i++) //맨 오른쪽 세로줄
		for (k = i + 1; k <= m; k++)
			tile[i][n] += tile[k][n];

	for (j = 1; j <= n - 1; j++) //맨 밑 가로줄
		for (k = j + 1; k <= n; k++)
			tile[m][j] += tile[m][k];

	for (i = m - 1; i >= 1; i--)
		for (j = n - 1; j >= 1; j--)
			tile[i][j] += max(max(tile[i + 1][j], tile[i][j + 1]), tile[i + 1][j + 1]);
/*	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", tile[1][1]);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
//인덱스=(수-1)도 가능. 제출번호 8740487.
//25~31라인 생략 가능->배열 크기 1씩 늘려야 함. 제출번호 8740510.