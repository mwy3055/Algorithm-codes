#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

__inline int sq(int i)
{
	return i * i;
}
int LP()
{
	int n, count = 0;
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d", &n);
	while (n--)
	{
		int x, y, r;
		scanf("%d %d %d", &x, &y,&r);
		if ((sq(x - x1) + sq(y - y1) < sq(r)) ^ (sq(x - x2) + sq(y - y2) < sq(r)))
			count++;
	}
	return count;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		printf("%d\n", LP());
	}
}