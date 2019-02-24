#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PUSH(c) {stack[size++]=c;}

int isin(char* stk, char* exp)
{
	stk--;
	int len = strlen(exp);
	for (int i = len - 2; i >= 0; i--)
	{
		if (*(stk--) != exp[i])
			return 0;
	}
	return 1;
}

int main()
{
	char str[1000001], exp[37];
	scanf("%s %s", str, exp);
	int len1 = strlen(str), len2 = strlen(exp);

	char* stack = (char*)calloc(len1 + 1, sizeof(char));
	int size = 0;
	for (int i = 0; i < len1; i++)
	{
		PUSH(str[i]);
		//check if exp is on the top of the stack.
		//if it is, remove the top len2 char of the stack.
		//else, do nothing.
		if (len2 <= size && stack[size - 1] == exp[len2 - 1] && isin(stack + size - 1, exp))
		{
			size -= len2;
//			stack[size] = 0; //이거 왜 작동 안 하지? 
		}
	}

	if (size == 0)
		printf("FRULA");
	else
	{
		char* s = (char*)calloc(size + 1, sizeof(char));
		for (int i = 0; i < size; i++)
			s[i] = stack[i];
		puts(s);
		free(s);
	}


	free(stack);
}