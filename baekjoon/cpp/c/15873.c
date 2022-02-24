#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char str[8] = { 0 };
	int num[2] = { 0 }, idx = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		int temp = str[i] - '0';
		if (temp == 0)
		{
			num[idx++] *= 10;
		}
		else if (temp == 1)
		{
			num[idx] = temp;
			if (str[i + 1] != '0')
				idx++;
		}
		else
		{
			num[idx] = temp;
			idx++;
		}
	}
	printf("%d", num[0] + num[1]);
}