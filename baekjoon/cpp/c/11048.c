#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int tile[1001][1001];//�ε���=��

int max(int, int);

int main()
{
	int n, m, i, j, k;
	scanf("%d %d", &m, &n);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &tile[i][j]);
/*	printf("���� %d ���� %d\n", n, m);
	printf("%d\n", tile[m][n]);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", tile[i][j]);
		}
		printf("\n");
	}*/
	for (i = 1; i <= m - 1; i++) //�� ������ ������
		for (k = i + 1; k <= m; k++)
			tile[i][n] += tile[k][n];

	for (j = 1; j <= n - 1; j++) //�� �� ������
		for (k = j + 1; k <= n; k++)
			tile[m][j] += tile[m][k];

	for (i = m - 1; i >= 1; i--)
		for (j = n - 1; j >= 1; j--)
			tile[i][j] += max(max(tile[i + 1][j], tile[i][j + 1]), tile[i + 1][j + 1]);
/*	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", tile[1][1]);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
//�ε���=(��-1)�� ����. �����ȣ 8740487.
//25~31���� ���� ����->�迭 ũ�� 1�� �÷��� ��. �����ȣ 8740510.