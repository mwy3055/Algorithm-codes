#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char** pr; //최대 3172*6344 크기
int n;

void makestar(int height, int y, int x)
{
	if (3 == height && pr[y][x] != '*')
	{
		pr[y][x] = '*';
		pr[y + 1][x - 1] = pr[y + 1][x + 1] = '*';
		for (int i = -2; i <= 2; i++)
			pr[y + 2][x + i] = '*';
		return;
	}
	makestar(height / 2, y, x);
	makestar(height / 2, y + (height / 2), x - (height / 2));
	makestar(height / 2, y + (height / 2), x + (height / 2));
}

int main()
{
	int i, j;
	scanf("%d", &n);
	pr = (char**)calloc(n, sizeof(char*));
	for (i = 0; i < n; i++)
	{
		*(pr + i) = calloc(n * 2 + 1, sizeof(char));
		for (j = 0; j < n * 2; j++)
			pr[i][j] = ' ';
	}

	makestar(n, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		puts(pr[i]);
		free(*(pr + i));
	}
}