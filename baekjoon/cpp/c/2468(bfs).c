#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coord {
	char x, y;
} coord;

char map[100][100];

#define push(a,b) {q[++qidx].y=a;q[qidx].x=b;v[a][b]=1;size++;}

int bfs(char, int);
void bfsexe(char(*v)[100], int, int, int,char);
int chk(int, int, int);

int main()
{
	int n, max = -1;
	int i, j;
	char height[101] = { 1 }, hmax = -1;
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
			int temp = bfs(i,n);
			if (max < temp) max = temp;
		}
	}

	printf("%d", max);
}

int bfs(char h, int n)
{
	int i, j, cnt = 0;
	char visit[100][100] = { 0 };

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (map[i][j] > h && !visit[i][j])
			{
				bfsexe(visit, i, j, n, h);
				cnt++;
			}
		}

	return cnt;
}

void bfsexe(char(*v)[100], int i, int j, int n,char h)
{
	int qidx = 0, sidx = 1, size = 0;
	coord q[10001];
	push(i, j);

	while (size)
	{
		char tx = q[sidx].x, ty = q[sidx].y;
		size--;
		//�����¿쿡 ���� ���� üũ
		//1. ���� ���ΰ�?
		//2. ���� h�� ���� Ž���� �� ���� �湮���� �ʾҴ°�?
		//3. ���̰� �� ������?
		//�� �� ������ ������Ű�� ť�� �ִ´�.
		if (chk(ty + 1, tx, n) && v[ty + 1][tx] == 0 && map[ty+1][tx]>h)
			push(ty + 1, tx);
		if (chk(ty - 1, tx, n) && v[ty - 1][tx] == 0 && map[ty-1][tx]>h)
			push(ty - 1, tx);
		if (chk(ty, tx - 1, n) && v[ty][tx - 1] == 0 && map[ty][tx-1]>h)
			push(ty, tx - 1);
		if (chk(ty, tx + 1, n) && v[ty][tx + 1] == 0 && map[ty][tx+1]>h)
			push(ty, tx + 1);
		sidx++;
	}
}

int chk(int i, int j, int n)
{
	if (0 <= i && i < n && 0 <= j && j < n)
		return 1;
	else
		return 0;
}

//�� �ϳ��� �� �� ���� �ִ�..
//qidx: ��������(ť�� ���ݱ��� �� ��ǥ�� ��)
//sidx: �˻��ϴ� �ε���
//size: ����������(�� ��ǥ�� ��-pop�� ��ǥ�� ��)