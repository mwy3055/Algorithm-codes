#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[101] = { 0 };
	scanf("%s", str);
	int len = strlen(str), ans = 1, i;
	if (len % 2)
		i = len / 2;
	else
		i = len / 2 - 1;

	for (; i >= 0; i--)
		if (str[i] != str[len - 1 - i])
		{
			ans = 0;
			break;
		}
	printf("%d", ans);
}