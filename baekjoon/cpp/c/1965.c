#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int psearch(int len, int m, int* d)
{
	int l = 0, r = len - 1;
	while (1)
	{
		int mid = (l + r) / 2;
		if (r - l <= 1)
		{
			if (d[l] >= m)
				return l;
			else if (d[r] >= m)
				return r;
			else
				return r + 1;
		}

		if (d[mid] < m)
			l = mid + 1;
		else
			r = mid;
	}
}

int lis(int n, int* ar)
{
	int len = 1, i, d[1000];
	d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int temp = psearch(len, ar[i], d);
		if (len == temp)
		{
			d[len++] = ar[i];
		}
		else
			d[temp] = ar[i];
	}
	return len;
}

int main()
{
	int n, ar[1000], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);
	printf("%d", lis(n, ar));
}