#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef short forDP; //문자열 길이 길어지면 바꿀것
__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}

char S[1001], T[1001];

int main()
{
	int i, j;
	scanf("%s %s", S, T);
	int v = strlen(T), h = strlen(S);
	forDP** dp = (forDP**)calloc(v + 1, sizeof(forDP*));
	for (i = 0; i <= v; i++)
		*(dp + i) = (forDP*)calloc(h + 1, sizeof(forDP));

	for (i = 1; i <= v; i++)
	{
		for (j = 1; j <= h; j++)
		{
			if (S[j - 1] == T[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = maxv(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[v][h]);  //LCS 길이

	for (i = 0; i <= v; i++)
		free(*(dp + i));
}