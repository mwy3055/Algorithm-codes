#define _CRT_SECURE_NO_WARNINGS
//큐는 최대 102개 필요
#include <stdio.h>

typedef struct coord {
	int x, y, no;
} coord;

#define push(a) {q[++ridx]=a;size++;visit[a]=1;}
__inline int abs(int a)
{
	return a > 0 ? a : -a;
}
char* bfs();

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		printf("%s\n",bfs());
	}
}

char* bfs()
{
	int n, sidx = 1, size = 0, ridx = 0; //탐색인덱스 실질사이즈 맨끝인덱스
	int i, j;
	scanf("%d", &n);
	coord point[102] = { 0 };
	int q[103] = { 0 };
	char visit[102] = { 0 };
	char cnt[102][102] = { 0 };
	for (i = 0; i < n + 2; i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
		point[i].no = i;
	}

	for (i = 0; i < n + 2; i++)
	{
		for (j = 0; j < n + 2; j++)
		{
			if (abs(point[i].x - point[j].x) + abs(point[i].y - point[j].y) <= 1000)
				cnt[i][j] = cnt[j][i] = 1;
		}
	}

	push(0)
	while (size)
	{
		int ti = q[sidx];
		size--;
		for (i = 0; i < n + 2; i++)
		{
			if (cnt[ti][i] && !visit[i])
			{
				if (i == n + 1)
					return "happy";
				else
					push(i)
			}
		}
		sidx++;
	}
	return "sad";
}