#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int zro[41] = { 0 }, one[41] = { 0 };
int fzro(int);
int fone(int);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d %d\n", fzro(n), fone(n));
	}
}

int fzro(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 0;
	else if (zro[n] != 0)
			return zro[n];
	return zro[n] = fzro(n - 1) + fzro(n - 2);
}

int fone(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (one[n] != 0)
		return one[n];
	return one[n] = fone(n - 1) + fone(n - 2);
}