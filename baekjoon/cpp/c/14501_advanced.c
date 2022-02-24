/*
   �ִ� ������ ��� ��� ���ձ��� �˷��ش�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct consult {
	int day, val;
} consult;

int dp[16][16];  //15���� �ִ�����, 0~14���� �� ���� ��� ��¥ ����

__inline int max(int a, int b)
{
	return a < b ? b : a;
}

int findidx(int k, int* pr)
{
	int idx = 0;
	for (int i = 1; i <= k; i++)
	{
		if (*pr < dp[i][15])
		{
			*pr = dp[i][15];
			idx = i;
		}
	}
	return idx;
}

int main()
{
	int n, Max = 0, Maxidx; 
	consult cons[16];
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &cons[i].day, &cons[i].val);

	for (i = 1; i <= n; i++)
	{
		int prev = 0;
		int previdx = findidx(i - 1, &prev);
		for (j = i; j <= n;)
		{
			int endday = j + cons[j].day - 1;
			if (endday > n)
				break;
			if (dp[endday][15] < prev + cons[j].val)
			{
				dp[endday][15] = prev + cons[j].val;

				memcpy(dp[endday], dp[previdx], 15 * sizeof(int));
				int k = 1;
				while (dp[endday][k]) k++;
				dp[endday][k] = j;
			}

			prev = dp[endday][15], previdx = endday;
			if (Max < prev)
			{
				Max = prev, Maxidx = previdx;
			}
			j += cons[j].day;
		}
	}

	printf("�ִ� ����: %d\n", Max);
	for (i = 1; dp[Maxidx][i]; i++)
	{
		int todo = dp[Maxidx][i];
		if (cons[todo].day == 1)
			printf("%d��, ���� %d\n", todo, cons[todo].val);
		else
			printf("%d��~%d��, ���� %d\n", todo, todo + cons[todo].day - 1, cons[todo].val);
	}
}