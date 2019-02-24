#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define push(a) {q[++qidx]=a;visit[a]=1;}

int f, s, g, u, d; //총 층수 시작층수 목표층수 위로 아래로

int ispush(char* visit,int i)
{
	if (1 <= i && i <= f && !visit[i])
		return 1;
	else
		return 0;
}

int bfs()
{
	char* visit = (char*)calloc(f + 1, sizeof(char)); //방문여부 체크
	int* q = (int*)calloc(1000001, sizeof(int));
	int qidx = 0, depth = 0;
	push(s);

	while (qidx)
	{
		int tqi = qidx;
		for (int i = 1; i <= tqi; i++)
		{
			if (q[i] == g)
				return depth;

			if (ispush(visit, q[i] + u))
				push(q[i] + u);
			if (ispush(visit, q[i] - d))
				push(q[i] - d);
		}
		memmove(q + 1, q + tqi + 1, (qidx - tqi) * sizeof(int));
		qidx -= tqi;






		depth++;
	}
	free(visit);
	free(q);
	return -1;
}

int main()
{
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	int temp = bfs();
	if (temp>=0)
		printf("%d", temp);
	else
		printf("use the stairs");
}

//아주 전형적인 bfs