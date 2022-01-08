#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char conv[210];

__inline int isUnderbar(char c)
{
	return c == '_' ? 1 : 0;
}
__inline int isUpper(char c)
{
	return 'A' <= c && c <= 'Z' ? 1 : 0;
}
__inline int isLower(char c)
{
	return 'a' <= c && c <= 'z' ? 1 : 0;
}
__inline char toLower(char c)
{
	return c + ('a' - 'A');
}
__inline char toUpper(char c)
{
	return c - ('a' - 'A');
}

int isJava(char*);
int isC(char*);
void toJava(char*);
void toC(char*);

int main()
{
	char src[101];
	scanf("%s", src);
	if (isJava(src)) //두 분류 모두에 속하면 이걸로
		toC(src);
	else if (isC(src))
		toJava(src);
	else
	{
		puts("Error!");
		return 0;
	}

	puts(conv);
}

int isJava(char* s)
{
	if (!isLower(s[0]))
		return 0;

	for (int i = 0; s[i]; i++)
	{
		if (!isUpper(s[i]) && !isLower(s[i]))
			return 0;
	}
	return 1;
}
void toC(char* s)
{
	int j = 0;
	for (int i = 0; s[i]; i++)
	{
		if (isLower(s[i]))
			conv[j++] = s[i];
		else
		{
			conv[j++] = '_';
			conv[j++] = toLower(s[i]);
		}
	}
}

int isC(char* s)
{
	if (!isLower(s[0]))
		return 0;

	for (int i = 0; s[i]; i++)
	{
		if (!isLower(s[i]) && !isUnderbar(s[i]))
			return 0;
		if (isUnderbar(s[i]) && !isLower(s[i + 1]))
			return 0;
	}
	return 1;
}
void toJava(char* s)
{
	int j = 0;
	for (int i = 0; s[i]; i++)
	{
		if (isLower(s[i]))
			conv[j++] = s[i];
		else
			conv[j++] = toUpper(s[++i]);
	}
}