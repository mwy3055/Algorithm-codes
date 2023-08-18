#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coord {
	char x, y;
} coord;

char map[100][100];

#define push(a,b) {q[++qidx].y=a;q[qidx].x=b;v[a][b]=1;size++;}

int bfs(char, int);
void bfsexe(char(*v)[100], int, int, int,char);
int chk(int, int, int);

int main()
{
	int n, max = -1;
	int i, j;
	char height[101] = { 1 }, hmax = -1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%hhd", *(map + i) + j);
			height[map[i][j]] = 1;
			if (hmax < map[i][j])
				hmax = map[i][j];
		}

	for (i = 0; i <= hmax; i++)
	{
		if (height[i])
		{
			int temp = bfs(i,n);
			if (max < temp) max = temp;
		}
	}

	printf("%d", max);
}

int bfs(char h, int n)
{
	int i, j, cnt = 0;
	char visit[100][100] = { 0 };

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (map[i][j] > h && !visit[i][j])
			{
				bfsexe(visit, i, j, n, h);
				cnt++;
			}
		}

	return cnt;
}

void bfsexe(char(*v)[100], int i, int j, int n,char h)
{
	int qidx = 0, sidx = 1, size = 0;
	coord q[10001];
	push(i, j);

	while (size)
	{
		char tx = q[sidx].x, ty = q[sidx].y;
		size--;
		//상하좌우에 대해 조건 체크
		//1. 지도 안인가?
		//2. 높이 h에 대해 탐색할 때 아직 방문하지 않았는가?
		//3. 높이가 더 높은가?
		//위 두 조건을 만족시키면 큐에 넣는다.
		if (chk(ty + 1, tx, n) && v[ty + 1][tx] == 0 && map[ty+1][tx]>h)
			push(ty + 1, tx);
		if (chk(ty - 1, tx, n) && v[ty - 1][tx] == 0 && map[ty-1][tx]>h)
			push(ty - 1, tx);
		if (chk(ty, tx - 1, n) && v[ty][tx - 1] == 0 && map[ty][tx-1]>h)
			push(ty, tx - 1);
		if (chk(ty, tx + 1, n) && v[ty][tx + 1] == 0 && map[ty][tx+1]>h)
			push(ty, tx + 1);
		sidx++;
	}
}

int chk(int i, int j, int n)
{
	if (0 <= i && i < n && 0 <= j && j < n)
		return 1;
	else
		return 0;
}

//비가 하나도 안 올 수도 있다..
//qidx: 명목사이즈(큐에 지금까지 들어간 좌표의 수)
//sidx: 검사하는 인덱스
//size: 실질사이즈(들어간 좌표의 수-pop한 좌표의 수)