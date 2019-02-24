#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}

int upper_bound(int len, int m, int* d)
{
	int l = 0, r = len - 1;
	if (d[len - 1] < m)
		return len;
	if (d[l] >= m)
		return l;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (d[mid] >= m) r = mid;
		else l = mid;
	}
	return r;
}

int lower_bound(int len, int m, int* d)
{
	int l = 0, r = len - 1;
	if (d[len - 1] > m) 
		return len;
	if (d[l] <= m)
		return l;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (d[mid] <= m) r = mid;
		else l = mid;
	}
	return r;
}

int LIS(int* ar, int n, int i)  //0~i
{
	int len = 1, j, d[1000];
	d[0] = ar[0];
	for (j = 1; j <= i; j++)
	{
		int temp = upper_bound(len, ar[j], d);
		if (len == temp)
			d[len++] = ar[j];
		else
			d[temp] = ar[j];
	}
	return len;
}

int LDS(int* ar, int n, int i) //i~(n-1)
{
	if (i == n) return 0;

	int len = 1, j, d[1000];
	d[0] = ar[i];
	for (j = i + 1; j < n; j++)
	{
		int temp = lower_bound(len, ar[j], d);
		if (len == temp)
			d[len++] = ar[j];
		else
			d[temp] = ar[j];
	}
	return len;
}

int main()
{
	int n, i, ar[1000], max = -1;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);

	for (i = 0; i < n; i++)
	{
		int tlis = LIS(ar, n, i), tlds = LDS(ar, n, i);
		printf("%d %d ", tlis, tlds);
		max = maxv(max, tlis + tlds - 1);
		printf("maxv = %d\n", max);
	}

	printf("%d", max);
}
