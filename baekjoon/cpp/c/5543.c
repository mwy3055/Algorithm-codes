#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int h[3], b[2], hmin = 2000, bmin = 2000, i;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", h + i);
		if (hmin > h[i])
			hmin = h[i];
	}
	for (i = 0; i < 2; i++)
	{
		scanf("%d", b + i);
		if (bmin > b[i])
			bmin = b[i];
	}
	printf("%d", hmin + bmin - 50);
}