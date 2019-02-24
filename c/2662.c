#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct info {
	int* amount;
} info;

int main()
{
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);

	short** profit = (short**)calloc(m + 1, sizeof(short*));
	int** dp = (int**)calloc(m + 1, sizeof(int**));
	info** inf = (info**)calloc(m + 1, sizeof(info*));
	for (i = 0; i <= m; i++)
	{
		*(profit + i) = (short*)calloc(n + 1, sizeof(short));
		*(dp + i) = (int*)calloc(n + 1, sizeof(int));
		*(inf + i) = (info*)calloc(n + 1, sizeof(info));
		for (j = 0; j <= n; j++)
		{
			inf[i][j].amount = (int*)calloc(i + 1, sizeof(int));
		}
	}

	for (i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		for (j = 1; j <= m; j++)
			scanf("%hd", &profit[j][i]);
	}


	for (i = 1; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 1)
			{
				dp[i][j] = profit[i][j];
				inf[i][j].amount[1] = j;
			}
			else
			{
				int temp = -1, tidx; //tidx: i번째 기업에 투자할 금액
				for (int k = 0; k <= j; k++)
				{
					if (temp < dp[i - 1][j - k] + profit[i][k])
					{
						temp = dp[i - 1][j - k] + profit[i][k];
						tidx = k;
					}
				}
				dp[i][j] = dp[i - 1][j - tidx] + profit[i][tidx];
				for (int k = 1; k < i; k++)
					inf[i][j].amount[k] = inf[i - 1][j - tidx].amount[k];
				inf[i][j].amount[i] = tidx;
			}
		}
	}

	printf("%d\n", dp[m][n]);
	for (i = 1; i <= m; i++)
	{
		printf("%d ", inf[m][n].amount[i]);
	}
	
	for (i = 0; i <= m; i++)
	{
		free(*(profit + i));
		free(*(dp + i));
		for (j = 0; j <= n; j++)
			free(inf[i][j].amount);
		free(*(inf + i));
	}
}