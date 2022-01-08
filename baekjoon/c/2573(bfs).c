#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define push(a,b) {q[++qidx].y=a;q[qidx].x=b;size++;visit[a][b]=1;}
#define search(a,b) {if(chk(a,b) && !visit[a][b]){if (map[a][b] > 0)push(a, b)else if(map[ty][tx]){map[ty][tx]--;if(!map[ty][tx])siz--;}}}

typedef struct coord {
	short x, y;
} coord;

int n, m, siz = 0;
char map[300][300];

int bfsexe();
int bfs(int, int);
int chk(int, int);

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		for (j = 0; j < m; j++)
		{
			scanf("%hhd", *(map + i) + j);
			if (map[i][j])
				siz++;
		}
	printf("%d", bfsexe());
}

int bfsexe()
{
	int i, j, year = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (map[i][j])
			{
				int tempsize = siz; //탐색해야 할 좌표의 수
				if (tempsize!=bfs(i,j))
					return year;
				year++;
			}
		}
	}
	return 0;
}

int bfs(int i, int j)
{
	coord q[10001]; //빙산이 있는 점은 최대 10000개 주어지므로..
	char visit[300][300] = { 0 };
	int qidx = 0, size = 0, sidx = 1;
	push(i, j)
	while (size)
	{
		int tx = q[sidx].x, ty = q[sidx].y;
		size--;
		search(ty - 1, tx);
		search(ty + 1, tx);
		search(ty, tx - 1);
		search(ty, tx + 1);

		sidx++;
	}
	return qidx; //탐색한 좌표의 수
}

int chk(int i, int j)
{
	if (0 <= i && i < n && 0 <= j && j < m)
		return 1;
	else
		return 0;
}

//search: (ty,tx)의 상하좌우 점을 검사. 조건에 따라 {큐에 삽입} 
//                                             또는 {map[ty][tx] 값을 1씩 깎음} 
//                                             또는 {아무것도 하지 않음}