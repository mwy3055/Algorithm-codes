#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void vps(char*);

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		char input[51];
		gets(input);
		vps(input);
	}
}

void vps(char* inp)
{
	char stack[51] = { 0 };
	int i = 0, num = 0;
	while (i < strlen(inp))
	{
		stack[num] = inp[i++];
		if ((stack[num - 1] == '(') && (stack[num] == ')')) //¦�� ������
		{
			stack[num - 1] = stack[num] = 0; //�����
			num -= 2; //�ڷ� ����
		}
		num++;
	}
	if (num == 0) puts("YES"); //������ ������� yes
	else puts("NO"); //�ƴϸ� no
}