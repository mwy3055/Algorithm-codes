#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int lis(int n, int* ar)
{
	int len = 1, i, d[200] = { 0 };
	d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int j = 0;
		while (d[j] < ar[i] && d[j] != 0) j++;
		if (j == len)
			d[len++] = ar[i];
		else
			d[j] = ar[i];
	}
	return len;
}

int main()
{
	int n, i, ar[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);

	printf("%d", n - lis(n, ar));
}