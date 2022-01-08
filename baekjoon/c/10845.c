//큐: FIFO
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int order(char*);
void exe(int, int*, char*, int*, int*);
int isempty(int*, int*, int*);

int main()
{
	int front = 0, back = 0, queue[10050] = { 0 };
	int n, i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		char input[20];
		gets(input);
		exe(order(input), queue, input, &front, &back);
	}
}

int order(char* inp)
{
	if (strcmp(inp, "pop") == 0)
		return 1;
	else if (strcmp(inp, "size") == 0)
		return 2;
	else if (strcmp(inp, "empty") == 0)
		return 3;
	else if (strcmp(inp, "front") == 0)
		return 4;
	else if (strcmp(inp, "back") == 0)
		return 5;
	else
		return 0;
}
void exe(int cmd, int* q, char* inp, int* fr, int* bk)
{
	enum { push, pop, size, empty, front, back };
	if (cmd == pop)
	{
		if (isempty(q,fr,bk))
			puts("-1");
		else
		{
			printf("%d\n", q[(*fr)]);
			q[*fr] = 0;
			if (*fr != *bk)
				(*fr)++;
		}
	}
	else if (cmd == size)
	{
		if (q[*fr] == 0 && q[*bk] == 0)
			puts("0");
		else
			printf("%d\n", *bk - *fr + 1);
	}
	else if (cmd == empty)
	{
		if (isempty(q,fr,bk))
			puts("1");
		else
			puts("0");
	}
	else if (cmd == front)
	{
		if (isempty(q,fr,bk))
			puts("-1");
		else
			printf("%d\n", q[*fr]);
	}
	else if (cmd == back)
	{
		if (isempty(q,fr,bk))
			puts("-1");
		else
			printf("%d\n", q[*bk]);
	}
	else //push
	{
		int temp = 0, i = 5;
		for (; i < strlen(inp); i++)
		{
			if (isdigit(inp[i]))
				temp = temp * 10 + (inp[i] - '0');
		}
		if (q[*bk])
			q[++(*bk)] = temp;
		else
			q[*bk] = temp;
	}
}
int isempty(int* q, int* f, int* b)
{
	if (q[*f] == 0 && q[*b] == 0)
		return 1;
	else return 0;
}