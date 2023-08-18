#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	short d[1000001];
	int n;
	scanf("%d", &n);
	d[1] = 1, d[2] = 2;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	printf("%d", d[n]);
}