#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int dp(int len, char* pw)
{
	int d[5005] = { 0 };

	d[len] = 1;

	d[len - 1] = (pw[len - 1] - '0') ? 1 : 0;

	for (int i = len - 2; i >= 0; i--)
	{
		int temp = (pw[i] - '0') * 10 + (pw[i + 1] - '0');
		if (pw[i + 1] - '0')
			d[i] = d[i + 1];
		if (10 <= temp && temp <= 26)
			d[i] += d[i + 2];

		d[i] %= 1000000;
	}

	printf("dp.\n");
	for (int i = 0; i < strlen(pw); i++)
		printf("%d ", d[i]);
	printf("\n");

	return d[0];
}

int main()
{
	char pw[5001];
	gets(pw);

	if (pw[0] == '0')
		printf("0");
	else
		printf("%d", dp(strlen(pw), pw));
}