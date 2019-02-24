#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct coord { //��ǥ��. ť�� �� �������� �����Ѵ�
	char x, y;
} pos;

char maze[101][101];
int n, m;

int bfs();
int bfschk(int i, int j,char (*visit)[101]) 
{
	//�迭 ���̰�, �̵��� �� ������, ���� �� ���� ĭ�ΰ�?
	if (((i > 0 && i <= n) && (j > 0 && j <= m)) && maze[i][j] && visit[i][j]==0)
		return 1;
	else
		return 0;
}
#define push_q(a,b) {queue[++qidx].y=a;queue[qidx].x=b;} //ť�� �ֱ�

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		char temp[101];
		scanf("%s", temp);
		//�Ľ�
		for (int j = 1; j <= m; j++)
			maze[i][j] = temp[j - 1] - '0';
	}
	printf("%d", bfs());
}

int bfs()
{
	char visit[101][101] = { 0 }; //�湮 üũ. 1�̸� �̹� �湮�� ��
	pos queue[1000] = { 0 }; //�ε��� 1������ ����
	int dep = 0, qidx = 0;

	push_q(1, 1);
	visit[1][1] = 1;
	//(1,1)���� �����Ѵ�.
	while (++dep)
	{
		//ó�� ť ����
		int temp = qidx;

		for (int i = 1; i <= temp; i++)
		{
			//ť���� pop
			int x = queue[i].x, y = queue[i].y;
			visit[y][x] = 1;

			//(n,m)�� ���´ٸ�
			if (y == n && x == m)
				return dep;

			//�����¿� üũ
			if (bfschk(y + 1, x, visit))
				push_q(y + 1, x);
			if (bfschk(y - 1, x, visit))
				push_q(y - 1, x);
			if (bfschk(y, x - 1, visit))
				push_q(y, x - 1);
			if (bfschk(y, x + 1, visit))
				push_q(y, x + 1);
		}

		//ť�� ���� �߰��� ���� (qidx-temp)���� �ű��.
		memcpy(queue + 1, queue + temp + 1, (qidx - temp) * sizeof(pos));
		qidx -= temp;
	}
}