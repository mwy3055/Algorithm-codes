#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

__inline int minv(int a, int b)
{
	return a < b ? a : b;
}

void manacher(int fidx, int* num, int* P)
{
	int r = 0, p = 0;
	for (int i = 0; i <= fidx; i++)
	{
		if (i <= r) P[i] = minv(r - i, P[2 * p - i]);
		else P[i] = 0;
		while (0 <= i - P[i] - 1 && i + P[i] + 1 <= fidx && num[i - P[i] - 1] == num[i + P[i] + 1])
			P[i]++;
		if (r < i + P[i])
			r = i + P[i], p = i;
	}

	printf("palindrome\n");
	for (int i = 0; i <= fidx; i++)
		printf("%d ", P[i]);
	printf("\n");
}

int main()
{
	int n, m, num[4005], P[4005] = { 0 };
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", num + i * 2);
		num[i * 2 + 1] = -1;
	}

	//팰린드롬 검사
	manacher((n - 1) * 2, num, P);

	scanf("%d", &m);
	while (m--)
	{
		int s, e, rst = 0;
		scanf("%d %d", &s, &e);
		int len = 2 * (s - e + 1) - 1;
		s--, e--;
		if (s == e || P[s + e] >= len / 2) rst = 1;
		printf("%d\n", rst);
	}
}