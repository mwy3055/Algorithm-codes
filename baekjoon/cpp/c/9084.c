#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getInput(int* n, int* m, int* coin)
{
	scanf("%d", n);
	for (int i = 0; i < *n; i++)
		scanf("%d", coin + i);
	scanf("%d", m);
}

int dp(int n, int m, int* coin)
{
	int* mem = (int*)calloc(m + 1, sizeof(int));

	for (int i = coin[0]; i <= m; i += coin[0])
		mem[i] = 1;
	for (int i = 1; i < n; i++)
	{
		int c = coin[i];
		mem[c]++;
		for (int j = c + 1; j <= m; j++)
			mem[j] += mem[j - c];
	}
	return mem[m];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, coin[20];
		getInput(&n, &m, coin);
		printf("%d\n", dp(n, m, coin));
	}
}
