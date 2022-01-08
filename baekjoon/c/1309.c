#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int dp[100000][2];

int f(int i, int j)
{
	if (dp[i][j])
		return dp[i][j];
	else if (j > 0)
		return dp[i][j] = (f(i + 1, 0) + f(i + 1, 1)) % 9901;
	else
		return dp[i][j] = (f(i + 1, 0) + 2 * f(i + 1, 1)) % 9901;
}

int main()
{
	int n, sum = 0, i;
	scanf("%d", &n);
	for (i = 0; i < 2; i++)
		dp[n - 1][i] = 1;
	for (i = 0; i < 2; i++)
	{
		f(0, i);
	}
/*	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%2d ", dp[i][j]);
		printf("\n");
	}
*/
	printf("%d", (dp[0][0]+2*dp[0][1])%9901);
} //ÈçÇÑ DP.

//Á» ´õ ¾å»ðÇÑ ÄÚµå´Â BOJ¿¡ ÀÖ´Ù.