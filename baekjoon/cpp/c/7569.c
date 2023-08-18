#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define push(a,b,c) {q[++qidx].z=a;q[qidx].y=b;q[qidx].x=c;visit[a][b][c]=tomato[a][b][c]=1;left--;} //z,y,x 순서로

typedef struct coord {
	char x, y, z;
} coord;

char tomato[101][101][101], visit[101][101][101]; //1이면 방문
int m, n, h, left; //토마토가 익지 않은 칸의 수. 토마토가 없는 칸은 제외한다.

int ispush(int z, int y, int x, int k)
{
	if ((z > 0 && z <= h && y > 0 && y <= n && x > 0 && x <= m) && tomato[z][y][x] == k && visit[z][y][x] == 0)
	{
		printf("push:%d %d %d\n", z, y, x);
		return 1;
	}
	else
		return 0;
}

int bfs()
{
	int day = 0;
	int i, j, k, qidx = 0;
	coord q[10000] = { 0 }; //1번부터 저장

	//초기 상태: 익은 곳의 좌표를 저장하자.
	for (i = 1; i <= h; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= m; k++)
			{
				if (ispush(i, j, k,1))
				{
					push(i, j, k);
				}
			}
	while (qidx)
	{
		int tqi = qidx;
		for (i = 1; i <= tqi; i++)
		{
			int tx = q[i].x, ty = q[i].y, tz = q[i].z;
			//6방향확인: 익지 않은 곳으로 퍼져나가야.
			if (ispush(tz + 1, ty, tx, 0))
				push(tz + 1, ty, tx);
			if (ispush(tz - 1, ty, tx, 0))
				push(tz - 1, ty, tx);
			if (ispush(tz, ty, tx + 1, 0))
				push(tz, ty, tx + 1);
			if (ispush(tz, ty, tx - 1, 0))
				push(tz, ty, tx - 1);
			if (ispush(tz, ty + 1, tx, 0))
				push(tz, ty + 1, tx);
			if (ispush(tz, ty - 1, tx, 0))
				push(tz, ty - 1, tx);
		}

		memmove(q + 1, q + tqi + 1, (qidx - tqi) * sizeof(coord));
		qidx -= tqi;

		if (qidx) day++;
	}

	if (left)
		return -1;
	else
		return day;
}

int main()
{
	int i, j, k;
	scanf("%d %d %d", &m, &n, &h);
	left = m * n*h;
	for (i = 1; i <= h; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= m; k++)
			{
				scanf("%hhd", &tomato[i][j][k]);
				if (-1 == tomato[i][j][k])
					left--;
			}
	printf("%d", left ? bfs():0);
}

//좌표 범위가 2~100이기 때문에 좌표의 자료형은 char로 충분하다.