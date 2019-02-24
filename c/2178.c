#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct coord { //좌표쌍. 큐를 이 형식으로 선언한다
	char x, y;
} pos;

char maze[101][101];
int n, m;

int bfs();
int bfschk(int i, int j,char (*visit)[101]) 
{
	//배열 안이고, 이동할 수 있으며, 아직 안 가본 칸인가?
	if (((i > 0 && i <= n) && (j > 0 && j <= m)) && maze[i][j] && visit[i][j]==0)
		return 1;
	else
		return 0;
}
#define push_q(a,b) {queue[++qidx].y=a;queue[qidx].x=b;} //큐에 넣기

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		char temp[101];
		scanf("%s", temp);
		//파싱
		for (int j = 1; j <= m; j++)
			maze[i][j] = temp[j - 1] - '0';
	}
	printf("%d", bfs());
}

int bfs()
{
	char visit[101][101] = { 0 }; //방문 체크. 1이면 이미 방문된 것
	pos queue[1000] = { 0 }; //인덱스 1번부터 저장
	int dep = 0, qidx = 0;

	push_q(1, 1);
	visit[1][1] = 1;
	//(1,1)부터 시작한다.
	while (++dep)
	{
		//처음 큐 개수
		int temp = qidx;

		for (int i = 1; i <= temp; i++)
		{
			//큐에서 pop
			int x = queue[i].x, y = queue[i].y;
			visit[y][x] = 1;

			//(n,m)을 꺼냈다면
			if (y == n && x == m)
				return dep;

			//상하좌우 체크
			if (bfschk(y + 1, x, visit))
				push_q(y + 1, x);
			if (bfschk(y - 1, x, visit))
				push_q(y - 1, x);
			if (bfschk(y, x - 1, visit))
				push_q(y, x - 1);
			if (bfschk(y, x + 1, visit))
				push_q(y, x + 1);
		}

		//큐에 새로 추가된 원소 (qidx-temp)개를 옮긴다.
		memcpy(queue + 1, queue + temp + 1, (qidx - temp) * sizeof(pos));
		qidx -= temp;
	}
}