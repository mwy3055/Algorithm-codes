#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define minv(a,b) (((a)<(b))?(a):(b))
int dp[1000][3], val[1000][3]; //0�̸� Ž�� �� �� ��, R G B-0 1 2, dp[i][j]�� i��° ���� j������ ĥ���� �� �� ����� �ּڰ�

int f(int i, int j) //DFS + �޸������̼�. dp�� �Ʒ��� �������� �Լ��� ������
{
	if (dp[i][j])
		return dp[i][j];
	return dp[i][j] = minv(f(i + 1, (j + 1) % 3), f(i + 1, (j + 2) % 3)) + val[i][j];
}

int main()
{
	int n, min = 1 << 30;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
		{
			scanf("%d", *(val + i) + j);
			if (i == n - 1) //������ ��.
				dp[i][j] = val[i][j];
		}
	for (i = 0; i < 3; i++)
	{
/*		dp[0][i] = f(0, i);
		if (dp[0][i] < min)
			min = dp[0][i];*/
		if ((dp[0][i] = f(0, i)) < min)
			min = dp[0][i];
	}
	printf("%d", min);
}