#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void Lis(int n, short* ar)
{
	int len = 1, i, d[1001] = { 0 }, lis[1001] = { 0 };
	lis[0] = d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int j = 0;
		while (d[j] < ar[i] && d[j]) j++;
		if (j == len)
		{
			lis[len] = ar[i];
			d[len++] = ar[i];
		}
		else
			d[j] = ar[i];
	}
	printf("%d\n", len);
	for (i = 0; i < len; i++)
		printf("%d ", lis[i]);
}
int main()
{
	int n, i;
	short ar[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%hd", ar + i);
	Lis(n, ar);
}
//갱신 관련 issue