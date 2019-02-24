/*
* Doesn't work
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define isAlpha(i) ('A' <= var[i] && var[i] <= 'Z')
#define isUnderbar2(i) (i < len - 1 && var[i] == '_'&&var[i + 1] == '_')
#define isUnderAlpha(i) (i<len-1&&var[i]=='_'&&isAlpha(i+1))

char conv[202];

__inline int error()
{
	printf("Error!");
	return 0;
}

void jtoc(char* var)
{
	int len = strlen(var), idx = 0;
	for (int i = 0; i < len; i++)
	{
		if (isAlpha(i))
		{
			conv[idx++] = '_';
			conv[idx++] = var[i] + ('a' - 'A');
		}
		else
			conv[idx++] = var[i];
	}
}

void ctoj(char* var)
{
	int len = strlen(var), idx = 0;
	for (int i = 0; i < len; i++)
	{
		if (var[i] == '_')
		{
			conv[idx++] = var[++i] - ('a' - 'A');
		}
		else
			conv[idx++] = var[i];
	}
}

int main()
{
	char var[101], option = 0; //0: 그냥 출력 1:java->c++ 2:c++->java
	scanf("%s", var);
	int len = strlen(var);
	if (isAlpha(0) || var[0] == '_' || var[len - 1] == '_')
		return error();

	for (int i = 0; i < len; i++)
	{
		if ('A' <= var[i] && var[i] <= 'Z')
			option = 1;
		else if (var[i] == '_')
			option = 2;

		if (option == 1 && var[i] == '_')
			return error();
		else if (option == 2 && (isAlpha(i) || isUnderbar2(i) || isUnderAlpha(i)))
			return error();

	}

	switch (option)
	{
	case 1:
		jtoc(var);
		printf("%s", conv);
		break;
	case 2:
		ctoj(var);
		printf("%s", conv);
		break;
	default:
		printf("%s", var);
		break;
	}
}