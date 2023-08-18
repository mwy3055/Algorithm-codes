#include <stdio.h>
#include <string.h>

void vps(char*);
//int calc(char*,int,int);
int check(char,char);

int main()
{
	char input[51];
	gets(input);
	vps(input);
}

void vps(char* inp) //괄호 문자열인지 체크
{
	char stack[51] = { 0 }, buf;
	int i = 0, idx = 0, sum = 0, temp = 0;
	while (i < strlen(inp))
	{
		stack[idx] = inp[i++];
		if ((stack[idx - 1] == '(') && (stack[idx] == ')'))
		{
			stack[idx - 1] = stack[idx] = 0;
			idx -= 2;
		}
		else if ((stack[idx - 1] == '[') && (stack[idx] == ']'))
		{
			stack[idx - 1] = stack[idx] = 0;
			idx -= 2;
		}
		else
			buf = inp[idx];
		idx++;
	}
	if (idx != 0)
	{
		puts("0");
		return;
	}
	/*else
		printf("%d", calc(inp, 0, 1));*/
}

int calc(char* str, int fi, int li) //재귀.
{
	if (strlen(str) == 2)
		return check(str[0], str[1]);

	char buf;
	int temp = 0, chk = check(str[fi], str[li]);
	if (chk) //①
	{
		while (li < strlen(str))
		{
			printf("%d %d\n", fi, li);
			if (li >= strlen(str))
				return temp;
			if (fi == 0)
				temp += chk;
			else
			{
				buf = str[fi - 1];
				temp += chk;
				chk = check(str[fi - 1], str[li + 1]);
				if (chk)
				{
					temp *= chk;
					return temp;
				}
				else
				{
					fi += 2;
					li += 2;
				}
			}
		}
	}
	else
	{
		if (str[fi] == '(')
			return 2 * calc(str, fi + 1, li + 1);
		else
			return 3 * calc(str, fi + 1, li + 1);
	}

}

int check(char s1,char s2)
{
	if (s1 == '(' && s2 == ')')
		return 2;
	else if (s1 == '[' && s2 == ')')
		return 3;
	else
		return 0;
}

	/*
	*/