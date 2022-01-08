#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#define min(a,b) (a<b?a:b)

int toone[1000000];

int main() //DP with 메모이제이션, 4ms
{
	int n;
	scanf("%d", &n);
	toone[1] = 0;
	toone[2] = toone[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (i % 3 == 0)
			toone[i] = min(toone[i / 3], toone[i - 1]) + 1; //3으로 나눌 수 있다면 나누는 게 최선
		else if (i % 2 == 0)
			toone[i] = min(toone[i / 2], toone[i - 1]) + 1;
		else
			toone[i] = toone[i - 1] + 1;
/*		for (int j = 1; j <= n; j++)
		{
			printf("%d[%d] ", j,toone[j]);
		}
		printf("\n");*/
	}
	printf("%d", toone[n]);
}

/*
재귀호출, 0ms

int f(int p) {
	int x, y;
	if (p <= 1) return 0;
	x = f(p / 2) + 1 + p % 2;
	y = f(p / 3) + 1 + p % 3;
	return min(x, y);
}
printf("%d",f(n));
*/