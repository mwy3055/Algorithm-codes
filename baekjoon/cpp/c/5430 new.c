#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int exe(char *f, int size, int *fr, int *bk) //������:1, ������:0 , ����:-1 ����
{
	int rev = 1; //��� 1 or 0
	for (int i = 0; f[i]; i++)
	{
		if (f[i] == 'D')
		{
			if (!size)
				return -1;
			//rev?(*fr)++:(*bk)--;
			if (rev)
				(*fr)++;
			else
				(*bk)--;
			size--;
		}
		else
			rev = 1 - rev; //rev^=1;
	}
	return rev;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		//�̰� �ε��� ���� �����̴�.
		//�߰� ���� �Լ� ����: D�� R�� ���� ����
		//�Ľ��� �� ���� ���� strtok:�Ʒ� ����
		char f[100001];
		int n;
		int i = 0;
		scanf("%s %d", f, &n);
		int fr = 0, bk = n - 1;
		int *num = (int *)calloc(n, sizeof(int)); //0~(n-1)������
		while (1)
		{
			char c;
			scanf("%c", &c);
			if (isdigit(c))
				num[i] = num[i] * 10 + (c - '0');
			else if (c == ',')
				i++;
			else if (c == ']')
				break;
		}
		int rev = exe(f, n, &fr, &bk);
		if (rev == 1) //������
		{
			printf("[");
			for (i = fr; i <= bk; i++)
			{
				printf("%d", num[i]);
				if (i < bk)
					printf(",");
			}
			puts("]");
		}
		else if (rev == 0) //������
		{
			printf("[");
			for (i = bk; i >= fr; i--)
			{
				printf("%d", num[i]);
				if (i > fr)
					printf(",");
			}
			puts("]");
		}
		else
			puts("error");
		free(num);
	}
}

//�Ľ��� �ٸ� ���.
/*
int nidx = 0;
char inp[400100], *pin, *delim = "[,]";
pin = strtok(inp, delim);
while (pin)
{
	num[nidx++] = (char)atoi(pin);
	pin = strtok(NULL, delim);
}
*/