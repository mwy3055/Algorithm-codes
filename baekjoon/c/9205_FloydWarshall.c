#define _CRT_SECURE_NO_WARNINGS

//경로 유무를 찾는 플로이드 와샬.
//거리가 1000 이하인 정점들 사이에만 간선을 놓고, 출발점에서 도착점까지 이동 가능한지를 판별하자.


typedef struct coord {
	int x, y;
} coord;

#include <stdio.h>
#include <stdlib.h>

__inline int ABS(int a)
{
	return a > 0 ? a : -a;
}

char* FloydWarshall(int);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%s\n", FloydWarshall(n));
	}
}

char* FloydWarshall(int n)
{
	int i, j, k;
	coord* node = (coord*)calloc(n + 2, sizeof(coord)); //좌표저장
	char** d = (char**)calloc(n + 2, sizeof(char*)); //연결여부
	for (i = 0; i < n + 2; i++)
	{
		*(d + i) = (char*)calloc(n + 2, sizeof(char));
		scanf("%d %d", &node[i].x, &node[i].y);
	}

	for (i = 0; i < n + 2; i++)
	{
		for (j = 0; j < n + 2; j++)
		{
			if (ABS(node[i].x - node[j].x) + ABS(node[i].y - node[j].y) <= 1000)
				d[i][j] = d[j][i] = 1;
		}
	}

	for (k = 0; k < n + 2; k++)
	{
		for (i = 0; i < n + 2; i++)
		{
			for (j = 0; j < n + 2; j++)
			{
				if (d[i][j]) continue;
				else d[i][j] = d[i][k] & d[k][j];
			}
		}
	}

	char* rtn = d[0][n + 1] ? "happy" : "sad";

	free(node);
	for (i = 0; i < n + 2; i++)
		free(*(d + i));

	return rtn;
}