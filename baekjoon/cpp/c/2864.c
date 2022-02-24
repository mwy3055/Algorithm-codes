#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int to_min(char* a)
{
	int len = strlen(a), rst = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == '6')
			rst = rst * 10 + 5;
		else
			rst = rst * 10 + (a[i] - '0');
	}
	return rst;
}

int to_max(char* a)
{
	int len = strlen(a), rst = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == '5')
			rst = rst * 10 + 6;
		else
			rst = rst * 10 + (a[i] - '0');
	}
	return rst;
}

int main()
{
	char a[8], b[8];
	scanf("%s %s", a, b);
	printf("%d %d", to_min(a) + to_min(b), to_max(a) + to_max(b));
}