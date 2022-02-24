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
		int prev = findmax(dp, i - 1);                        //prev: 상담하기 전 날까지의 최대 이익
		for (j = i; j <= n;)
		{
			int endday = j + cons[j].day - 1;                 //상담이 끝나는 날
			if (endday > n)
				break;
			dp[endday] = max(dp[endday], prev + cons[j].val); //기존값과 새 값 비교
			prev = dp[endday];                                //for문 안에서의 이익 최댓값 갱신
			Max = max(Max, prev);                             //dp 최댓값 갱신
			j += cons[j].day;                                 //다음 상담하러 가자.
		}
	}

	printf("%d", Max);
}

//day=1일 때 다음 날로 넘어가는 과정에서 문제가 생김.
//하나씩 돌자.