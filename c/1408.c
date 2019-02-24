#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calc(int*,int*);

int main()
{
	int curr[3], start[3]; //0:h 1:m 2:s
	scanf("%d:%d:%d", curr, curr+1, curr+2);
	scanf("%d:%d:%d", start, start+1, start+2);
	calc(curr, start);
}

void calc(int* c, int* s)
{
	int rst[3];
	for (int i = 2; i >= 0; i--)
	{
		rst[i] = s[i] - c[i];
		if (rst[i] < 0)
		{
			if (i > 0) //초, 분
			{
				rst[i] += 60;
				s[i - 1]--;
			}
			else //시
				rst[i] += 24;
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		printf("%02d", rst[i]); //형식 맞춰서 출력
		if (i < 2)
			printf(":");
	}
}