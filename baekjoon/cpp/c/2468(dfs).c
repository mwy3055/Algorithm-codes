#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char map[100][100], hmax = -1;
int n;

int chk(int, int, int, char (*v)[100]);
int dfs(int, int);
void dfsexe(int, int, int, char(*v)[100]);

int main()
{
	int max = -1;
	int i, j;
	char height[101] = { 1 };
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
//			printf("limit height=%d\n", i);
			int temp = dfs(i, n);
			if (max < temp) max = temp;
		}
	}

	printf("%d", max);
}

int dfs(int h, int n) //탐색중인 높이, map 크기
{
	int cnt = 0;
	char visit[100][100] = { 0 };
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (chk(i, j, h,visit))
			{
				dfsexe(i, j, h,visit);
				cnt++;
			}
		}
//	printf("return:%d\n", cnt);
	return cnt;
}

void dfsexe(int i, int j, int h, char (*v)[100]) //좌표, 탐색중인 높이
{
//	printf("now searching:%d %d\n", i, j);
	v[i][j] = 1;

	if (chk(i - 1, j, h,v))
		dfsexe(i - 1, j, h,v);
	if (chk(i + 1, j, h,v))
		dfsexe(i + 1, j, h,v);
	if (chk(i, j - 1, h,v))
		dfsexe(i, j - 1, h,v);
	if (chk(i, j + 1, h,v))
		dfsexe(i, j + 1, h,v);

	return;
}

int chk(int i, int j, int h, char (*v)[100])
{
	if (0 <= i && i < n && 0 <= j && j < n && map[i][j]>h && !v[i][j])
		return 1;
	else
		return 0;
}

//bfs보다 오래걸린다?