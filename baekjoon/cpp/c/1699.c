#define _CRT_SECURE_NO_WARNINGS
//65435 -> 3
#include <stdio.h>
#include <math.h>
#define min(a,b) (((a)<(b))?(a):(b))

int main()
{
	int n, dp[100001] = { 0 }; //인덱스=숫자
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int rt = (int)sqrt(i);
		if (i <= 3)
			dp[i] = i;
		else if (rt*rt == i)
			dp[i] = 1;
		else
		{
			int temp = 1 << 30;
			for (int j = 1; j <= rt; j++)
				temp = min(temp, dp[i - j * j] + 1);
			dp[i] = temp;
		}
	}
	printf("%d", dp[n]);
} //24ms

//함수 재귀버전도 있음. 204ms