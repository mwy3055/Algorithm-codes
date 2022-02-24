#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	int dp[41] = { 1,1 }, i;
	char str[41];
	gets(str);
	int len = strlen(str);
	if (len == 1)
	{
		printf("1");
		return 0;
	}

	for (i = 0; i < len; i++)
		str[i] -= '0';

	for (i = 0; i < len - 1; i++)
	{
		if (!str[i + 1])
		{
			if (!str[i] || str[i] >= 4)
			{
				printf("0");
				return 0;
			}
			else
				dp[i + 2] = dp[i];
		}
		else if (!str[i] && str[i + 1])
		{
			dp[i + 2] = dp[i + 1];			
		}
		else
		{
			int temp = str[i] * 10 + str[i + 1];
			if (11 <= temp && temp <= 34)
				dp[i + 2] = dp[i + 1] + dp[i];
			else
				dp[i + 2] = dp[i + 1];

		}
	}
	printf("%d", dp[len]);
}