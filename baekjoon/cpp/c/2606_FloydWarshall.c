#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int FloydWarshall(int, int);

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	printf("%d",FloydWarshall(v, e));
}

int FloydWarshall(int v, int e)
{
	int count = 0;
	int i, j, k;
	char** d = (char**)calloc(v, sizeof(char*));
	for (i = 0; i < v; i++)
	{
		*(d + i) = (char*)calloc(v, sizeof(char));
		d[i][i] = 1;
	}

	while (e--)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		d[from - 1][to - 1] = d[to - 1][from - 1] = 1;
	}

	for (k = 0; k < v; k++)          //거쳐가는 점
	{
		for (i = 0; i < v; i++)      //출발점
		{
			for (j = 0; j < v; j++)  //도착점
			{
				if (d[i][j])
					continue;
				else
					d[i][j] = d[i][k] & d[k][j];
			}
		}
	}

	for (i = 1; i < v; i++)
	{
		if (d[0][i])
			count++;
	}

	for (i = 0; i < v; i++)
		free(*(d + i));

	return count;
}