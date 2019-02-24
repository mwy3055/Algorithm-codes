#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int garbage = 1;
		int a, b, init, cnt = 1, fin, temp;
		scanf("%d %d", &a, &b);
		init = a % 10;
		fin = a * a % 10;
		while (init != fin)
		{
			fin = fin * a % 10;
			cnt++; //주기
		}
		temp = (b - 1) % cnt + 1; //주기 중 몇번째?
		printf("%d\n", ((int)pow(a, temp) - 1) % 10 + 1);
	}
}