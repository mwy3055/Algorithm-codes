#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int lds(int n, short* ar)
{
	int len = 1, i, d[1000] = { 0 };
	d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int j = 0;
		while (d[j]>ar[i] && d[j]) j++;
		if (j == len)
			d[len++] = ar[i];
		else
			d[j] = ar[i];
	}
	return len;
}
int main()
{
	int n, i;
	short ar[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%hd", ar + i);
	printf("%d", lds(n, ar));
}