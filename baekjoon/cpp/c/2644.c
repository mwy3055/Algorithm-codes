#define _CRT_SECURE_NO_WARNINGS

//그래프 상의 거리계산

#include <stdio.h>
#include <string.h>
#define push_q(a) {queue[++qidx]=(char)a;visit[a]=1;}
char cnt[101][101], visit[101];

int bfs(int p, int q, int n) //출발점 도착점 사람수
{
	int dist = 0, qidx = 0;
	int i, j;
	char queue[106] = { 0 }; //1번부터 저장
	push_q(p);
	while (qidx)
	{
		dist++;		
		int tqidx = qidx;

		for (i = 1; i <= tqidx; i++)
		{
			char temp = queue[i];
			for (j = 1; j <= n; j++)
			{
				if (cnt[j][temp] && visit[j] == 0)
				{
					if (j == q)
						return dist;
					else
						push_q(j);
				}
			}
		}

		memmove(queue + 1, queue + tqidx+1, (qidx-tqidx) * sizeof(char));
		qidx -= tqidx;
	}
	return -1;
}

int main()
{
	int n, m, p1, p2;
	scanf("%d %d %d %d", &n, &p1, &p2,&m);
	while (m--)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		cnt[t1][t2] = cnt[t2][t1] = 1;
	}
	printf("%d", bfs(p1, p2,n));
}