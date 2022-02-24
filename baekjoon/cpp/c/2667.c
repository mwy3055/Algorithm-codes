#define _CRT_SECURE_NO_WARNINGS
//테스트 케이스로 디버깅할것
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define push_q(a,b) {q[++size].y=a;q[size].x=b;cnt++;visit[a][b]=1;}
#define clean_q(s) {q[s+1].y=0;q[s+1].x=0;}
typedef struct coord {
	int y, x;
} coord;

char map[25][25], visit[25][25];
int n;

int cmp(short* a,short* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int chk(int i, int j) //탐색해야 하는가?
{
	if (i >= 0 && i < n && j >= 0 && j < n && map[i][j] && (visit[i][j]==0))
		return 1;
	else
		return 0;
}

int bfs(int i, int j) //y좌표 x좌표
{
	int cnt = 0, size = 0;
	coord q[650] = { 0 }; //1번부터 쓴다.
	push_q(i, j);
	while (size)
	{
		int x = q[1].x, y = q[1].y;
		memmove(q + 1, q + 2, --size * sizeof(coord));
		clean_q(size);

		if (chk(y + 1, x))
			push_q(y + 1, x);
		if (chk(y - 1, x))
			push_q(y - 1, x);
		if (chk(y, x - 1))
			push_q(y, x - 1);
		if (chk(y, x + 1))
			push_q(y, x + 1);
	}
	return cnt;
}

int main()
{
	int i, j;
	short house[400], idx = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char temp[26];
		scanf("%s", temp);
		for (j = 0; j < n; j++)
			map[i][j] = temp[j] - '0';
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (map[i][j] && visit[i][j] == 0)
				house[++idx] = bfs(i, j);
		}
	}
	qsort(house+1, idx, sizeof(short), cmp);
	//동 수
	printf("%d\n", idx); 
	//집 수(오름차순)
	for (i =1; i <= idx; i++)
		printf("%d\n", house[i]);
}