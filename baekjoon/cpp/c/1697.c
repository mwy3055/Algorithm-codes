#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define push(a) {if(!visit[a] && a<=100000 && a>=0){q[++qidx]=a;visit[a]=1;}}

int bfs(int n,int k)
{
	int q[10000] = { 0 }, depth = 0, qidx = 1; //1번부터 저장
	char visit[100001] = { 0 }; //방문여부 저장. 1이면 방문한 것
	q[1] = k;
	while (qidx)
	{
		int tqi = qidx;
		for (int i = 1; i <= tqi; i++)
		{
			if (q[i] == n)
				return depth;

			push(q[i] - 1);
			push(q[i] + 1);
			if (q[i]%2==0)
				push(q[i] / 2);
		}

		memmove(q + 1, q + tqi + 1, (qidx - tqi) * sizeof(int));
		qidx -= tqi;
		depth++;
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", bfs(n,k));
}

//큐는 10000개면 충분하다.