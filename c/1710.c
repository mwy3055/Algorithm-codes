#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getpi(int* pi, char* p, int m)
{
	int i, j = 0;
	for (i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

void kmp(char* t, char* p, int* pi, int n, int m)
{
	int count = 0, matchidx = 0, i, j = 0;
	int* match = (int*)calloc(n - m + 2, sizeof(int)); //매치된 번호. (인덱스+1)

	for (i = 0; i < n; i++)
	{
		while (j > 0 && t[i] != p[j])
			j = pi[j - 1];

		if (t[i] == p[j])
		{
			if (j == m - 1)
			{
				count++;
				match[++matchidx] = i - m + 2; //(i-(m-1))+1 = (인덱스)+1
				j = pi[j];
			}
			else j++;
		}
	}
	printf("%d\n", count);
	for (i = 1; i <= matchidx; i++)
		printf("%d\n", match[i]);
}

int main()
{
	char* text = (char*)calloc(1000001, sizeof(char));
	char* pattern = (char*)calloc(1000001, sizeof(char));
	gets(text);
	gets(pattern);
	int n = strlen(text), m = strlen(pattern);

	int* pi = (int*)calloc(m, sizeof(int));
	getpi(pi, pattern, m);

	kmp(text, pattern, pi, n, m);

	free(text);
	free(pattern);
	free(pi);
}