#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}

char S[1001], T[1001], LCS[1001];

int main()
{
	int i, j;
	gets(S), gets(T);
	int v = strlen(T), h = strlen(S);
	short dp[1001][1001] = { 0 };

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

	printf("%d\n", dp[v][h]);  //LCS ±æÀÌ

	int index = dp[v][h] - 1;
	for (i = v, j = h; i > 0 && j > 0;)
	{
		if (T[i - 1] == S[j - 1])
		{
			LCS[index--] = S[j - 1];
			i--, j--;
		}
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
	}
	printf("%s", LCS);
}