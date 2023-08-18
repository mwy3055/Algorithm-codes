#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check(char*);

int main()
{
	char str[102];
	while (fgets(str, sizeof(str), stdin) != NULL)
		check(str);
}

void check(char* s)
{
	int low = 0, upp = 0, dig = 0, spc = 0;
	for (int i = 0; i < (int)strlen(s); i++)
	{
		if (*(s + i) == '\n')
			break;
		else if (islower(*(s + i)))
			low++;
		else if (isupper(*(s + i)))
			upp++;
		else if (isdigit(*(s + i)))
			dig++;
		else
			spc++;
	}
	printf("%d %d %d %d\n", low, upp, dig, spc);
}