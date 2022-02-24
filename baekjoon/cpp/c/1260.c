#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char graph[1001][1001] = { 0 }; //1�̸� ���������
char chk[1001] = { 0 }; //����=�ε���
int odr[1001] = { 0 };
int idx;

void dfs(int, int);
void bfs(int, int);

int main()
{
	int n, m, v, i;
	scanf("%d %d %d", &n, &m, &v);
	for (i = 0; i < m; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		graph[n1][n2] = graph[n2][n1] = 1;
	}
	//DFS ����
	idx = 0;
	dfs(v, n);
	for (i = 0; i < idx; i++)
	{
		printf("%d", odr[i]);
		odr[i] = chk[i + 1] = 0;
		if (i < idx - 1)
			printf(" ");
	}
	printf("\n");
	//DFS ����
	
	//BFS ����
	idx = 0;
	bfs(v, n);
	for (i = 0; i < idx; i++)
	{
		printf("%d", odr[i]);
		if (i < idx - 1)
			printf(" ");
	}
	//BFS ����
}

void dfs(int v, int n)
{
	odr[idx++] = v;
	chk[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (chk[i] == 0 && graph[v][i] == 1)
			dfs(i, n);
	}
}

void bfs(int v, int n)
{
	int q[1001] = { 0 }, qidx = 0, m; //ť�� 1������ ����
	q[++qidx] = v;
	while (idx < n)
	{
		//�湮����
		chk[v] = 1;
		
		//pop
		m = q[1];
		memmove(q + 1, q + 2, qidx * sizeof(int));
		q[qidx--] = 0;
		odr[idx++] = m;

		//ť�� ����.
		for (int i = 1; i <= n; i++)
		{
			if (chk[i] == 0 && graph[m][i] == 1)
			{
				q[++qidx] = i;
				chk[i] = 1;
			}
		}
		v = q[1];


	/*	printf("ť:");
		for (int i = 1; i <= n; i++)
			printf("%d ", q[i]);
		printf("\n");*/
	}
}