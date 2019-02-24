#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define push(a,b) {q[++qidx].y=a;q[qidx].x=b;visit[a][b]=tomato[a][b]=1;left--;}

typedef struct coord {
	int x, y;
} coord;

char tomato[1001][1001], visit[1001][1001];
int m, n, left;

int ispush(int y, int x, char k)
{
	if ((y > 0 && y <= n && x > 0 && x <= m) && tomato[y][x] == k && visit[y][x] == 0)
		return 1;
	else
		return 0;
}

int bfs()
{
	int day = 0, qidx = 0;
	int i, j;
	coord* q = (coord*)calloc(500000, sizeof(coord));
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (ispush(i, j, 1))
			{
				push(i, j)
			}
		}
	while (qidx)
	{
		int tqi = qidx;
		for (i = 1; i <= tqi; i++)
		{
			int tx = q[i].x, ty = q[i].y;
			if (ispush(ty, tx + 1, 0))
				push(ty, tx + 1)
			if (ispush(ty, tx - 1, 0))
				push(ty, tx - 1)
			if (ispush(ty + 1, tx, 0))
				push(ty + 1, tx)
			if (ispush(ty - 1, tx, 0))
				push(ty - 1, tx)
		}
		memmove(q + 1, q + tqi + 1, (qidx - tqi) * sizeof(coord));
		qidx -= tqi;
		if (qidx) day++;
	}

	free(q);
	if (left)
		return -1;
	else
		return day;
}

int main()
{
	int i, j;
	scanf("%d %d", &m, &n);
	left = m * n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%hhd", &tomato[i][j]);
			if (-1 == tomato[i][j])
				left--;
		}
	printf("%d", left ? bfs() : 0);
}