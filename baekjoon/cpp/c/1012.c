#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct coord {
	char x, y;
} coord;
char map[50][50];
char visit[50][50];
int n, m;

#define push(a,b) {q[qidx].y=a;q[qidx++].x=b;visit[a][b]=1;}

__inline int isgo(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m && map[y][x] && !visit[y][x])
		return 1;
	else 
		return 0;
}

void bfs(int i, int j)
{
	coord q[2500];
	int qidx = 0, sidx = 0;           //Å¥ »ðÀÔ¿ë, Å¥ Å½»ö¿ë
	push(i, j);

	while (sidx < qidx)
	{
		int x = q[sidx].x, y = q[sidx].y;

		if (isgo(y - 1, x))
			push(y - 1, x);
		if (isgo(y, x + 1))
			push(y, x + 1);
		if (isgo(y + 1, x))
			push(y + 1, x);
		if (isgo(y, x - 1))
			push(y, x - 1);

		sidx++;
	}
}

int search()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

void clear()
{
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
		{
			visit[i][j] = map[i][j] = 0;
		}
}

void getinput()
{
	int k;
	scanf("%d %d %d", &m, &n, &k);
	while (k--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[y][x] = 1;
	}
}

int main()
{	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		getinput();
		printf("%d\n", search());
		clear();
	}
}