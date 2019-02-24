#include <stdio.h>

void cut(int, int*);

int main()
{
	int n, m;
	int cn = 0, cm = 0;
	scanf_s("%d %d", &n, &m);
	cut(n, &cn);
	cut(m, &cm);
	printf("%d", cn + n * cm);
}

void cut(int l, int* cnt)
{
	if (l == 1)
		return;
	(*cnt)++;
	cut(l / 2, cnt);
	cut(l - l / 2, cnt);
}