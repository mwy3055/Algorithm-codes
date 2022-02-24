#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int command(char*);

int main()
{
	int n, tp, index = 0;
	char cmd[10];
	scanf("%d", &n);
	getchar();
	int* stack = (int*)calloc(n, sizeof(int));
	while (n--) //명령 수행
	{
		tp = 0;
		gets(cmd);
		switch (command(cmd))
		{
		case 1:
			if (index == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[--index]);
				stack[index] = 0;
			}
			break;
		case 2:
			printf("%d\n", index);
			break;
		case 3:
			if (index)
				printf("0\n");
			else
				printf("1\n");
			break;
		case 4:
			if (index)
				printf("%d\n", stack[index - 1]);
			else
				printf("-1\n");
			break;
		default:
			for (int i = 5; i < strlen(cmd); i++)
				tp = tp * 10 + (cmd[i] - '0');
			stack[index++] = tp;
			break;
		}
	}
	free(stack);
}

int command(char* cmd)
{
	if (strcmp(cmd, "pop") == 0) return 1;
	else if (strcmp(cmd, "size") == 0) return 2;
	else if (strcmp(cmd, "empty") == 0) return 3;
	else if (strcmp(cmd, "top") == 0) return 4;
	else return 0;
}