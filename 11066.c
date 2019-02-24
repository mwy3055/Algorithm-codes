#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

short size[501];
int d[501][501], sum[501];

__inline int minv(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%hd", size + i);
			d[i][i] = size[i];
			if (i > 1) d[i - 1][i] = size[i - 1] + size[i];
			sum[i] = sum[i - 1] + size[i];
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (!d[i][j])
				{
					int min = 1 << 30;
					for (int t = i; t < j; t++)
					{
						min = minv(min, d[i][t] + d[t + 1][j]);
					}
					d[i][j] = sum[j] - sum[i - 1] + min;
				}
			}
		}
		printf("%d\n", d[1][k]);
	}
}

//D[i][j] = (i번째 수부터 j번째 수의 합) + min(D[i][t] + D[t+1][j]) for i ≤ t < j