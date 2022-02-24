//20180830

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct coord {
	char x, y;
} coord;

int n, m;
char map[101][101];

#define push(a, b) {queue[i].y=a;queue[i++].x=b;visit[a][b]=1;} //(y, x) 순서
__inline int check(int y, int x)
{
	if (0 < y && y <= n && 0 < x && x <= m && map[y][x])
		return 1;
	else
		return 0;
}

int bfs()
{
	coord queue[10020] = { 0 };
	int dep = 1, i = 1, start = 1, end = 1; //깊이, 큐의 맨 끝 인덱스
	char visit[101][101] = { 0 };

	push(1, 1);
	while (1)
	{
		for (int j = start; j <= end; j++)
		{
			char tx = queue[j].x, ty = queue[j].y;
			if (ty == n && tx == m)
				return dep;

			if (check(ty - 1, tx) && !visit[ty - 1][tx])
				push(ty - 1, tx)
			if (check(ty, tx + 1) && !visit[ty][tx + 1])
				push(ty, tx + 1)
			if (check(ty + 1, tx) && !visit[ty + 1][tx])
				push(ty + 1, tx)
			if (check(ty, tx - 1) && !visit[ty][tx - 1])
				push(ty, tx - 1)
		}
		start = end + 1;
		end = i - 1;
		dep++;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		char temp[101];
		scanf("%s", temp);
		for (j = 1; j <= m; j++)
			map[i][j] = temp[j - 1] - '0';
	}

	printf("%d", bfs());
}