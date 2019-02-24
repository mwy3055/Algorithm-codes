#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char map[50][50];
char n, m;
char y, x;
char dir;

int count;

__inline void rotate()
{
	dir = (dir + 3) % 4;
}
int ismap(int a,int b)
{
	if (0 <= a && a < n && 0 <= b && b < m)
		return 1;
	else
		return 0;
}
void dfs();
int todo();
int CheckLeft();
int CheckBack();

int main()
{
	int i, j;
	scanf("%hhd %hhd", &n, &m);
	scanf("%hhd %hhd %hhd", &y, &x, &dir);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%hhd", &map[i][j]);
	dfs();
	printf("%d", count);
}

void dfs()
{
	if (map[y][x] == 0)
	{
		count++;
		map[y][x] = -1; //û�ҵ� ĭ ǥ��
	}
	switch (todo())
	{
	case 0:
		return;
	default:
		dfs();
		return;
	}
}

int todo()
{
	for (int i = 1; i <= 4; i++)
	{
		if (CheckLeft())
			return 1;
		else
			rotate();
	}
	if (CheckBack())
		return 2;
	else
		return 0;
}

int CheckLeft()
{
	int tx, ty; //���� ������ ��ǥ
	switch (dir)
	{
	case 0:
		tx = x - 1;
		ty = y;
		break;
	case 1:
		tx = x;
		ty = y - 1;
		break;
	case 2:
		tx = x + 1;
		ty = y;
		break;
	case 3:
		tx = x;
		ty = y + 1;
		break;
	}
	if (ismap(ty, tx) && map[ty][tx]==0)
	{
		x = tx;
		y = ty;	
		rotate();
		return 1; //û���Ϸ� ������
	}
	else
		return 0; //ȸ��
}

int CheckBack()
{
	int tx, ty; //�� ������ ��ǥ
	switch (dir)
	{
	case 0:
		tx = x;
		ty = y + 1;
		break;
	case 1:
		tx = x - 1;
		ty = y;
		break;
	case 2:
		tx = x;
		ty = y - 1;
		break;
	default:
		tx = x + 1;
		ty = y;
		break;
	}
	if (ismap(ty, tx) && map[ty][tx] != 1)
	{
		x = tx;
		y = ty;	
		return 1; //�ڷ� ������
	}
	else
		return 0; //�۵� ����
}