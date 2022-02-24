#define _CRT_SECURE_NO_WARNINGS
//DFS

#include <stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))

char visit[101], line[101][101], parent[101]; //规巩眉农, 牢立青纺, 何葛 历厘

void dfs(int i, int n)
{
	visit[i] = 1;
	for (int j = 1; j <= n; j++)
	{
		if (line[i][j] && visit[j] == 0)
		{
			parent[i] = parent[j] = min(parent[i], parent[j]);
			dfs(j, n);
		}
	}
}

int main()
{
	int n, m, cnt = 0;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		line[b][a] = line[a][b] = 1;
	}
	dfs(1, n);
	for (i = 2; i <= n; i++)
	{
		if (1 == parent[i])
			cnt++;
	}
	printf("%d", cnt);
}