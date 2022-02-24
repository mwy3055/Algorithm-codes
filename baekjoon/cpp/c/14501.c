#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct consult {
	int day, val;
} consult;

__inline int max(int a, int b)
{
	return a < b ? b : a;
}

int findmax(int* ar, int k)
{
	int rst = 0;
	for (int i = 1; i <= k; i++)
		rst = max(rst, ar[i]);
	return rst;
}

int main()
{
	int n, Max = 0, dp[16] = { 0 };
	consult cons[16];
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &cons[i].day, &cons[i].val);

	for (i = 1; i <= n; i++)
	{
		int prev = findmax(dp, i - 1);                        //prev: ����ϱ� �� �������� �ִ� ����
		for (j = i; j <= n;)
		{
			int endday = j + cons[j].day - 1;                 //����� ������ ��
			if (endday > n)
				break;
			dp[endday] = max(dp[endday], prev + cons[j].val); //�������� �� �� ��
			prev = dp[endday];                                //for�� �ȿ����� ���� �ִ� ����
			Max = max(Max, prev);                             //dp �ִ� ����
			j += cons[j].day;                                 //���� ����Ϸ� ����.
		}
	}

	printf("%d", Max);
}

//day=1�� �� ���� ���� �Ѿ�� �������� ������ ����.
//�ϳ��� ����.