#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rtn {
	char tp;
	int x;
} info;

void rtn(info*, char*);
void exe(info*, int*, int*);

int main()
{
	int n, idx = 0;
	scanf("%d", &n);
	getchar();
	int* deque = (int*)calloc(n, sizeof(int));
	while (n--)
	{
		info cmd;
		char order[20] = { 0 };
		gets(order);
		rtn(&cmd, order);
		exe(&cmd,deque,&idx);
	}

	free(deque);
}

void rtn(info* cmd, char* odr)
{
	int i, tmp = 0;
	char temp[11] = { 0 };
	memcpy(temp, odr, 6 * sizeof(char));
	if (strcmp(temp, "push_f") == 0)
	{
		for (i = 11; i < strlen(odr); i++)
			tmp = tmp * 10 + (odr[i] - '0');
		cmd->tp = 0;
		cmd->x = tmp;
	}
	else if (strcmp(temp, "push_b") == 0)
	{
		for (i = 10; i < strlen(odr); i++)
			tmp = tmp * 10 + (odr[i] - '0');
		cmd->tp = 1;
		cmd->x = tmp;
	}
	else if (strcmp(temp, "pop_fr") == 0)
		cmd->tp = 2;
	else if (strcmp(temp, "pop_ba") == 0)
		cmd->tp = 3;
	else if (strcmp(temp, "size") == 0)
		cmd->tp = 4;
	else if (strcmp(temp, "empty") == 0)
		cmd->tp = 5;
	else if (strcmp(temp, "front") == 0)
		cmd->tp = 6;
	else //back
		cmd->tp = 7;
}

void exe(info* cmd, int* deq, int* idx)
{
	if (cmd->tp == 0)
	{
		if (deq[*idx])
		{
			memmove(deq + 1, deq, ((*idx)++ + 1) * sizeof(int));
			deq[0] = cmd->x;
		}
		else
			deq[0] = cmd->x;
	}
	else if (cmd->tp == 1)
	{
		if (deq[*idx])
			deq[++(*idx)] = cmd->x;
		else
			deq[*idx] = cmd->x;
	}
	else if (cmd->tp == 2)
	{
		if (*idx)
		{
			printf("%d\n", deq[0]);
			memmove(deq, deq + 1, (*idx) * sizeof(int));
			deq[(*idx)--] = 0;
		}
		else //idx=0
		{
			if (deq[0])
			{
				printf("%d\n", deq[0]);
				deq[0] = 0;
			}
			else //덱이 비어있음
				puts("-1");
		}
	}
	else if (cmd->tp == 3)
	{
		if (*idx)
		{
			printf("%d\n", deq[*idx]);
			deq[(*idx)--] = 0;
		}
		else //idx=0
		{
			if (deq[0])
			{
				printf("%d\n", deq[0]);
				deq[0] = 0;
			}
			else //덱이 비어있음
				puts("-1");
		}
	}
	else if (cmd->tp == 4)
	{
		if (deq[*idx])
			printf("%d\n", *idx + 1);
		else
			puts("0");
	}
	else if (cmd->tp == 5)
	{
		if (deq[*idx])
			puts("0");
		else
			puts("1");
	}
	else if (cmd->tp == 6)
	{
		if (deq[0])
			printf("%d\n", deq[0]);
		else
			puts("-1");
	}
	else
	{
		if (deq[*idx])
			printf("%d\n", deq[*idx]);
		else
			puts("-1");
	}
//	printf("명령: %d, idx=%d\n", cmd->tp, *idx);
}